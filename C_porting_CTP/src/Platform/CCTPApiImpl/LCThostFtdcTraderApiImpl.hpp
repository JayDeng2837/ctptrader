#ifndef LCTHOSTFTDCTRADERAPIIMPL_HPP
#define LCTHOSTFTDCTRADERAPIIMPL_HPP
#include "ThostFtdcTraderApi.h"
#include "LCThostFtdcTraderApi.h"

class LCCThostFtdcTraderSpi : public CThostFtdcTraderSpi
{
private:

	fnTraderApiOnFrontConnected m_fnTraderApiOnFrontConnected;
	fnTraderApiOnFrontDisconnected m_fnTraderApiOnFrontDisconnected;
	fnTraderApiOnHeartBeatWarning m_fnTraderApiOnHeartBeatWarning;
	fnTraderApiOnRspAuthenticate m_fnTraderApiOnRspAuthenticate;
	fnTraderApiOnRspUserLogin m_fnTraderApiOnRspUserLogin;
	fnTraderApiOnRspUserLogout m_fnTraderApiOnRspUserLogout;
	fnTraderApiOnRspUserPasswordUpdate m_fnTraderApiOnRspUserPasswordUpdate;
	fnTraderApiOnRspTradingAccountPasswordUpdate m_fnTraderApiOnRspTradingAccountPasswordUpdate;
	fnTraderApiOnRspOrderInsert m_fnTraderApiOnRspOrderInsert;
	fnTraderApiOnRspParkedOrderInsert m_fnTraderApiOnRspParkedOrderInsert;
	fnTraderApiOnRspParkedOrderAction m_fnTraderApiOnRspParkedOrderAction;
	fnTraderApiOnRspOrderAction m_fnTraderApiOnRspOrderAction;
	fnTraderApiOnRspQueryMaxOrderVolume m_fnTraderApiOnRspQueryMaxOrderVolume;
	fnTraderApiOnRspSettlementInfoConfirm m_fnTraderApiOnRspSettlementInfoConfirm;
	fnTraderApiOnRspRemoveParkedOrder m_fnTraderApiOnRspRemoveParkedOrder;
	fnTraderApiOnRspRemoveParkedOrderAction m_fnTraderApiOnRspRemoveParkedOrderAction;
	fnTraderApiOnRspExecOrderInsert m_fnTraderApiOnRspExecOrderInsert;
	fnTraderApiOnRspExecOrderAction m_fnTraderApiOnRspExecOrderAction;
	fnTraderApiOnRspForQuoteInsert m_fnTraderApiOnRspForQuoteInsert;
	fnTraderApiOnRspQuoteInsert m_fnTraderApiOnRspQuoteInsert;
	fnTraderApiOnRspQuoteAction m_fnTraderApiOnRspQuoteAction;
	fnTraderApiOnRspQryOrder m_fnTraderApiOnRspQryOrder;
	fnTraderApiOnRspQryTrade m_fnTraderApiOnRspQryTrade;
	fnTraderApiOnRspQryInvestorPosition m_fnTraderApiOnRspQryInvestorPosition;
	fnTraderApiOnRspQryTradingAccount m_fnTraderApiOnRspQryTradingAccount;
	fnTraderApiOnRspQryInvestor m_fnTraderApiOnRspQryInvestor;
	fnTraderApiOnRspQryTradingCode m_fnTraderApiOnRspQryTradingCode;
	fnTraderApiOnRspQryInstrumentMarginRate m_fnTraderApiOnRspQryInstrumentMarginRate;
	fnTraderApiOnRspQryInstrumentCommissionRate m_fnTraderApiOnRspQryInstrumentCommissionRate;
	fnTraderApiOnRspQryExchange m_fnTraderApiOnRspQryExchange;
	fnTraderApiOnRspQryProduct m_fnTraderApiOnRspQryProduct;
	fnTraderApiOnRspQryInstrument m_fnTraderApiOnRspQryInstrument;
	fnTraderApiOnRspQryDepthMarketData m_fnTraderApiOnRspQryDepthMarketData;
	fnTraderApiOnRspQrySettlementInfo m_fnTraderApiOnRspQrySettlementInfo;
	fnTraderApiOnRspQryTransferBank m_fnTraderApiOnRspQryTransferBank;
	fnTraderApiOnRspQryInvestorPositionDetail m_fnTraderApiOnRspQryInvestorPositionDetail;
	fnTraderApiOnRspQryNotice m_fnTraderApiOnRspQryNotice;
	fnTraderApiOnRspQrySettlementInfoConfirm m_fnTraderApiOnRspQrySettlementInfoConfirm;
	fnTraderApiOnRspQryInvestorPositionCombineDetail m_fnTraderApiOnRspQryInvestorPositionCombineDetail;
	fnTraderApiOnRspQryCFMMCTradingAccountKey m_fnTraderApiOnRspQryCFMMCTradingAccountKey;
	fnTraderApiOnRspQryEWarrantOffset m_fnTraderApiOnRspQryEWarrantOffset;
	fnTraderApiOnRspQryInvestorProductGroupMargin m_fnTraderApiOnRspQryInvestorProductGroupMargin;
	fnTraderApiOnRspQryExchangeMarginRate m_fnTraderApiOnRspQryExchangeMarginRate;
	fnTraderApiOnRspQryExchangeMarginRateAdjust m_fnTraderApiOnRspQryExchangeMarginRateAdjust;
	fnTraderApiOnRspQryExchangeRate m_fnTraderApiOnRspQryExchangeRate;
	fnTraderApiOnRspQrySecAgentACIDMap m_fnTraderApiOnRspQrySecAgentACIDMap;
	fnTraderApiOnRspQryOptionInstrTradeCost m_fnTraderApiOnRspQryOptionInstrTradeCost;
	fnTraderApiOnRspQryOptionInstrCommRate m_fnTraderApiOnRspQryOptionInstrCommRate;
	fnTraderApiOnRspQryExecOrder m_fnTraderApiOnRspQryExecOrder;
	fnTraderApiOnRspQryForQuote m_fnTraderApiOnRspQryForQuote;
	fnTraderApiOnRspQryQuote m_fnTraderApiOnRspQryQuote;
	fnTraderApiOnRspQryTransferSerial m_fnTraderApiOnRspQryTransferSerial;
	fnTraderApiOnRspQryAccountregister m_fnTraderApiOnRspQryAccountregister;
	fnTraderApiOnRspError m_fnTraderApiOnRspError;
	fnTraderApiOnRtnOrder m_fnTraderApiOnRtnOrder;
	fnTraderApiOnRtnTrade m_fnTraderApiOnRtnTrade;
	fnTraderApiOnErrRtnOrderInsert m_fnTraderApiOnErrRtnOrderInsert;
	fnTraderApiOnErrRtnOrderAction m_fnTraderApiOnErrRtnOrderAction;
	fnTraderApiOnRtnInstrumentStatus m_fnTraderApiOnRtnInstrumentStatus;
	fnTraderApiOnRtnTradingNotice m_fnTraderApiOnRtnTradingNotice;
	fnTraderApiOnRtnErrorConditionalOrder m_fnTraderApiOnRtnErrorConditionalOrder;
	fnTraderApiOnRtnExecOrder m_fnTraderApiOnRtnExecOrder;
	fnTraderApiOnErrRtnExecOrderInsert m_fnTraderApiOnErrRtnExecOrderInsert;
	fnTraderApiOnErrRtnExecOrderAction m_fnTraderApiOnErrRtnExecOrderAction;
	fnTraderApiOnErrRtnForQuoteInsert m_fnTraderApiOnErrRtnForQuoteInsert;
	fnTraderApiOnRtnQuote m_fnTraderApiOnRtnQuote;
	fnTraderApiOnErrRtnQuoteInsert m_fnTraderApiOnErrRtnQuoteInsert;
	fnTraderApiOnErrRtnQuoteAction m_fnTraderApiOnErrRtnQuoteAction;
	fnTraderApiOnRtnForQuoteRsp m_fnTraderApiOnRtnForQuoteRsp;
	fnTraderApiOnRspQryContractBank m_fnTraderApiOnRspQryContractBank;
	fnTraderApiOnRspQryParkedOrder m_fnTraderApiOnRspQryParkedOrder;
	fnTraderApiOnRspQryParkedOrderAction m_fnTraderApiOnRspQryParkedOrderAction;
	fnTraderApiOnRspQryTradingNotice m_fnTraderApiOnRspQryTradingNotice;
	fnTraderApiOnRspQryBrokerTradingParams m_fnTraderApiOnRspQryBrokerTradingParams;
	fnTraderApiOnRspQryBrokerTradingAlgos m_fnTraderApiOnRspQryBrokerTradingAlgos;
	fnTraderApiOnRtnFromBankToFutureByBank m_fnTraderApiOnRtnFromBankToFutureByBank;
	fnTraderApiOnRtnFromFutureToBankByBank m_fnTraderApiOnRtnFromFutureToBankByBank;
	fnTraderApiOnRtnRepealFromBankToFutureByBank m_fnTraderApiOnRtnRepealFromBankToFutureByBank;
	fnTraderApiOnRtnRepealFromFutureToBankByBank m_fnTraderApiOnRtnRepealFromFutureToBankByBank;
	fnTraderApiOnRtnFromBankToFutureByFuture m_fnTraderApiOnRtnFromBankToFutureByFuture;
	fnTraderApiOnRtnFromFutureToBankByFuture m_fnTraderApiOnRtnFromFutureToBankByFuture;
	fnTraderApiOnRtnRepealFromBankToFutureByFutureManual m_fnTraderApiOnRtnRepealFromBankToFutureByFutureManual;
	fnTraderApiOnRtnRepealFromFutureToBankByFutureManual m_fnTraderApiOnRtnRepealFromFutureToBankByFutureManual;
	fnTraderApiOnRtnQueryBankBalanceByFuture m_fnTraderApiOnRtnQueryBankBalanceByFuture;
	fnTraderApiOnErrRtnBankToFutureByFuture m_fnTraderApiOnErrRtnBankToFutureByFuture;
	fnTraderApiOnErrRtnFutureToBankByFuture m_fnTraderApiOnErrRtnFutureToBankByFuture;
	fnTraderApiOnErrRtnRepealBankToFutureByFutureManual m_fnTraderApiOnErrRtnRepealBankToFutureByFutureManual;
	fnTraderApiOnErrRtnRepealFutureToBankByFutureManual m_fnTraderApiOnErrRtnRepealFutureToBankByFutureManual;
	fnTraderApiOnErrRtnQueryBankBalanceByFuture m_fnTraderApiOnErrRtnQueryBankBalanceByFuture;
	fnTraderApiOnRtnRepealFromBankToFutureByFuture m_fnTraderApiOnRtnRepealFromBankToFutureByFuture;
	fnTraderApiOnRtnRepealFromFutureToBankByFuture m_fnTraderApiOnRtnRepealFromFutureToBankByFuture;
	fnTraderApiOnRspFromBankToFutureByFuture m_fnTraderApiOnRspFromBankToFutureByFuture;
	fnTraderApiOnRspFromFutureToBankByFuture m_fnTraderApiOnRspFromFutureToBankByFuture;
	fnTraderApiOnRspQueryBankAccountMoneyByFuture m_fnTraderApiOnRspQueryBankAccountMoneyByFuture;
	fnTraderApiOnRtnOpenAccountByBank m_fnTraderApiOnRtnOpenAccountByBank;
	fnTraderApiOnRtnCancelAccountByBank m_fnTraderApiOnRtnCancelAccountByBank;
	fnTraderApiOnRtnChangeAccountByBank m_fnTraderApiOnRtnChangeAccountByBank;

public:
	void RegisterTraderApiOnFrontConnectedCallback(fnTraderApiOnFrontConnected _fnTraderApiOnFrontConnected);
	void RegisterTraderApiOnFrontDisconnectedCallback(fnTraderApiOnFrontDisconnected _fnTraderApiOnFrontDisconnected);
	void RegisterTraderApiOnHeartBeatWarningCallback(fnTraderApiOnHeartBeatWarning _fnTraderApiOnHeartBeatWarning);
	void RegisterTraderApiOnRspAuthenticateCallback(fnTraderApiOnRspAuthenticate _fnTraderApiOnRspAuthenticate);
	void RegisterTraderApiOnRspUserLoginCallback(fnTraderApiOnRspUserLogin _fnTraderApiOnRspUserLogin);
	void RegisterTraderApiOnRspUserLogoutCallback(fnTraderApiOnRspUserLogout _fnTraderApiOnRspUserLogout);
	void RegisterTraderApiOnRspUserPasswordUpdateCallback(fnTraderApiOnRspUserPasswordUpdate _fnTraderApiOnRspUserPasswordUpdate);
	void RegisterTraderApiOnRspTradingAccountPasswordUpdateCallback(fnTraderApiOnRspTradingAccountPasswordUpdate _fnTraderApiOnRspTradingAccountPasswordUpdate);
	void RegisterTraderApiOnRspOrderInsertCallback(fnTraderApiOnRspOrderInsert _fnTraderApiOnRspOrderInsert);
	void RegisterTraderApiOnRspParkedOrderInsertCallback(fnTraderApiOnRspParkedOrderInsert _fnTraderApiOnRspParkedOrderInsert);
	void RegisterTraderApiOnRspParkedOrderActionCallback(fnTraderApiOnRspParkedOrderAction _fnTraderApiOnRspParkedOrderAction);
	void RegisterTraderApiOnRspOrderActionCallback(fnTraderApiOnRspOrderAction _fnTraderApiOnRspOrderAction);
	void RegisterTraderApiOnRspQueryMaxOrderVolumeCallback(fnTraderApiOnRspQueryMaxOrderVolume _fnTraderApiOnRspQueryMaxOrderVolume);
	void RegisterTraderApiOnRspSettlementInfoConfirmCallback(fnTraderApiOnRspSettlementInfoConfirm _fnTraderApiOnRspSettlementInfoConfirm);
	void RegisterTraderApiOnRspRemoveParkedOrderCallback(fnTraderApiOnRspRemoveParkedOrder _fnTraderApiOnRspRemoveParkedOrder);
	void RegisterTraderApiOnRspRemoveParkedOrderActionCallback(fnTraderApiOnRspRemoveParkedOrderAction _fnTraderApiOnRspRemoveParkedOrderAction);
	void RegisterTraderApiOnRspExecOrderInsertCallback(fnTraderApiOnRspExecOrderInsert _fnTraderApiOnRspExecOrderInsert);
	void RegisterTraderApiOnRspExecOrderActionCallback(fnTraderApiOnRspExecOrderAction _fnTraderApiOnRspExecOrderAction);
	void RegisterTraderApiOnRspForQuoteInsertCallback(fnTraderApiOnRspForQuoteInsert _fnTraderApiOnRspForQuoteInsert);
	void RegisterTraderApiOnRspQuoteInsertCallback(fnTraderApiOnRspQuoteInsert _fnTraderApiOnRspQuoteInsert);
	void RegisterTraderApiOnRspQuoteActionCallback(fnTraderApiOnRspQuoteAction _fnTraderApiOnRspQuoteAction);
	void RegisterTraderApiOnRspQryOrderCallback(fnTraderApiOnRspQryOrder _fnTraderApiOnRspQryOrder);
	void RegisterTraderApiOnRspQryTradeCallback(fnTraderApiOnRspQryTrade _fnTraderApiOnRspQryTrade);
	void RegisterTraderApiOnRspQryInvestorPositionCallback(fnTraderApiOnRspQryInvestorPosition _fnTraderApiOnRspQryInvestorPosition);
	void RegisterTraderApiOnRspQryTradingAccountCallback(fnTraderApiOnRspQryTradingAccount _fnTraderApiOnRspQryTradingAccount);
	void RegisterTraderApiOnRspQryInvestorCallback(fnTraderApiOnRspQryInvestor _fnTraderApiOnRspQryInvestor);
	void RegisterTraderApiOnRspQryTradingCodeCallback(fnTraderApiOnRspQryTradingCode _fnTraderApiOnRspQryTradingCode);
	void RegisterTraderApiOnRspQryInstrumentMarginRateCallback(fnTraderApiOnRspQryInstrumentMarginRate _fnTraderApiOnRspQryInstrumentMarginRate);
	void RegisterTraderApiOnRspQryInstrumentCommissionRateCallback(fnTraderApiOnRspQryInstrumentCommissionRate _fnTraderApiOnRspQryInstrumentCommissionRate);
	void RegisterTraderApiOnRspQryExchangeCallback(fnTraderApiOnRspQryExchange _fnTraderApiOnRspQryExchange);
	void RegisterTraderApiOnRspQryProductCallback(fnTraderApiOnRspQryProduct _fnTraderApiOnRspQryProduct);
	void RegisterTraderApiOnRspQryInstrumentCallback(fnTraderApiOnRspQryInstrument _fnTraderApiOnRspQryInstrument);
	void RegisterTraderApiOnRspQryDepthMarketDataCallback(fnTraderApiOnRspQryDepthMarketData _fnTraderApiOnRspQryDepthMarketData);
	void RegisterTraderApiOnRspQrySettlementInfoCallback(fnTraderApiOnRspQrySettlementInfo _fnTraderApiOnRspQrySettlementInfo);
	void RegisterTraderApiOnRspQryTransferBankCallback(fnTraderApiOnRspQryTransferBank _fnTraderApiOnRspQryTransferBank);
	void RegisterTraderApiOnRspQryInvestorPositionDetailCallback(fnTraderApiOnRspQryInvestorPositionDetail _fnTraderApiOnRspQryInvestorPositionDetail);
	void RegisterTraderApiOnRspQryNoticeCallback(fnTraderApiOnRspQryNotice _fnTraderApiOnRspQryNotice);
	void RegisterTraderApiOnRspQrySettlementInfoConfirmCallback(fnTraderApiOnRspQrySettlementInfoConfirm _fnTraderApiOnRspQrySettlementInfoConfirm);
	void RegisterTraderApiOnRspQryInvestorPositionCombineDetailCallback(fnTraderApiOnRspQryInvestorPositionCombineDetail _fnTraderApiOnRspQryInvestorPositionCombineDetail);
	void RegisterTraderApiOnRspQryCFMMCTradingAccountKeyCallback(fnTraderApiOnRspQryCFMMCTradingAccountKey _fnTraderApiOnRspQryCFMMCTradingAccountKey);
	void RegisterTraderApiOnRspQryEWarrantOffsetCallback(fnTraderApiOnRspQryEWarrantOffset _fnTraderApiOnRspQryEWarrantOffset);
	void RegisterTraderApiOnRspQryInvestorProductGroupMarginCallback(fnTraderApiOnRspQryInvestorProductGroupMargin _fnTraderApiOnRspQryInvestorProductGroupMargin);
	void RegisterTraderApiOnRspQryExchangeMarginRateCallback(fnTraderApiOnRspQryExchangeMarginRate _fnTraderApiOnRspQryExchangeMarginRate);
	void RegisterTraderApiOnRspQryExchangeMarginRateAdjustCallback(fnTraderApiOnRspQryExchangeMarginRateAdjust _fnTraderApiOnRspQryExchangeMarginRateAdjust);
	void RegisterTraderApiOnRspQryExchangeRateCallback(fnTraderApiOnRspQryExchangeRate _fnTraderApiOnRspQryExchangeRate);
	void RegisterTraderApiOnRspQrySecAgentACIDMapCallback(fnTraderApiOnRspQrySecAgentACIDMap _fnTraderApiOnRspQrySecAgentACIDMap);
	void RegisterTraderApiOnRspQryOptionInstrTradeCostCallback(fnTraderApiOnRspQryOptionInstrTradeCost _fnTraderApiOnRspQryOptionInstrTradeCost);
	void RegisterTraderApiOnRspQryOptionInstrCommRateCallback(fnTraderApiOnRspQryOptionInstrCommRate _fnTraderApiOnRspQryOptionInstrCommRate);
	void RegisterTraderApiOnRspQryExecOrderCallback(fnTraderApiOnRspQryExecOrder _fnTraderApiOnRspQryExecOrder);
	void RegisterTraderApiOnRspQryForQuoteCallback(fnTraderApiOnRspQryForQuote _fnTraderApiOnRspQryForQuote);
	void RegisterTraderApiOnRspQryQuoteCallback(fnTraderApiOnRspQryQuote _fnTraderApiOnRspQryQuote);
	void RegisterTraderApiOnRspQryTransferSerialCallback(fnTraderApiOnRspQryTransferSerial _fnTraderApiOnRspQryTransferSerial);
	void RegisterTraderApiOnRspQryAccountregisterCallback(fnTraderApiOnRspQryAccountregister _fnTraderApiOnRspQryAccountregister);
	void RegisterTraderApiOnRspErrorCallback(fnTraderApiOnRspError _fnTraderApiOnRspError);
	void RegisterTraderApiOnRtnOrderCallback(fnTraderApiOnRtnOrder _fnTraderApiOnRtnOrder);
	void RegisterTraderApiOnRtnTradeCallback(fnTraderApiOnRtnTrade _fnTraderApiOnRtnTrade);
	void RegisterTraderApiOnErrRtnOrderInsertCallback(fnTraderApiOnErrRtnOrderInsert _fnTraderApiOnErrRtnOrderInsert);
	void RegisterTraderApiOnErrRtnOrderActionCallback(fnTraderApiOnErrRtnOrderAction _fnTraderApiOnErrRtnOrderAction);
	void RegisterTraderApiOnRtnInstrumentStatusCallback(fnTraderApiOnRtnInstrumentStatus _fnTraderApiOnRtnInstrumentStatus);
	void RegisterTraderApiOnRtnTradingNoticeCallback(fnTraderApiOnRtnTradingNotice _fnTraderApiOnRtnTradingNotice);
	void RegisterTraderApiOnRtnErrorConditionalOrderCallback(fnTraderApiOnRtnErrorConditionalOrder _fnTraderApiOnRtnErrorConditionalOrder);
	void RegisterTraderApiOnRtnExecOrderCallback(fnTraderApiOnRtnExecOrder _fnTraderApiOnRtnExecOrder);
	void RegisterTraderApiOnErrRtnExecOrderInsertCallback(fnTraderApiOnErrRtnExecOrderInsert _fnTraderApiOnErrRtnExecOrderInsert);
	void RegisterTraderApiOnErrRtnExecOrderActionCallback(fnTraderApiOnErrRtnExecOrderAction _fnTraderApiOnErrRtnExecOrderAction);
	void RegisterTraderApiOnErrRtnForQuoteInsertCallback(fnTraderApiOnErrRtnForQuoteInsert _fnTraderApiOnErrRtnForQuoteInsert);
	void RegisterTraderApiOnRtnQuoteCallback(fnTraderApiOnRtnQuote _fnTraderApiOnRtnQuote);
	void RegisterTraderApiOnErrRtnQuoteInsertCallback(fnTraderApiOnErrRtnQuoteInsert _fnTraderApiOnErrRtnQuoteInsert);
	void RegisterTraderApiOnErrRtnQuoteActionCallback(fnTraderApiOnErrRtnQuoteAction _fnTraderApiOnErrRtnQuoteAction);
	void RegisterTraderApiOnRtnForQuoteRspCallback(fnTraderApiOnRtnForQuoteRsp _fnTraderApiOnRtnForQuoteRsp);
	void RegisterTraderApiOnRspQryContractBankCallback(fnTraderApiOnRspQryContractBank _fnTraderApiOnRspQryContractBank);
	void RegisterTraderApiOnRspQryParkedOrderCallback(fnTraderApiOnRspQryParkedOrder _fnTraderApiOnRspQryParkedOrder);
	void RegisterTraderApiOnRspQryParkedOrderActionCallback(fnTraderApiOnRspQryParkedOrderAction _fnTraderApiOnRspQryParkedOrderAction);
	void RegisterTraderApiOnRspQryTradingNoticeCallback(fnTraderApiOnRspQryTradingNotice _fnTraderApiOnRspQryTradingNotice);
	void RegisterTraderApiOnRspQryBrokerTradingParamsCallback(fnTraderApiOnRspQryBrokerTradingParams _fnTraderApiOnRspQryBrokerTradingParams);
	void RegisterTraderApiOnRspQryBrokerTradingAlgosCallback(fnTraderApiOnRspQryBrokerTradingAlgos _fnTraderApiOnRspQryBrokerTradingAlgos);
	void RegisterTraderApiOnRtnFromBankToFutureByBankCallback(fnTraderApiOnRtnFromBankToFutureByBank _fnTraderApiOnRtnFromBankToFutureByBank);
	void RegisterTraderApiOnRtnFromFutureToBankByBankCallback(fnTraderApiOnRtnFromFutureToBankByBank _fnTraderApiOnRtnFromFutureToBankByBank);
	void RegisterTraderApiOnRtnRepealFromBankToFutureByBankCallback(fnTraderApiOnRtnRepealFromBankToFutureByBank _fnTraderApiOnRtnRepealFromBankToFutureByBank);
	void RegisterTraderApiOnRtnRepealFromFutureToBankByBankCallback(fnTraderApiOnRtnRepealFromFutureToBankByBank _fnTraderApiOnRtnRepealFromFutureToBankByBank);
	void RegisterTraderApiOnRtnFromBankToFutureByFutureCallback(fnTraderApiOnRtnFromBankToFutureByFuture _fnTraderApiOnRtnFromBankToFutureByFuture);
	void RegisterTraderApiOnRtnFromFutureToBankByFutureCallback(fnTraderApiOnRtnFromFutureToBankByFuture _fnTraderApiOnRtnFromFutureToBankByFuture);
	void RegisterTraderApiOnRtnRepealFromBankToFutureByFutureManualCallback(fnTraderApiOnRtnRepealFromBankToFutureByFutureManual _fnTraderApiOnRtnRepealFromBankToFutureByFutureManual);
	void RegisterTraderApiOnRtnRepealFromFutureToBankByFutureManualCallback(fnTraderApiOnRtnRepealFromFutureToBankByFutureManual _fnTraderApiOnRtnRepealFromFutureToBankByFutureManual);
	void RegisterTraderApiOnRtnQueryBankBalanceByFutureCallback(fnTraderApiOnRtnQueryBankBalanceByFuture _fnTraderApiOnRtnQueryBankBalanceByFuture);
	void RegisterTraderApiOnErrRtnBankToFutureByFutureCallback(fnTraderApiOnErrRtnBankToFutureByFuture _fnTraderApiOnErrRtnBankToFutureByFuture);
	void RegisterTraderApiOnErrRtnFutureToBankByFutureCallback(fnTraderApiOnErrRtnFutureToBankByFuture _fnTraderApiOnErrRtnFutureToBankByFuture);
	void RegisterTraderApiOnErrRtnRepealBankToFutureByFutureManualCallback(fnTraderApiOnErrRtnRepealBankToFutureByFutureManual _fnTraderApiOnErrRtnRepealBankToFutureByFutureManual);
	void RegisterTraderApiOnErrRtnRepealFutureToBankByFutureManualCallback(fnTraderApiOnErrRtnRepealFutureToBankByFutureManual _fnTraderApiOnErrRtnRepealFutureToBankByFutureManual);
	void RegisterTraderApiOnErrRtnQueryBankBalanceByFutureCallback(fnTraderApiOnErrRtnQueryBankBalanceByFuture _fnTraderApiOnErrRtnQueryBankBalanceByFuture);
	void RegisterTraderApiOnRtnRepealFromBankToFutureByFutureCallback(fnTraderApiOnRtnRepealFromBankToFutureByFuture _fnTraderApiOnRtnRepealFromBankToFutureByFuture);
	void RegisterTraderApiOnRtnRepealFromFutureToBankByFutureCallback(fnTraderApiOnRtnRepealFromFutureToBankByFuture _fnTraderApiOnRtnRepealFromFutureToBankByFuture);
	void RegisterTraderApiOnRspFromBankToFutureByFutureCallback(fnTraderApiOnRspFromBankToFutureByFuture _fnTraderApiOnRspFromBankToFutureByFuture);
	void RegisterTraderApiOnRspFromFutureToBankByFutureCallback(fnTraderApiOnRspFromFutureToBankByFuture _fnTraderApiOnRspFromFutureToBankByFuture);
	void RegisterTraderApiOnRspQueryBankAccountMoneyByFutureCallback(fnTraderApiOnRspQueryBankAccountMoneyByFuture _fnTraderApiOnRspQueryBankAccountMoneyByFuture);
	void RegisterTraderApiOnRtnOpenAccountByBankCallback(fnTraderApiOnRtnOpenAccountByBank _fnTraderApiOnRtnOpenAccountByBank);
	void RegisterTraderApiOnRtnCancelAccountByBankCallback(fnTraderApiOnRtnCancelAccountByBank _fnTraderApiOnRtnCancelAccountByBank);
	void RegisterTraderApiOnRtnChangeAccountByBankCallback(fnTraderApiOnRtnChangeAccountByBank _fnTraderApiOnRtnChangeAccountByBank);

public:
	virtual void OnFrontConnected();
	virtual void OnFrontDisconnected(int nReason);
	virtual void OnHeartBeatWarning(int nTimeLapse);
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote);
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);
	virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);
	LCCThostFtdcTraderSpi();
	~LCCThostFtdcTraderSpi();

};

LCCThostFtdcTraderSpi * GetLCCThostFtdcTraderSpi(void * pLC_Spi);

CThostFtdcTraderApi * GetCThostFtdcTraderApi(void * pLC_Api);

#endif