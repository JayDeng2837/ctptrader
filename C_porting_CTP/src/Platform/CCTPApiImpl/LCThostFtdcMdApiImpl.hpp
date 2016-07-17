#ifndef LCTHOSTFTDCMDAPIIMPL_HPP
#define LCTHOSTFTDCMDAPIIMPL_HPP
#include "ThostFtdcMdApi.h"
#include "LCThostFtdcMdApi.h"

class LCCThostFtdcMdSpi : public CThostFtdcMdSpi
{
private:

	fnMdApiOnFrontConnected m_fnMdApiOnFrontConnected;
	fnMdApiOnFrontDisconnected m_fnMdApiOnFrontDisconnected;
	fnMdApiOnHeartBeatWarning m_fnMdApiOnHeartBeatWarning;
	fnMdApiOnRspUserLogin m_fnMdApiOnRspUserLogin;
	fnMdApiOnRspUserLogout m_fnMdApiOnRspUserLogout;
	fnMdApiOnRspError m_fnMdApiOnRspError;
	fnMdApiOnRspSubMarketData m_fnMdApiOnRspSubMarketData;
	fnMdApiOnRspUnSubMarketData m_fnMdApiOnRspUnSubMarketData;
	fnMdApiOnRspSubForQuoteRsp m_fnMdApiOnRspSubForQuoteRsp;
	fnMdApiOnRspUnSubForQuoteRsp m_fnMdApiOnRspUnSubForQuoteRsp;
	fnMdApiOnRtnDepthMarketData m_fnMdApiOnRtnDepthMarketData;
	fnMdApiOnRtnForQuoteRsp m_fnMdApiOnRtnForQuoteRsp;

public:
	void RegisterMdApiOnFrontConnectedCallback(fnMdApiOnFrontConnected _fnMdApiOnFrontConnected);
	void RegisterMdApiOnFrontDisconnectedCallback(fnMdApiOnFrontDisconnected _fnMdApiOnFrontDisconnected);
	void RegisterMdApiOnHeartBeatWarningCallback(fnMdApiOnHeartBeatWarning _fnMdApiOnHeartBeatWarning);
	void RegisterMdApiOnRspUserLoginCallback(fnMdApiOnRspUserLogin _fnMdApiOnRspUserLogin);
	void RegisterMdApiOnRspUserLogoutCallback(fnMdApiOnRspUserLogout _fnMdApiOnRspUserLogout);
	void RegisterMdApiOnRspErrorCallback(fnMdApiOnRspError _fnMdApiOnRspError);
	void RegisterMdApiOnRspSubMarketDataCallback(fnMdApiOnRspSubMarketData _fnMdApiOnRspSubMarketData);
	void RegisterMdApiOnRspUnSubMarketDataCallback(fnMdApiOnRspUnSubMarketData _fnMdApiOnRspUnSubMarketData);
	void RegisterMdApiOnRspSubForQuoteRspCallback(fnMdApiOnRspSubForQuoteRsp _fnMdApiOnRspSubForQuoteRsp);
	void RegisterMdApiOnRspUnSubForQuoteRspCallback(fnMdApiOnRspUnSubForQuoteRsp _fnMdApiOnRspUnSubForQuoteRsp);
	void RegisterMdApiOnRtnDepthMarketDataCallback(fnMdApiOnRtnDepthMarketData _fnMdApiOnRtnDepthMarketData);
	void RegisterMdApiOnRtnForQuoteRspCallback(fnMdApiOnRtnForQuoteRsp _fnMdApiOnRtnForQuoteRsp);

public:
	virtual void OnFrontConnected();
	virtual void OnFrontDisconnected(int nReason);
	virtual void OnHeartBeatWarning(int nTimeLapse);
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
	LCCThostFtdcMdSpi();
	~LCCThostFtdcMdSpi();

};

LCCThostFtdcMdSpi * GetLCCThostFtdcMdSpi(void * pLC_Spi);

CThostFtdcMdApi * GetCThostFtdcMdApi(void * pLC_Api);

#endif