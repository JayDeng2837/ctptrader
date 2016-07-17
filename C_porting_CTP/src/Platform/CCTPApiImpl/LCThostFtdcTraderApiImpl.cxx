#include "LCThostFtdcTraderApiImpl.hpp"

LCCThostFtdcTraderSpi * GetLCCThostFtdcTraderSpi(void * pLC_Spi)
{
	return (LCCThostFtdcTraderSpi *)(pLC_Spi);
}

CThostFtdcTraderApi * GetCThostFtdcTraderApi(void * pLC_Api)
{
	return (CThostFtdcTraderApi *)(pLC_Api);
}

LCCThostFtdcTraderSpi::LCCThostFtdcTraderSpi()
{
	 m_fnTraderApiOnFrontConnected = NULL;
	 m_fnTraderApiOnFrontDisconnected = NULL;
	 m_fnTraderApiOnHeartBeatWarning = NULL;
	 m_fnTraderApiOnRspAuthenticate = NULL;
	 m_fnTraderApiOnRspUserLogin = NULL;
	 m_fnTraderApiOnRspUserLogout = NULL;
	 m_fnTraderApiOnRspUserPasswordUpdate = NULL;
	 m_fnTraderApiOnRspTradingAccountPasswordUpdate = NULL;
	 m_fnTraderApiOnRspOrderInsert = NULL;
	 m_fnTraderApiOnRspParkedOrderInsert = NULL;
	 m_fnTraderApiOnRspParkedOrderAction = NULL;
	 m_fnTraderApiOnRspOrderAction = NULL;
	 m_fnTraderApiOnRspQueryMaxOrderVolume = NULL;
	 m_fnTraderApiOnRspSettlementInfoConfirm = NULL;
	 m_fnTraderApiOnRspRemoveParkedOrder = NULL;
	 m_fnTraderApiOnRspRemoveParkedOrderAction = NULL;
	 m_fnTraderApiOnRspExecOrderInsert = NULL;
	 m_fnTraderApiOnRspExecOrderAction = NULL;
	 m_fnTraderApiOnRspForQuoteInsert = NULL;
	 m_fnTraderApiOnRspQuoteInsert = NULL;
	 m_fnTraderApiOnRspQuoteAction = NULL;
	 m_fnTraderApiOnRspQryOrder = NULL;
	 m_fnTraderApiOnRspQryTrade = NULL;
	 m_fnTraderApiOnRspQryInvestorPosition = NULL;
	 m_fnTraderApiOnRspQryTradingAccount = NULL;
	 m_fnTraderApiOnRspQryInvestor = NULL;
	 m_fnTraderApiOnRspQryTradingCode = NULL;
	 m_fnTraderApiOnRspQryInstrumentMarginRate = NULL;
	 m_fnTraderApiOnRspQryInstrumentCommissionRate = NULL;
	 m_fnTraderApiOnRspQryExchange = NULL;
	 m_fnTraderApiOnRspQryProduct = NULL;
	 m_fnTraderApiOnRspQryInstrument = NULL;
	 m_fnTraderApiOnRspQryDepthMarketData = NULL;
	 m_fnTraderApiOnRspQrySettlementInfo = NULL;
	 m_fnTraderApiOnRspQryTransferBank = NULL;
	 m_fnTraderApiOnRspQryInvestorPositionDetail = NULL;
	 m_fnTraderApiOnRspQryNotice = NULL;
	 m_fnTraderApiOnRspQrySettlementInfoConfirm = NULL;
	 m_fnTraderApiOnRspQryInvestorPositionCombineDetail = NULL;
	 m_fnTraderApiOnRspQryCFMMCTradingAccountKey = NULL;
	 m_fnTraderApiOnRspQryEWarrantOffset = NULL;
	 m_fnTraderApiOnRspQryInvestorProductGroupMargin = NULL;
	 m_fnTraderApiOnRspQryExchangeMarginRate = NULL;
	 m_fnTraderApiOnRspQryExchangeMarginRateAdjust = NULL;
	 m_fnTraderApiOnRspQryExchangeRate = NULL;
	 m_fnTraderApiOnRspQrySecAgentACIDMap = NULL;
	 m_fnTraderApiOnRspQryOptionInstrTradeCost = NULL;
	 m_fnTraderApiOnRspQryOptionInstrCommRate = NULL;
	 m_fnTraderApiOnRspQryExecOrder = NULL;
	 m_fnTraderApiOnRspQryForQuote = NULL;
	 m_fnTraderApiOnRspQryQuote = NULL;
	 m_fnTraderApiOnRspQryTransferSerial = NULL;
	 m_fnTraderApiOnRspQryAccountregister = NULL;
	 m_fnTraderApiOnRspError = NULL;
	 m_fnTraderApiOnRtnOrder = NULL;
	 m_fnTraderApiOnRtnTrade = NULL;
	 m_fnTraderApiOnErrRtnOrderInsert = NULL;
	 m_fnTraderApiOnErrRtnOrderAction = NULL;
	 m_fnTraderApiOnRtnInstrumentStatus = NULL;
	 m_fnTraderApiOnRtnTradingNotice = NULL;
	 m_fnTraderApiOnRtnErrorConditionalOrder = NULL;
	 m_fnTraderApiOnRtnExecOrder = NULL;
	 m_fnTraderApiOnErrRtnExecOrderInsert = NULL;
	 m_fnTraderApiOnErrRtnExecOrderAction = NULL;
	 m_fnTraderApiOnErrRtnForQuoteInsert = NULL;
	 m_fnTraderApiOnRtnQuote = NULL;
	 m_fnTraderApiOnErrRtnQuoteInsert = NULL;
	 m_fnTraderApiOnErrRtnQuoteAction = NULL;
	 m_fnTraderApiOnRtnForQuoteRsp = NULL;
	 m_fnTraderApiOnRspQryContractBank = NULL;
	 m_fnTraderApiOnRspQryParkedOrder = NULL;
	 m_fnTraderApiOnRspQryParkedOrderAction = NULL;
	 m_fnTraderApiOnRspQryTradingNotice = NULL;
	 m_fnTraderApiOnRspQryBrokerTradingParams = NULL;
	 m_fnTraderApiOnRspQryBrokerTradingAlgos = NULL;
	 m_fnTraderApiOnRtnFromBankToFutureByBank = NULL;
	 m_fnTraderApiOnRtnFromFutureToBankByBank = NULL;
	 m_fnTraderApiOnRtnRepealFromBankToFutureByBank = NULL;
	 m_fnTraderApiOnRtnRepealFromFutureToBankByBank = NULL;
	 m_fnTraderApiOnRtnFromBankToFutureByFuture = NULL;
	 m_fnTraderApiOnRtnFromFutureToBankByFuture = NULL;
	 m_fnTraderApiOnRtnRepealFromBankToFutureByFutureManual = NULL;
	 m_fnTraderApiOnRtnRepealFromFutureToBankByFutureManual = NULL;
	 m_fnTraderApiOnRtnQueryBankBalanceByFuture = NULL;
	 m_fnTraderApiOnErrRtnBankToFutureByFuture = NULL;
	 m_fnTraderApiOnErrRtnFutureToBankByFuture = NULL;
	 m_fnTraderApiOnErrRtnRepealBankToFutureByFutureManual = NULL;
	 m_fnTraderApiOnErrRtnRepealFutureToBankByFutureManual = NULL;
	 m_fnTraderApiOnErrRtnQueryBankBalanceByFuture = NULL;
	 m_fnTraderApiOnRtnRepealFromBankToFutureByFuture = NULL;
	 m_fnTraderApiOnRtnRepealFromFutureToBankByFuture = NULL;
	 m_fnTraderApiOnRspFromBankToFutureByFuture = NULL;
	 m_fnTraderApiOnRspFromFutureToBankByFuture = NULL;
	 m_fnTraderApiOnRspQueryBankAccountMoneyByFuture = NULL;
	 m_fnTraderApiOnRtnOpenAccountByBank = NULL;
	 m_fnTraderApiOnRtnCancelAccountByBank = NULL;
	 m_fnTraderApiOnRtnChangeAccountByBank = NULL;
}

LCCThostFtdcTraderSpi::~LCCThostFtdcTraderSpi()
{}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnFrontConnectedCallback(fnTraderApiOnFrontConnected _fnTraderApiOnFrontConnected)
{
	 m_fnTraderApiOnFrontConnected = _fnTraderApiOnFrontConnected;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnFrontDisconnectedCallback(fnTraderApiOnFrontDisconnected _fnTraderApiOnFrontDisconnected)
{
	 m_fnTraderApiOnFrontDisconnected = _fnTraderApiOnFrontDisconnected;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnHeartBeatWarningCallback(fnTraderApiOnHeartBeatWarning _fnTraderApiOnHeartBeatWarning)
{
	 m_fnTraderApiOnHeartBeatWarning = _fnTraderApiOnHeartBeatWarning;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspAuthenticateCallback(fnTraderApiOnRspAuthenticate _fnTraderApiOnRspAuthenticate)
{
	 m_fnTraderApiOnRspAuthenticate = _fnTraderApiOnRspAuthenticate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspUserLoginCallback(fnTraderApiOnRspUserLogin _fnTraderApiOnRspUserLogin)
{
	 m_fnTraderApiOnRspUserLogin = _fnTraderApiOnRspUserLogin;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspUserLogoutCallback(fnTraderApiOnRspUserLogout _fnTraderApiOnRspUserLogout)
{
	 m_fnTraderApiOnRspUserLogout = _fnTraderApiOnRspUserLogout;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspUserPasswordUpdateCallback(fnTraderApiOnRspUserPasswordUpdate _fnTraderApiOnRspUserPasswordUpdate)
{
	 m_fnTraderApiOnRspUserPasswordUpdate = _fnTraderApiOnRspUserPasswordUpdate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspTradingAccountPasswordUpdateCallback(fnTraderApiOnRspTradingAccountPasswordUpdate _fnTraderApiOnRspTradingAccountPasswordUpdate)
{
	 m_fnTraderApiOnRspTradingAccountPasswordUpdate = _fnTraderApiOnRspTradingAccountPasswordUpdate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspOrderInsertCallback(fnTraderApiOnRspOrderInsert _fnTraderApiOnRspOrderInsert)
{
	 m_fnTraderApiOnRspOrderInsert = _fnTraderApiOnRspOrderInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspParkedOrderInsertCallback(fnTraderApiOnRspParkedOrderInsert _fnTraderApiOnRspParkedOrderInsert)
{
	 m_fnTraderApiOnRspParkedOrderInsert = _fnTraderApiOnRspParkedOrderInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspParkedOrderActionCallback(fnTraderApiOnRspParkedOrderAction _fnTraderApiOnRspParkedOrderAction)
{
	 m_fnTraderApiOnRspParkedOrderAction = _fnTraderApiOnRspParkedOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspOrderActionCallback(fnTraderApiOnRspOrderAction _fnTraderApiOnRspOrderAction)
{
	 m_fnTraderApiOnRspOrderAction = _fnTraderApiOnRspOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQueryMaxOrderVolumeCallback(fnTraderApiOnRspQueryMaxOrderVolume _fnTraderApiOnRspQueryMaxOrderVolume)
{
	 m_fnTraderApiOnRspQueryMaxOrderVolume = _fnTraderApiOnRspQueryMaxOrderVolume;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspSettlementInfoConfirmCallback(fnTraderApiOnRspSettlementInfoConfirm _fnTraderApiOnRspSettlementInfoConfirm)
{
	 m_fnTraderApiOnRspSettlementInfoConfirm = _fnTraderApiOnRspSettlementInfoConfirm;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspRemoveParkedOrderCallback(fnTraderApiOnRspRemoveParkedOrder _fnTraderApiOnRspRemoveParkedOrder)
{
	 m_fnTraderApiOnRspRemoveParkedOrder = _fnTraderApiOnRspRemoveParkedOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspRemoveParkedOrderActionCallback(fnTraderApiOnRspRemoveParkedOrderAction _fnTraderApiOnRspRemoveParkedOrderAction)
{
	 m_fnTraderApiOnRspRemoveParkedOrderAction = _fnTraderApiOnRspRemoveParkedOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspExecOrderInsertCallback(fnTraderApiOnRspExecOrderInsert _fnTraderApiOnRspExecOrderInsert)
{
	 m_fnTraderApiOnRspExecOrderInsert = _fnTraderApiOnRspExecOrderInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspExecOrderActionCallback(fnTraderApiOnRspExecOrderAction _fnTraderApiOnRspExecOrderAction)
{
	 m_fnTraderApiOnRspExecOrderAction = _fnTraderApiOnRspExecOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspForQuoteInsertCallback(fnTraderApiOnRspForQuoteInsert _fnTraderApiOnRspForQuoteInsert)
{
	 m_fnTraderApiOnRspForQuoteInsert = _fnTraderApiOnRspForQuoteInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQuoteInsertCallback(fnTraderApiOnRspQuoteInsert _fnTraderApiOnRspQuoteInsert)
{
	 m_fnTraderApiOnRspQuoteInsert = _fnTraderApiOnRspQuoteInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQuoteActionCallback(fnTraderApiOnRspQuoteAction _fnTraderApiOnRspQuoteAction)
{
	 m_fnTraderApiOnRspQuoteAction = _fnTraderApiOnRspQuoteAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryOrderCallback(fnTraderApiOnRspQryOrder _fnTraderApiOnRspQryOrder)
{
	 m_fnTraderApiOnRspQryOrder = _fnTraderApiOnRspQryOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTradeCallback(fnTraderApiOnRspQryTrade _fnTraderApiOnRspQryTrade)
{
	 m_fnTraderApiOnRspQryTrade = _fnTraderApiOnRspQryTrade;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInvestorPositionCallback(fnTraderApiOnRspQryInvestorPosition _fnTraderApiOnRspQryInvestorPosition)
{
	 m_fnTraderApiOnRspQryInvestorPosition = _fnTraderApiOnRspQryInvestorPosition;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTradingAccountCallback(fnTraderApiOnRspQryTradingAccount _fnTraderApiOnRspQryTradingAccount)
{
	 m_fnTraderApiOnRspQryTradingAccount = _fnTraderApiOnRspQryTradingAccount;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInvestorCallback(fnTraderApiOnRspQryInvestor _fnTraderApiOnRspQryInvestor)
{
	 m_fnTraderApiOnRspQryInvestor = _fnTraderApiOnRspQryInvestor;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTradingCodeCallback(fnTraderApiOnRspQryTradingCode _fnTraderApiOnRspQryTradingCode)
{
	 m_fnTraderApiOnRspQryTradingCode = _fnTraderApiOnRspQryTradingCode;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInstrumentMarginRateCallback(fnTraderApiOnRspQryInstrumentMarginRate _fnTraderApiOnRspQryInstrumentMarginRate)
{
	 m_fnTraderApiOnRspQryInstrumentMarginRate = _fnTraderApiOnRspQryInstrumentMarginRate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInstrumentCommissionRateCallback(fnTraderApiOnRspQryInstrumentCommissionRate _fnTraderApiOnRspQryInstrumentCommissionRate)
{
	 m_fnTraderApiOnRspQryInstrumentCommissionRate = _fnTraderApiOnRspQryInstrumentCommissionRate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryExchangeCallback(fnTraderApiOnRspQryExchange _fnTraderApiOnRspQryExchange)
{
	 m_fnTraderApiOnRspQryExchange = _fnTraderApiOnRspQryExchange;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryProductCallback(fnTraderApiOnRspQryProduct _fnTraderApiOnRspQryProduct)
{
	 m_fnTraderApiOnRspQryProduct = _fnTraderApiOnRspQryProduct;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInstrumentCallback(fnTraderApiOnRspQryInstrument _fnTraderApiOnRspQryInstrument)
{
	 m_fnTraderApiOnRspQryInstrument = _fnTraderApiOnRspQryInstrument;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryDepthMarketDataCallback(fnTraderApiOnRspQryDepthMarketData _fnTraderApiOnRspQryDepthMarketData)
{
	 m_fnTraderApiOnRspQryDepthMarketData = _fnTraderApiOnRspQryDepthMarketData;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQrySettlementInfoCallback(fnTraderApiOnRspQrySettlementInfo _fnTraderApiOnRspQrySettlementInfo)
{
	 m_fnTraderApiOnRspQrySettlementInfo = _fnTraderApiOnRspQrySettlementInfo;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTransferBankCallback(fnTraderApiOnRspQryTransferBank _fnTraderApiOnRspQryTransferBank)
{
	 m_fnTraderApiOnRspQryTransferBank = _fnTraderApiOnRspQryTransferBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInvestorPositionDetailCallback(fnTraderApiOnRspQryInvestorPositionDetail _fnTraderApiOnRspQryInvestorPositionDetail)
{
	 m_fnTraderApiOnRspQryInvestorPositionDetail = _fnTraderApiOnRspQryInvestorPositionDetail;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryNoticeCallback(fnTraderApiOnRspQryNotice _fnTraderApiOnRspQryNotice)
{
	 m_fnTraderApiOnRspQryNotice = _fnTraderApiOnRspQryNotice;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQrySettlementInfoConfirmCallback(fnTraderApiOnRspQrySettlementInfoConfirm _fnTraderApiOnRspQrySettlementInfoConfirm)
{
	 m_fnTraderApiOnRspQrySettlementInfoConfirm = _fnTraderApiOnRspQrySettlementInfoConfirm;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInvestorPositionCombineDetailCallback(fnTraderApiOnRspQryInvestorPositionCombineDetail _fnTraderApiOnRspQryInvestorPositionCombineDetail)
{
	 m_fnTraderApiOnRspQryInvestorPositionCombineDetail = _fnTraderApiOnRspQryInvestorPositionCombineDetail;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryCFMMCTradingAccountKeyCallback(fnTraderApiOnRspQryCFMMCTradingAccountKey _fnTraderApiOnRspQryCFMMCTradingAccountKey)
{
	 m_fnTraderApiOnRspQryCFMMCTradingAccountKey = _fnTraderApiOnRspQryCFMMCTradingAccountKey;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryEWarrantOffsetCallback(fnTraderApiOnRspQryEWarrantOffset _fnTraderApiOnRspQryEWarrantOffset)
{
	 m_fnTraderApiOnRspQryEWarrantOffset = _fnTraderApiOnRspQryEWarrantOffset;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryInvestorProductGroupMarginCallback(fnTraderApiOnRspQryInvestorProductGroupMargin _fnTraderApiOnRspQryInvestorProductGroupMargin)
{
	 m_fnTraderApiOnRspQryInvestorProductGroupMargin = _fnTraderApiOnRspQryInvestorProductGroupMargin;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryExchangeMarginRateCallback(fnTraderApiOnRspQryExchangeMarginRate _fnTraderApiOnRspQryExchangeMarginRate)
{
	 m_fnTraderApiOnRspQryExchangeMarginRate = _fnTraderApiOnRspQryExchangeMarginRate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryExchangeMarginRateAdjustCallback(fnTraderApiOnRspQryExchangeMarginRateAdjust _fnTraderApiOnRspQryExchangeMarginRateAdjust)
{
	 m_fnTraderApiOnRspQryExchangeMarginRateAdjust = _fnTraderApiOnRspQryExchangeMarginRateAdjust;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryExchangeRateCallback(fnTraderApiOnRspQryExchangeRate _fnTraderApiOnRspQryExchangeRate)
{
	 m_fnTraderApiOnRspQryExchangeRate = _fnTraderApiOnRspQryExchangeRate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQrySecAgentACIDMapCallback(fnTraderApiOnRspQrySecAgentACIDMap _fnTraderApiOnRspQrySecAgentACIDMap)
{
	 m_fnTraderApiOnRspQrySecAgentACIDMap = _fnTraderApiOnRspQrySecAgentACIDMap;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryOptionInstrTradeCostCallback(fnTraderApiOnRspQryOptionInstrTradeCost _fnTraderApiOnRspQryOptionInstrTradeCost)
{
	 m_fnTraderApiOnRspQryOptionInstrTradeCost = _fnTraderApiOnRspQryOptionInstrTradeCost;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryOptionInstrCommRateCallback(fnTraderApiOnRspQryOptionInstrCommRate _fnTraderApiOnRspQryOptionInstrCommRate)
{
	 m_fnTraderApiOnRspQryOptionInstrCommRate = _fnTraderApiOnRspQryOptionInstrCommRate;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryExecOrderCallback(fnTraderApiOnRspQryExecOrder _fnTraderApiOnRspQryExecOrder)
{
	 m_fnTraderApiOnRspQryExecOrder = _fnTraderApiOnRspQryExecOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryForQuoteCallback(fnTraderApiOnRspQryForQuote _fnTraderApiOnRspQryForQuote)
{
	 m_fnTraderApiOnRspQryForQuote = _fnTraderApiOnRspQryForQuote;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryQuoteCallback(fnTraderApiOnRspQryQuote _fnTraderApiOnRspQryQuote)
{
	 m_fnTraderApiOnRspQryQuote = _fnTraderApiOnRspQryQuote;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTransferSerialCallback(fnTraderApiOnRspQryTransferSerial _fnTraderApiOnRspQryTransferSerial)
{
	 m_fnTraderApiOnRspQryTransferSerial = _fnTraderApiOnRspQryTransferSerial;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryAccountregisterCallback(fnTraderApiOnRspQryAccountregister _fnTraderApiOnRspQryAccountregister)
{
	 m_fnTraderApiOnRspQryAccountregister = _fnTraderApiOnRspQryAccountregister;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspErrorCallback(fnTraderApiOnRspError _fnTraderApiOnRspError)
{
	 m_fnTraderApiOnRspError = _fnTraderApiOnRspError;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnOrderCallback(fnTraderApiOnRtnOrder _fnTraderApiOnRtnOrder)
{
	 m_fnTraderApiOnRtnOrder = _fnTraderApiOnRtnOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnTradeCallback(fnTraderApiOnRtnTrade _fnTraderApiOnRtnTrade)
{
	 m_fnTraderApiOnRtnTrade = _fnTraderApiOnRtnTrade;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnOrderInsertCallback(fnTraderApiOnErrRtnOrderInsert _fnTraderApiOnErrRtnOrderInsert)
{
	 m_fnTraderApiOnErrRtnOrderInsert = _fnTraderApiOnErrRtnOrderInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnOrderActionCallback(fnTraderApiOnErrRtnOrderAction _fnTraderApiOnErrRtnOrderAction)
{
	 m_fnTraderApiOnErrRtnOrderAction = _fnTraderApiOnErrRtnOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnInstrumentStatusCallback(fnTraderApiOnRtnInstrumentStatus _fnTraderApiOnRtnInstrumentStatus)
{
	 m_fnTraderApiOnRtnInstrumentStatus = _fnTraderApiOnRtnInstrumentStatus;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnTradingNoticeCallback(fnTraderApiOnRtnTradingNotice _fnTraderApiOnRtnTradingNotice)
{
	 m_fnTraderApiOnRtnTradingNotice = _fnTraderApiOnRtnTradingNotice;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnErrorConditionalOrderCallback(fnTraderApiOnRtnErrorConditionalOrder _fnTraderApiOnRtnErrorConditionalOrder)
{
	 m_fnTraderApiOnRtnErrorConditionalOrder = _fnTraderApiOnRtnErrorConditionalOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnExecOrderCallback(fnTraderApiOnRtnExecOrder _fnTraderApiOnRtnExecOrder)
{
	 m_fnTraderApiOnRtnExecOrder = _fnTraderApiOnRtnExecOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnExecOrderInsertCallback(fnTraderApiOnErrRtnExecOrderInsert _fnTraderApiOnErrRtnExecOrderInsert)
{
	 m_fnTraderApiOnErrRtnExecOrderInsert = _fnTraderApiOnErrRtnExecOrderInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnExecOrderActionCallback(fnTraderApiOnErrRtnExecOrderAction _fnTraderApiOnErrRtnExecOrderAction)
{
	 m_fnTraderApiOnErrRtnExecOrderAction = _fnTraderApiOnErrRtnExecOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnForQuoteInsertCallback(fnTraderApiOnErrRtnForQuoteInsert _fnTraderApiOnErrRtnForQuoteInsert)
{
	 m_fnTraderApiOnErrRtnForQuoteInsert = _fnTraderApiOnErrRtnForQuoteInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnQuoteCallback(fnTraderApiOnRtnQuote _fnTraderApiOnRtnQuote)
{
	 m_fnTraderApiOnRtnQuote = _fnTraderApiOnRtnQuote;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnQuoteInsertCallback(fnTraderApiOnErrRtnQuoteInsert _fnTraderApiOnErrRtnQuoteInsert)
{
	 m_fnTraderApiOnErrRtnQuoteInsert = _fnTraderApiOnErrRtnQuoteInsert;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnQuoteActionCallback(fnTraderApiOnErrRtnQuoteAction _fnTraderApiOnErrRtnQuoteAction)
{
	 m_fnTraderApiOnErrRtnQuoteAction = _fnTraderApiOnErrRtnQuoteAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnForQuoteRspCallback(fnTraderApiOnRtnForQuoteRsp _fnTraderApiOnRtnForQuoteRsp)
{
	 m_fnTraderApiOnRtnForQuoteRsp = _fnTraderApiOnRtnForQuoteRsp;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryContractBankCallback(fnTraderApiOnRspQryContractBank _fnTraderApiOnRspQryContractBank)
{
	 m_fnTraderApiOnRspQryContractBank = _fnTraderApiOnRspQryContractBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryParkedOrderCallback(fnTraderApiOnRspQryParkedOrder _fnTraderApiOnRspQryParkedOrder)
{
	 m_fnTraderApiOnRspQryParkedOrder = _fnTraderApiOnRspQryParkedOrder;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryParkedOrderActionCallback(fnTraderApiOnRspQryParkedOrderAction _fnTraderApiOnRspQryParkedOrderAction)
{
	 m_fnTraderApiOnRspQryParkedOrderAction = _fnTraderApiOnRspQryParkedOrderAction;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryTradingNoticeCallback(fnTraderApiOnRspQryTradingNotice _fnTraderApiOnRspQryTradingNotice)
{
	 m_fnTraderApiOnRspQryTradingNotice = _fnTraderApiOnRspQryTradingNotice;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryBrokerTradingParamsCallback(fnTraderApiOnRspQryBrokerTradingParams _fnTraderApiOnRspQryBrokerTradingParams)
{
	 m_fnTraderApiOnRspQryBrokerTradingParams = _fnTraderApiOnRspQryBrokerTradingParams;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQryBrokerTradingAlgosCallback(fnTraderApiOnRspQryBrokerTradingAlgos _fnTraderApiOnRspQryBrokerTradingAlgos)
{
	 m_fnTraderApiOnRspQryBrokerTradingAlgos = _fnTraderApiOnRspQryBrokerTradingAlgos;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnFromBankToFutureByBankCallback(fnTraderApiOnRtnFromBankToFutureByBank _fnTraderApiOnRtnFromBankToFutureByBank)
{
	 m_fnTraderApiOnRtnFromBankToFutureByBank = _fnTraderApiOnRtnFromBankToFutureByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnFromFutureToBankByBankCallback(fnTraderApiOnRtnFromFutureToBankByBank _fnTraderApiOnRtnFromFutureToBankByBank)
{
	 m_fnTraderApiOnRtnFromFutureToBankByBank = _fnTraderApiOnRtnFromFutureToBankByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromBankToFutureByBankCallback(fnTraderApiOnRtnRepealFromBankToFutureByBank _fnTraderApiOnRtnRepealFromBankToFutureByBank)
{
	 m_fnTraderApiOnRtnRepealFromBankToFutureByBank = _fnTraderApiOnRtnRepealFromBankToFutureByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromFutureToBankByBankCallback(fnTraderApiOnRtnRepealFromFutureToBankByBank _fnTraderApiOnRtnRepealFromFutureToBankByBank)
{
	 m_fnTraderApiOnRtnRepealFromFutureToBankByBank = _fnTraderApiOnRtnRepealFromFutureToBankByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnFromBankToFutureByFutureCallback(fnTraderApiOnRtnFromBankToFutureByFuture _fnTraderApiOnRtnFromBankToFutureByFuture)
{
	 m_fnTraderApiOnRtnFromBankToFutureByFuture = _fnTraderApiOnRtnFromBankToFutureByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnFromFutureToBankByFutureCallback(fnTraderApiOnRtnFromFutureToBankByFuture _fnTraderApiOnRtnFromFutureToBankByFuture)
{
	 m_fnTraderApiOnRtnFromFutureToBankByFuture = _fnTraderApiOnRtnFromFutureToBankByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromBankToFutureByFutureManualCallback(fnTraderApiOnRtnRepealFromBankToFutureByFutureManual _fnTraderApiOnRtnRepealFromBankToFutureByFutureManual)
{
	 m_fnTraderApiOnRtnRepealFromBankToFutureByFutureManual = _fnTraderApiOnRtnRepealFromBankToFutureByFutureManual;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromFutureToBankByFutureManualCallback(fnTraderApiOnRtnRepealFromFutureToBankByFutureManual _fnTraderApiOnRtnRepealFromFutureToBankByFutureManual)
{
	 m_fnTraderApiOnRtnRepealFromFutureToBankByFutureManual = _fnTraderApiOnRtnRepealFromFutureToBankByFutureManual;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnQueryBankBalanceByFutureCallback(fnTraderApiOnRtnQueryBankBalanceByFuture _fnTraderApiOnRtnQueryBankBalanceByFuture)
{
	 m_fnTraderApiOnRtnQueryBankBalanceByFuture = _fnTraderApiOnRtnQueryBankBalanceByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnBankToFutureByFutureCallback(fnTraderApiOnErrRtnBankToFutureByFuture _fnTraderApiOnErrRtnBankToFutureByFuture)
{
	 m_fnTraderApiOnErrRtnBankToFutureByFuture = _fnTraderApiOnErrRtnBankToFutureByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnFutureToBankByFutureCallback(fnTraderApiOnErrRtnFutureToBankByFuture _fnTraderApiOnErrRtnFutureToBankByFuture)
{
	 m_fnTraderApiOnErrRtnFutureToBankByFuture = _fnTraderApiOnErrRtnFutureToBankByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnRepealBankToFutureByFutureManualCallback(fnTraderApiOnErrRtnRepealBankToFutureByFutureManual _fnTraderApiOnErrRtnRepealBankToFutureByFutureManual)
{
	 m_fnTraderApiOnErrRtnRepealBankToFutureByFutureManual = _fnTraderApiOnErrRtnRepealBankToFutureByFutureManual;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnRepealFutureToBankByFutureManualCallback(fnTraderApiOnErrRtnRepealFutureToBankByFutureManual _fnTraderApiOnErrRtnRepealFutureToBankByFutureManual)
{
	 m_fnTraderApiOnErrRtnRepealFutureToBankByFutureManual = _fnTraderApiOnErrRtnRepealFutureToBankByFutureManual;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnErrRtnQueryBankBalanceByFutureCallback(fnTraderApiOnErrRtnQueryBankBalanceByFuture _fnTraderApiOnErrRtnQueryBankBalanceByFuture)
{
	 m_fnTraderApiOnErrRtnQueryBankBalanceByFuture = _fnTraderApiOnErrRtnQueryBankBalanceByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromBankToFutureByFutureCallback(fnTraderApiOnRtnRepealFromBankToFutureByFuture _fnTraderApiOnRtnRepealFromBankToFutureByFuture)
{
	 m_fnTraderApiOnRtnRepealFromBankToFutureByFuture = _fnTraderApiOnRtnRepealFromBankToFutureByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnRepealFromFutureToBankByFutureCallback(fnTraderApiOnRtnRepealFromFutureToBankByFuture _fnTraderApiOnRtnRepealFromFutureToBankByFuture)
{
	 m_fnTraderApiOnRtnRepealFromFutureToBankByFuture = _fnTraderApiOnRtnRepealFromFutureToBankByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspFromBankToFutureByFutureCallback(fnTraderApiOnRspFromBankToFutureByFuture _fnTraderApiOnRspFromBankToFutureByFuture)
{
	 m_fnTraderApiOnRspFromBankToFutureByFuture = _fnTraderApiOnRspFromBankToFutureByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspFromFutureToBankByFutureCallback(fnTraderApiOnRspFromFutureToBankByFuture _fnTraderApiOnRspFromFutureToBankByFuture)
{
	 m_fnTraderApiOnRspFromFutureToBankByFuture = _fnTraderApiOnRspFromFutureToBankByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRspQueryBankAccountMoneyByFutureCallback(fnTraderApiOnRspQueryBankAccountMoneyByFuture _fnTraderApiOnRspQueryBankAccountMoneyByFuture)
{
	 m_fnTraderApiOnRspQueryBankAccountMoneyByFuture = _fnTraderApiOnRspQueryBankAccountMoneyByFuture;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnOpenAccountByBankCallback(fnTraderApiOnRtnOpenAccountByBank _fnTraderApiOnRtnOpenAccountByBank)
{
	 m_fnTraderApiOnRtnOpenAccountByBank = _fnTraderApiOnRtnOpenAccountByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnCancelAccountByBankCallback(fnTraderApiOnRtnCancelAccountByBank _fnTraderApiOnRtnCancelAccountByBank)
{
	 m_fnTraderApiOnRtnCancelAccountByBank = _fnTraderApiOnRtnCancelAccountByBank;
}

void LCCThostFtdcTraderSpi::RegisterTraderApiOnRtnChangeAccountByBankCallback(fnTraderApiOnRtnChangeAccountByBank _fnTraderApiOnRtnChangeAccountByBank)
{
	 m_fnTraderApiOnRtnChangeAccountByBank = _fnTraderApiOnRtnChangeAccountByBank;
}

void LCCThostFtdcTraderSpi::OnFrontConnected()
{
	 (*m_fnTraderApiOnFrontConnected)();
}

void LCCThostFtdcTraderSpi::OnFrontDisconnected(int nReason)
{
	 (*m_fnTraderApiOnFrontDisconnected)( nReason);
}

void LCCThostFtdcTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
	 (*m_fnTraderApiOnHeartBeatWarning)( nTimeLapse);
}

void LCCThostFtdcTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspAuthenticate)(pRspAuthenticateField, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspUserLogin)(pRspUserLogin, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspUserLogout)(pUserLogout, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspUserPasswordUpdate)(pUserPasswordUpdate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspTradingAccountPasswordUpdate)(pTradingAccountPasswordUpdate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspOrderInsert)(pInputOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspParkedOrderInsert)(pParkedOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspParkedOrderAction)(pParkedOrderAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspOrderAction)(pInputOrderAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQueryMaxOrderVolume)(pQueryMaxOrderVolume, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspSettlementInfoConfirm)(pSettlementInfoConfirm, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspRemoveParkedOrder)(pRemoveParkedOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspRemoveParkedOrderAction)(pRemoveParkedOrderAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspExecOrderInsert)(pInputExecOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspExecOrderAction)(pInputExecOrderAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspForQuoteInsert)(pInputForQuote, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQuoteInsert)(pInputQuote, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQuoteAction)(pInputQuoteAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryOrder)(pOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTrade)(pTrade, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInvestorPosition)(pInvestorPosition, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTradingAccount)(pTradingAccount, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInvestor)(pInvestor, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTradingCode)(pTradingCode, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInstrumentMarginRate)(pInstrumentMarginRate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInstrumentCommissionRate)(pInstrumentCommissionRate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryExchange)(pExchange, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryProduct)(pProduct, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInstrument)(pInstrument, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryDepthMarketData)(pDepthMarketData, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQrySettlementInfo)(pSettlementInfo, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTransferBank)(pTransferBank, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInvestorPositionDetail)(pInvestorPositionDetail, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryNotice)(pNotice, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQrySettlementInfoConfirm)(pSettlementInfoConfirm, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInvestorPositionCombineDetail)(pInvestorPositionCombineDetail, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryCFMMCTradingAccountKey)(pCFMMCTradingAccountKey, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryEWarrantOffset)(pEWarrantOffset, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryInvestorProductGroupMargin)(pInvestorProductGroupMargin, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryExchangeMarginRate)(pExchangeMarginRate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryExchangeMarginRateAdjust)(pExchangeMarginRateAdjust, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryExchangeRate)(pExchangeRate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQrySecAgentACIDMap)(pSecAgentACIDMap, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryOptionInstrTradeCost)(pOptionInstrTradeCost, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryOptionInstrCommRate)(pOptionInstrCommRate, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryExecOrder)(pExecOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryForQuote)(pForQuote, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryQuote)(pQuote, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTransferSerial)(pTransferSerial, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryAccountregister)(pAccountregister, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspError)(pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	 (*m_fnTraderApiOnRtnOrder)(pOrder);
}

void LCCThostFtdcTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	 (*m_fnTraderApiOnRtnTrade)(pTrade);
}

void LCCThostFtdcTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnOrderInsert)(pInputOrder, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnOrderAction)(pOrderAction, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
{
	 (*m_fnTraderApiOnRtnInstrumentStatus)(pInstrumentStatus);
}

void LCCThostFtdcTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
{
	 (*m_fnTraderApiOnRtnTradingNotice)(pTradingNoticeInfo);
}

void LCCThostFtdcTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
{
	 (*m_fnTraderApiOnRtnErrorConditionalOrder)(pErrorConditionalOrder);
}

void LCCThostFtdcTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder)
{
	 (*m_fnTraderApiOnRtnExecOrder)(pExecOrder);
}

void LCCThostFtdcTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnExecOrderInsert)(pInputExecOrder, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnExecOrderAction)(pExecOrderAction, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnForQuoteInsert)(pInputForQuote, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnRtnQuote(CThostFtdcQuoteField *pQuote)
{
	 (*m_fnTraderApiOnRtnQuote)(pQuote);
}

void LCCThostFtdcTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnQuoteInsert)(pInputQuote, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnQuoteAction)(pQuoteAction, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{
	 (*m_fnTraderApiOnRtnForQuoteRsp)(pForQuoteRsp);
}

void LCCThostFtdcTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryContractBank)(pContractBank, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryParkedOrder)(pParkedOrder, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryParkedOrderAction)(pParkedOrderAction, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryTradingNotice)(pTradingNotice, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryBrokerTradingParams)(pBrokerTradingParams, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQryBrokerTradingAlgos)(pBrokerTradingAlgos, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	 (*m_fnTraderApiOnRtnFromBankToFutureByBank)(pRspTransfer);
}

void LCCThostFtdcTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	 (*m_fnTraderApiOnRtnFromFutureToBankByBank)(pRspTransfer);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromBankToFutureByBank)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromFutureToBankByBank)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	 (*m_fnTraderApiOnRtnFromBankToFutureByFuture)(pRspTransfer);
}

void LCCThostFtdcTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	 (*m_fnTraderApiOnRtnFromFutureToBankByFuture)(pRspTransfer);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromBankToFutureByFutureManual)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromFutureToBankByFutureManual)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
{
	 (*m_fnTraderApiOnRtnQueryBankBalanceByFuture)(pNotifyQueryAccount);
}

void LCCThostFtdcTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnBankToFutureByFuture)(pReqTransfer, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnFutureToBankByFuture)(pReqTransfer, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnRepealBankToFutureByFutureManual)(pReqRepeal, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnRepealFutureToBankByFutureManual)(pReqRepeal, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
{
	 (*m_fnTraderApiOnErrRtnQueryBankBalanceByFuture)(pReqQueryAccount, pRspInfo);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromBankToFutureByFuture)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	 (*m_fnTraderApiOnRtnRepealFromFutureToBankByFuture)(pRspRepeal);
}

void LCCThostFtdcTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspFromBankToFutureByFuture)(pReqTransfer, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspFromFutureToBankByFuture)(pReqTransfer, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	 (*m_fnTraderApiOnRspQueryBankAccountMoneyByFuture)(pReqQueryAccount, pRspInfo,  nRequestID,  bIsLast);
}

void LCCThostFtdcTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount)
{
	 (*m_fnTraderApiOnRtnOpenAccountByBank)(pOpenAccount);
}

void LCCThostFtdcTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount)
{
	 (*m_fnTraderApiOnRtnCancelAccountByBank)(pCancelAccount);
}

void LCCThostFtdcTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount)
{
	 (*m_fnTraderApiOnRtnChangeAccountByBank)(pChangeAccount);
}

