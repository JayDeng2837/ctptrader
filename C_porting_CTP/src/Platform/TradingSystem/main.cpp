//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     main.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////
// self header

// c header
#include "stdio.h"

#ifdef WIN32
#include "conio.h"
#endif

// c++ header

// third library header
#include <boost/thread.hpp>
#include <boost/pool/pool.hpp>
#include <boost/unordered_map.hpp>
#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/ini_parser.hpp>  
#include <boost/format.hpp>  
#include <boost/tokenizer.hpp>  
#include <boost/algorithm/string.hpp>  

// inner header

#include "lctslog.h"

#include "global_variables.h"

#include "queue_helper.h"

#include "queryworker.h"
#include "marketdataworker.h"

#ifdef LOCK_FREE_OMS
#include "omsworker.h"
#endif

#include "MDWrapper.h"
#include "TraderWrapper.h"

#include "DateTime.h"

#include "cpu_affinity_helper.h"

#include "LcTraderProxy.h"

#include "dll_manager.h"

#include "hft_strategy.h"

#include "log_info.pb.h"
#include "log_service.h"

#include "md_service.h"

/*
#if defined _DEBUG and defined WIN32
#include "vld.h"
#endif
*/

using namespace std;

LogService logService;

DataMgr dc;

OrderMgr OMS;

PositionMgr positionMgr;

MemoryMgr memoryMgr;

DLLManager dllMgr;

boost::condition	m_condTaskQueue;

boost::mutex		m_exeMutex;

boost::mutex		oms_Mutex;

char * d_arr[] = 
{
	"Buy",
	"Sell",
	"SellShort",
	"BuyToCover"
};

char * ot_arr[] =
{
	"Market",
	"Limit",
	"IOC",
	"Cancel"
};

void initHPQ()
{
	fifo_init_hpq(MARKET_DATA_FIFO_ID);

#ifdef LOCK_FREE_OMS
	fifo_init_hpq(ORDER_FIFO_ID);
#endif

	fifo_init_hpq(QUERY_FIFO_ID);
}

#define TEST

struct Config
{
	Config() : cfg_flag(false)
	{
	}

	bool   cfg_flag;

	string username;
	string password;
	string m_brokerId;
	string md_addr;

	string t_brokerId;
	string trader_addr;

	string log_server_addr;

	string md_server_addr;

	vector<string> concern_instruments;
};

bool readConfig(const char * path, Config & cfg)
{
	try
	{
		boost::property_tree::ptree pt;  
		boost::property_tree::ini_parser::read_ini(path, pt);

		cfg.username = pt.get<std::string>("CFG.username");
		cfg.password = pt.get<std::string>("CFG.password");
		cfg.md_addr = pt.get<std::string>("CFG.md_addr");
		cfg.m_brokerId = pt.get<std::string>("CFG.m_brokerId");
		cfg.trader_addr = pt.get<std::string>("CFG.trader_addr");  
		cfg.t_brokerId = pt.get<std::string>("CFG.t_brokerId"); 
		cfg.log_server_addr = pt.get<std::string>("CFG.log_server_addr");
		cfg.md_server_addr = pt.get<std::string>("CFG.md_server_addr");

		const string instruments = pt.get<string>("CFG.concerns");
		
		boost::char_separator<char> sep(" ,");
		typedef boost::tokenizer<boost::char_separator<char> > CustomedTokenizer;  
		CustomedTokenizer tok(instruments, sep); 

		// 输出分割结果  
		for(CustomedTokenizer::iterator beg=tok.begin(); beg!=tok.end();++beg)  
		{  
			cfg.concern_instruments.push_back(*beg);  
		}
		return true;
	}
	catch (...)
	{		
	}
	return false;
}

LC_BOOL lc_log_callback(int pri, const char * str)
{
	LogInfo li;
	li.set_log_str(str);
	li.set_pri(pri);

	char temp[5];

	MY_SPRINTF(temp, "%d", pri);

	logService.SendMsg(temp, ZMQ_SM);
	logService.SendMsg(li.SerializeAsString(), ZMQ_NB);
	return TRUE;
}

int main(int argc, char** argv)
{

	set_log_priority_name("LOG_INFO");

	Config cfg;

	if (argc <= 1 || !readConfig(argv[1], cfg))
	{
#ifdef TEST
		//中信仿真 why
		cfg.username = "894962";
		cfg.password = "181221";
		cfg.md_addr = "tcp://ctpfz1-front1.citicsf.com:51213";
		cfg.m_brokerId = "66666";
		cfg.trader_addr = "tcp://ctpfz1-front1.citicsf.com:51205";
		cfg.t_brokerId = "66666";
		cfg.log_server_addr = "tcp://*:8888";
		cfg.md_server_addr = "tcp://*:16888";
		cfg.concern_instruments.push_back("IF1508");
#else
		//申万 cyf
		cfg.username = "8002041107";
		cfg.password = "083817";
		cfg.md_addr = "tcp://180.168.212.51:41213";
		cfg.m_brokerId = "88888";
		cfg.trader_addr = "tcp://180.168.212.51:41205";
		cfg.t_brokerId = "88888";
		cfg.log_server_addr = "tcp://*:8888";
		cfg.md_server_addr = "tcp://*:16888";
		cfg.concern_instruments.push_back("rb1510");
#endif
	}
	logService.InitService(cfg.log_server_addr.c_str());

#ifdef HAS_LOG_CALLBACK_F
	LOG_CALLBACK_F pf;
	pf = &lc_log_callback;
	set_log_callback(pf);
#endif

	initHPQ();

	unsigned long cpu = GetCoreNum();

	boost::thread_group group;

	string strategy_name = "TestOrderRtnTime";

	dllMgr.LoadStrategyDLLByName(strategy_name, "./" + strategy_name);

	IStrategy * strategy = dllMgr.CreateStrategyInstance(strategy_name);
	strategy->RegLogService(&logService);

	if (!strategy)
	{
		return -1;
	}

	MarketDataService * pPricingSource = new MarketDataService();
	pPricingSource->InitService(cfg.md_server_addr.c_str());

	//Define Wrappers

	MDWrapper md(cfg.username, cfg.password, cfg.md_addr, cfg.m_brokerId);
	
	TraderWrapper trader(cfg.username, cfg.password, cfg.trader_addr, cfg.t_brokerId, cfg.concern_instruments);

	//Define Workers
	QueryWorker queryworker(&md, &trader, strategy);

	MarketDataWorker mdworker(strategy);

	mdworker.InitPricingSource(pPricingSource);

	boost::thread * query_worker_thread = group.create_thread(boost::bind(&QueryWorker::ProcessQueryQueue, &queryworker));

	boost::thread * md_worker_thread = group.create_thread(boost::bind(&MarketDataWorker::ProcessMarketDataQueue, &mdworker));

	boost::thread::native_handle_type md_native_handle = md_worker_thread->native_handle();

	LcSetThreadAffinityMask(MD_PROCESSOR_CORE, md_native_handle);

#ifndef NO_TRADER
	LcTraderProxy proxy(&trader);

	((HFTStrategyBase *)strategy)->RegTraderProxy(&proxy);
#endif

#ifdef LOCK_FREE_OMS

#ifndef NO_TRADER

	OMSWorker omsworker(&trader);

	boost::thread * oms_worker_thread = group.create_thread(boost::bind(&OMSWorker::ProcessOrderQueue, &omsworker));

	boost::thread::native_handle_type oms_native_handle = oms_worker_thread->native_handle();

	LcSetThreadAffinityMask(OMS_CORE, oms_native_handle);

#endif

#endif

	trader.Init();

	bool isRun = true;

	RecordMgr recordMgr;

	recordMgr.addRecord("positions.csv", &positionMgr);

	recordMgr.addRecord("orders.csv", &OMS);

	while (isRun)
	{
		switch(MY_GETCH())
		{
		case 'q':
		case 'Q':

#ifdef LOCK_FREE_OMS
#ifndef NO_TRADER
			omsworker.stop();
#endif
#endif

			queryworker.stop();
			mdworker.stop();
			group.join_all();

			recordMgr.writeRecord();

			DEL_PTR(strategy);

			DEL_PTR(pPricingSource);

			isRun = false;
			break;
		default:
			break;
		}
	}
	return 0;
}