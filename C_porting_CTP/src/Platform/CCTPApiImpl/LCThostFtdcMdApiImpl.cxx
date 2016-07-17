#include "LCThostFtdcMdApiImpl.hpp"

LCCThostFtdcMdSpi * GetLCCThostFtdcMdSpi(void * pLC_Spi)
{
	return (LCCThostFtdcMdSpi *)(pLC_Spi);
}

CThostFtdcMdApi * GetCThostFtdcMdApi(void * pLC_Api)
{
	return (CThostFtdcMdApi *)(pLC_Api);
}

LCCThostFtdcMdSpi::LCCThostFtdcMdSpi()
{
	 m_fnMdApiOnFrontConnected = NULL;
	 m_fnMdApiOnFrontDisconnected = NULL;
	 m_fnMdApiOnHeartBeatWarning = NULL;
	 m_fnMdApiOnRspUserLogin = NULL;
	 m_fnMdApiOnRspUserLogout = NULL;
	 m_fnMdApiOnRspError = NULL;
	 m_fnMdApiOnRspSubMarketData = NULL;
	 m_fnMdApiOnRspUnSubMarketData = NULL;
	 m_fnMdApiOnRspSubForQuoteRsp = NULL;
	 m_fnMdApiOnRspUnSubForQuoteRsp = NULL;
	 m_fnMdApiOnRtnDepthMarketData = NULL;
	 m_fnMdApiOnRtnForQuoteRsp = NULL;
}

LCCThostFtdcMdSpi::~LCCThostFtdcMdSpi()
{}

void LCCThostFtdcMdSpi::RegisterMdApiOnFrontConnectedCallback(fnMdApiOnFrontConnected _fnMdApiOnFrontConnected)
{
	 m_fnMdApiOnFrontConnected = _fnMdApiOnFrontConnected;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnFrontDisconnectedCallback(fnMdApiOnFrontDisconnected _fnMdApiOnFrontDisconnected)
{
	 m_fnMdApiOnFrontDisconnected = _fnMdApiOnFrontDisconnected;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnHeartBeatWarningCallback(fnMdApiOnHeartBeatWarning _fnMdApiOnHeartBeatWarning)
{
	 m_fnMdApiOnHeartBeatWarning = _fnMdApiOnHeartBeatWarning;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspUserLoginCallback(fnMdApiOnRspUserLogin _fnMdApiOnRspUserLogin)
{
	 m_fnMdApiOnRspUserLogin = _fnMdApiOnRspUserLogin;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspUserLogoutCallback(fnMdApiOnRspUserLogout _fnMdApiOnRspUserLogout)
{
	 m_fnMdApiOnRspUserLogout = _fnMdApiOnRspUserLogout;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspErrorCallback(fnMdApiOnRspError _fnMdApiOnRspError)
{
	 m_fnMdApiOnRspError = _fnMdApiOnRspError;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspSubMarketDataCallback(fnMdApiOnRspSubMarketData _fnMdApiOnRspSubMarketData)
{
	 m_fnMdApiOnRspSubMarketData = _fnMdApiOnRspSubMarketData;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspUnSubMarketDataCallback(fnMdApiOnRspUnSubMarketData _fnMdApiOnRspUnSubMarketData)
{
	 m_fnMdApiOnRspUnSubMarketData = _fnMdApiOnRspUnSubMarketData;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspSubForQuoteRspCallback(fnMdApiOnRspSubForQuoteRsp _fnMdApiOnRspSubForQuoteRsp)
{
	 m_fnMdApiOnRspSubForQuoteRsp = _fnMdApiOnRspSubForQuoteRsp;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRspUnSubForQuoteRspCallback(fnMdApiOnRspUnSubForQuoteRsp _fnMdApiOnRspUnSubForQuoteRsp)
{
	 m_fnMdApiOnRspUnSubForQuoteRsp = _fnMdApiOnRspUnSubForQuoteRsp;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRtnDepthMarketDataCallback(fnMdApiOnRtnDepthMarketData _fnMdApiOnRtnDepthMarketData)
{
	 m_fnMdApiOnRtnDepthMarketData = _fnMdApiOnRtnDepthMarketData;
}

void LCCThostFtdcMdSpi::RegisterMdApiOnRtnForQuoteRspCallback(fnMdApiOnRtnForQuoteRsp _fnMdApiOnRtnForQuoteRsp)
{
	 m_fnMdApiOnRtnForQuoteRsp = _fnMdApiOnRtnForQuoteRsp;
}

void LCCThostFtdcMdSpi::OnFrontConnected()
{
	 (*m_fnMdApiOnFrontConnected)();
}

void LCCThostFtdcMdSpi::OnFrontDisconnected(int nReason)
{
	 (*m_fnMdApiOnFrontDisconnected)( nReason);
}

void LCCThostFtdcMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	 (*m_fnMdApiOnHeartBeatWarning)( nTimeLapse);
}

void LCCThostFtdcMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspUserLogin)(pRspUserLogin, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspUserLogout)(pUserLogout, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspError)(pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspSubMarketData)(pSpecificInstrument, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspUnSubMarketData)(pSpecificInstrument, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspSubForQuoteRsp)(pSpecificInstrument, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnMdApiOnRspUnSubForQuoteRsp)(pSpecificInstrument, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	 (*m_fnMdApiOnRtnDepthMarketData)(pDepthMarketData);
}

void LCCThostFtdcMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	 (*m_fnMdApiOnRtnForQuoteRsp)(pForQuoteRsp);
}

