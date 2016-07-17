//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     pInvestorPosition->cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/20
//////////////////////////////////////////////////////////////////////////
// self header
#include "position_mgr.h"

// c header

// c++ header
#include <fstream>

// third library header
#include <boost/pool/pool.hpp>

// inner header
#include "Base.h"
#include "lcts_defs.h"

#include "lctslog.h"

using namespace std;

Position::Position()
{
	ResetPosition();
}

void Position::ResetPosition()
{

	iYesterday = 0;

	iYesterdayLong = 0;

	iYesterdayShort = 0;

	iToday = 0;

	iTodayLong = 0;

	iTodayShort = 0;

	iTotalPos = 0;

	iTotalLong = 0;

	iTotalShort = 0;
}

void Position::UpdatePosition(CThostFtdcInvestorPositionField * pInvestorPosition, bool bIsLast)
{
	if (pInvestorPosition == nullptr)
	{
		return;
	}
	
	memcpy(instumentid, pInvestorPosition->InstrumentID, sizeof(TThostFtdcInstrumentIDType));

	if (pInvestorPosition->HedgeFlag == THOST_FTDC_HF_Speculation)
	{
		/*
		if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Long && pInvestorPosition->PositionDate == THOST_FTDC_PSD_History)
		{
			iYesterday += pInvestorPosition->Position;

			iTodayLong += pInvestorPosition->TodayPosition;
			iYesterdayLong += (pInvestorPosition->YdPosition > pInvestorPosition->CloseVolume ? pInvestorPosition->YdPosition - pInvestorPosition->CloseVolume : 0);
		}
		else if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Short && pInvestorPosition->PositionDate == THOST_FTDC_PSD_History)
		{
			iYesterday -= pInvestorPosition->Position;

			iTodayShort -= pInvestorPosition->TodayPosition;
			iYesterdayShort -= (pInvestorPosition->YdPosition > pInvestorPosition->CloseVolume ? pInvestorPosition->YdPosition - pInvestorPosition->CloseVolume : 0);;
		}
		else */
		if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Long && pInvestorPosition->PositionDate == THOST_FTDC_PSD_Today)
		{
			//iToday += pInvestorPosition->Position;

			iYesterdayLong += (pInvestorPosition->YdPosition > pInvestorPosition->CloseVolume ? pInvestorPosition->YdPosition - pInvestorPosition->CloseVolume : 0);
			iTodayLong += pInvestorPosition->TodayPosition;

			//iYesterday += iYesterdayLong;
		}
		else if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Short && pInvestorPosition->PositionDate == THOST_FTDC_PSD_Today)
		{
			//iToday -= pInvestorPosition->Position;

			iYesterdayShort -= (pInvestorPosition->YdPosition > pInvestorPosition->CloseVolume ? pInvestorPosition->YdPosition - pInvestorPosition->CloseVolume : 0);
			iTodayShort -= pInvestorPosition->TodayPosition;

			//iYesterday += iYesterdayShort;
		}

		if (bIsLast)
		{
			SumPosInfo();
		}

		/*
		//THOST_FTDC_PD_Long 2
		if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Long && pInvestorPosition->PositionDate == THOST_FTDC_PSD_Today)
		{
			iToday += pInvestorPosition->Position;

			iYesterdayLong = pInvestorPosition->YdPosition;
			iTodayLong = pInvestorPosition->TodayPosition;

			iYesterday += iYesterdayLong;
		}
		//THOST_FTDC_PD_Short 3
		else if (pInvestorPosition->PosiDirection == THOST_FTDC_PD_Short && pInvestorPosition->PositionDate == THOST_FTDC_PSD_Today)
		{
			iToday -= pInvestorPosition->Position;

			iYesterdayShort = pInvestorPosition->YdPosition;
			iTodayShort = pInvestorPosition->TodayPosition;

			iYesterday -= iYesterdayShort;
		}
	*/
	}
}

void Position::SumPosInfo()
{
	iToday = iTodayLong + iTodayShort;
	iYesterday = iYesterdayLong + iYesterdayShort;

	iTotalLong = iTodayLong + iYesterdayLong;

	iTotalShort = iTodayShort + iYesterdayShort;

	iTotalPos = iToday + iYesterday;
}

void Position::CalcPosition(TThostFtdcDirectionType Direction, TThostFtdcCombOffsetFlagType CombOffsetFlag, int new_trade_count)
{
	switch (CombOffsetFlag[0])
	{
		//¿ª²Ö
	case THOST_FTDC_OF_Open:
		{
			switch (Direction)
			{
			case THOST_FTDC_D_Buy: // buy
				{				
					iTodayLong += new_trade_count;
					break;
				}
			case THOST_FTDC_D_Sell: // sellshort
				{
					iTodayShort -= new_trade_count;
					break;
				}
			default:
				break;
			}
			break;
		}
		//Æ½²Ö
	case THOST_FTDC_OF_Close:
		{
			switch (Direction)
			{
			case THOST_FTDC_D_Buy: // buy2cover
				{
					if (iYesterdayShort < 0)
					{
						if (-iYesterdayShort < new_trade_count)
						{
							int delta = (new_trade_count + iYesterdayShort); // delta > 0
							iYesterdayShort = 0;
							iTodayShort += delta;
						}
						else
						{
							iYesterdayShort += new_trade_count;
						}
					}
					else if (iYesterdayShort == 0)
					{
						iTodayShort += new_trade_count;
					}
					else
					{
						throw std::logic_error("iYesterdayShort > 0");
					}
					break;
				}
			case THOST_FTDC_D_Sell: // sell
				{
					if (iYesterdayLong > 0)
					{
						if (iYesterdayLong < new_trade_count)
						{
							int delta = (new_trade_count - iYesterdayLong); // delta > 0
							iYesterdayLong = 0;
							iTodayLong -= delta;
						}
						else
						{
							iYesterdayLong -= new_trade_count;
						}
					}
					else if (iYesterdayLong == 0)
					{
						iTodayLong -= new_trade_count;
					}
					else
					{
						throw std::logic_error("iYesterdayLong < 0");
					}
					break;
				}
			default:
				break;
			}
			break;
		}
		/*
	case THOST_FTDC_OF_CloseToday:
		{
			break;
		}
	case THOST_FTDC_OF_CloseYesterday:
		{
			break;
		}
		*/
	default:
		break;
	}
	
	SumPosInfo();
}

PositionMgr::PositionMgr()
{
	position_pool = new boost::pool<>(sizeof(Position));
} 

PositionMgr::~PositionMgr()
{
	if (position_pool)
	{
		position_pool->release_memory();
		delete position_pool;
		position_pool = nullptr;
	}
}

void PositionMgr::clearAllPositions()
{
	POSMAP_ITOR itor = positionCenter.begin();
	for(;itor != positionCenter.end(); itor++)
	{
		itor->second->ResetPosition();
	}
}

void PositionMgr::InitialPostions(std::list<std::string> instruments)
{
	for(list<string>::iterator itor = instruments.begin(); itor != instruments.end(); itor++)
	{
		const string & item = *itor;
		if (positionCenter.find(item) != positionCenter.end())
		{
			Position * p = positionCenter[item];
			p->ResetPosition();
		}
		else
		{
			PBOOSTPOOL_MALLOC(p, position_pool, Position);
			MY_STRCPY(p->instumentid, item.c_str());
			positionCenter[item] = p;
		}
	}
}

void PositionMgr::UpdatePosition(CThostFtdcInvestorPositionField * pInvestorPosition, bool bIsLast)
{

	if (pInvestorPosition)
	{
		LOGFILE(LOG_INFO, "%s", pInvestorPosition->InstrumentID);
	}

	int ss = positionCenter.size();

	if (pInvestorPosition == nullptr || strcmp(pInvestorPosition->InstrumentID, "") == 0)
	{
		return;
	}

	const string & key = pInvestorPosition->InstrumentID;
	
	Position * p = nullptr;

	POSMAP_ITOR itor = positionCenter.find(key);
	
	if (itor != positionCenter.end())
	{
		p = itor->second;
	}
	else
	{
		PBOOSTPOOL_MALLOC_2(p, position_pool, Position);
		positionCenter[key] = p;
	}

	if (p)
	{
		p->UpdatePosition(pInvestorPosition, bIsLast);
	}
}

Position * PositionMgr::GetPostion(const std::string & key)
{
	POSMAP_ITOR itor = positionCenter.find(key);
	if (itor != positionCenter.end())
	{
		return itor->second;
	}

	return nullptr;
}

void PositionMgr::CalcPosition(TThostFtdcInstrumentIDType InstrumentID, TThostFtdcDirectionType Direction, TThostFtdcCombOffsetFlagType CombOffsetFlag, int new_trade_count)
{
	Position * p = GetPostion(InstrumentID);

	if (p == nullptr)
	{
		return;
	}

	p->CalcPosition(Direction, CombOffsetFlag, new_trade_count);
}

void PositionMgr::WriteToDisk(const std::string & path)
{
	ofstream fout;
	
	try
	{
		fout.open(path, ios::trunc);

		POSMAP_ITOR itor = positionCenter.begin();

		fout << "instumentid, iTotalPos, iTotalLong, iTotalShort, iToday, iTodayLong, iTodayShort, "
			"iYesterday, iYesterdayLong, iYesterdayShort" << endl;

		for (; itor != positionCenter.end(); itor++)
		{
			Position * p = itor->second;

			if (p)
			{
				fout << p->instumentid << "," << p->iTotalPos  << "," << p->iTotalLong  << "," << p->iTotalShort 
					<< "," << p->iToday << "," << p->iTodayLong << "," << p->iTodayShort << "," << p->iYesterday
					<< "," << p->iYesterdayLong << "," << p->iYesterdayShort << endl;
			}
		}
	}
	catch(...)
	{
	}

	if (fout.is_open())
		fout.close();
}
