#include "LCThostFtdcTraderApi.h"
#include "LCThostFtdcTraderApiImpl.hpp"

void * CreateLCCThostFtdcTraderSpi()
{
	return (void *)(new LCCThostFtdcTraderSpi);
}

void ReleaseLCCThostFtdcTraderSpi(void * * pLC_Spi)
{
	if (*pLC_Spi != NULL)
	{
		delete *pLC_Spi;
		*pLC_Spi = NULL;
	}
}

void RegisterTraderApiOnFrontConnectedCallback(void * pLC_Spi, fnTraderApiOnFrontConnected pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnFrontConnectedCallback(pCallback);
	}
}
void RegisterTraderApiOnFrontDisconnectedCallback(void * pLC_Spi, fnTraderApiOnFrontDisconnected pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnFrontDisconnectedCallback(pCallback);
	}
}
void RegisterTraderApiOnHeartBeatWarningCallback(void * pLC_Spi, fnTraderApiOnHeartBeatWarning pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnHeartBeatWarningCallback(pCallback);
	}
}
void RegisterTraderApiOnRspAuthenticateCallback(void * pLC_Spi, fnTraderApiOnRspAuthenticate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspAuthenticateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspUserLoginCallback(void * pLC_Spi, fnTraderApiOnRspUserLogin pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspUserLoginCallback(pCallback);
	}
}
void RegisterTraderApiOnRspUserLogoutCallback(void * pLC_Spi, fnTraderApiOnRspUserLogout pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspUserLogoutCallback(pCallback);
	}
}
void RegisterTraderApiOnRspUserPasswordUpdateCallback(void * pLC_Spi, fnTraderApiOnRspUserPasswordUpdate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspUserPasswordUpdateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspTradingAccountPasswordUpdateCallback(void * pLC_Spi, fnTraderApiOnRspTradingAccountPasswordUpdate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspTradingAccountPasswordUpdateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspOrderInsertCallback(void * pLC_Spi, fnTraderApiOnRspOrderInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspOrderInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRspParkedOrderInsertCallback(void * pLC_Spi, fnTraderApiOnRspParkedOrderInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspParkedOrderInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRspParkedOrderActionCallback(void * pLC_Spi, fnTraderApiOnRspParkedOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspParkedOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspOrderActionCallback(void * pLC_Spi, fnTraderApiOnRspOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQueryMaxOrderVolumeCallback(void * pLC_Spi, fnTraderApiOnRspQueryMaxOrderVolume pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQueryMaxOrderVolumeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspSettlementInfoConfirmCallback(void * pLC_Spi, fnTraderApiOnRspSettlementInfoConfirm pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspSettlementInfoConfirmCallback(pCallback);
	}
}
void RegisterTraderApiOnRspRemoveParkedOrderCallback(void * pLC_Spi, fnTraderApiOnRspRemoveParkedOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspRemoveParkedOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRspRemoveParkedOrderActionCallback(void * pLC_Spi, fnTraderApiOnRspRemoveParkedOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspRemoveParkedOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspExecOrderInsertCallback(void * pLC_Spi, fnTraderApiOnRspExecOrderInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspExecOrderInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRspExecOrderActionCallback(void * pLC_Spi, fnTraderApiOnRspExecOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspExecOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspForQuoteInsertCallback(void * pLC_Spi, fnTraderApiOnRspForQuoteInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspForQuoteInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQuoteInsertCallback(void * pLC_Spi, fnTraderApiOnRspQuoteInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQuoteInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQuoteActionCallback(void * pLC_Spi, fnTraderApiOnRspQuoteAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQuoteActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryOrderCallback(void * pLC_Spi, fnTraderApiOnRspQryOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTradeCallback(void * pLC_Spi, fnTraderApiOnRspQryTrade pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTradeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInvestorPositionCallback(void * pLC_Spi, fnTraderApiOnRspQryInvestorPosition pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInvestorPositionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTradingAccountCallback(void * pLC_Spi, fnTraderApiOnRspQryTradingAccount pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTradingAccountCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInvestorCallback(void * pLC_Spi, fnTraderApiOnRspQryInvestor pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInvestorCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTradingCodeCallback(void * pLC_Spi, fnTraderApiOnRspQryTradingCode pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTradingCodeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInstrumentMarginRateCallback(void * pLC_Spi, fnTraderApiOnRspQryInstrumentMarginRate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInstrumentMarginRateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInstrumentCommissionRateCallback(void * pLC_Spi, fnTraderApiOnRspQryInstrumentCommissionRate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInstrumentCommissionRateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryExchangeCallback(void * pLC_Spi, fnTraderApiOnRspQryExchange pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryExchangeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryProductCallback(void * pLC_Spi, fnTraderApiOnRspQryProduct pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryProductCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInstrumentCallback(void * pLC_Spi, fnTraderApiOnRspQryInstrument pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInstrumentCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryDepthMarketDataCallback(void * pLC_Spi, fnTraderApiOnRspQryDepthMarketData pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryDepthMarketDataCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQrySettlementInfoCallback(void * pLC_Spi, fnTraderApiOnRspQrySettlementInfo pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQrySettlementInfoCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTransferBankCallback(void * pLC_Spi, fnTraderApiOnRspQryTransferBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTransferBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInvestorPositionDetailCallback(void * pLC_Spi, fnTraderApiOnRspQryInvestorPositionDetail pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInvestorPositionDetailCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryNoticeCallback(void * pLC_Spi, fnTraderApiOnRspQryNotice pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryNoticeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQrySettlementInfoConfirmCallback(void * pLC_Spi, fnTraderApiOnRspQrySettlementInfoConfirm pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQrySettlementInfoConfirmCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInvestorPositionCombineDetailCallback(void * pLC_Spi, fnTraderApiOnRspQryInvestorPositionCombineDetail pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInvestorPositionCombineDetailCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryCFMMCTradingAccountKeyCallback(void * pLC_Spi, fnTraderApiOnRspQryCFMMCTradingAccountKey pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryCFMMCTradingAccountKeyCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryEWarrantOffsetCallback(void * pLC_Spi, fnTraderApiOnRspQryEWarrantOffset pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryEWarrantOffsetCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryInvestorProductGroupMarginCallback(void * pLC_Spi, fnTraderApiOnRspQryInvestorProductGroupMargin pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryInvestorProductGroupMarginCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryExchangeMarginRateCallback(void * pLC_Spi, fnTraderApiOnRspQryExchangeMarginRate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryExchangeMarginRateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryExchangeMarginRateAdjustCallback(void * pLC_Spi, fnTraderApiOnRspQryExchangeMarginRateAdjust pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryExchangeMarginRateAdjustCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryExchangeRateCallback(void * pLC_Spi, fnTraderApiOnRspQryExchangeRate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryExchangeRateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQrySecAgentACIDMapCallback(void * pLC_Spi, fnTraderApiOnRspQrySecAgentACIDMap pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQrySecAgentACIDMapCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryOptionInstrTradeCostCallback(void * pLC_Spi, fnTraderApiOnRspQryOptionInstrTradeCost pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryOptionInstrTradeCostCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryOptionInstrCommRateCallback(void * pLC_Spi, fnTraderApiOnRspQryOptionInstrCommRate pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryOptionInstrCommRateCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryExecOrderCallback(void * pLC_Spi, fnTraderApiOnRspQryExecOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryExecOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryForQuoteCallback(void * pLC_Spi, fnTraderApiOnRspQryForQuote pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryForQuoteCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryQuoteCallback(void * pLC_Spi, fnTraderApiOnRspQryQuote pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryQuoteCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTransferSerialCallback(void * pLC_Spi, fnTraderApiOnRspQryTransferSerial pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTransferSerialCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryAccountregisterCallback(void * pLC_Spi, fnTraderApiOnRspQryAccountregister pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryAccountregisterCallback(pCallback);
	}
}
void RegisterTraderApiOnRspErrorCallback(void * pLC_Spi, fnTraderApiOnRspError pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspErrorCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnOrderCallback(void * pLC_Spi, fnTraderApiOnRtnOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnTradeCallback(void * pLC_Spi, fnTraderApiOnRtnTrade pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnTradeCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnOrderInsertCallback(void * pLC_Spi, fnTraderApiOnErrRtnOrderInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnOrderInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnOrderActionCallback(void * pLC_Spi, fnTraderApiOnErrRtnOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnInstrumentStatusCallback(void * pLC_Spi, fnTraderApiOnRtnInstrumentStatus pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnInstrumentStatusCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnTradingNoticeCallback(void * pLC_Spi, fnTraderApiOnRtnTradingNotice pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnTradingNoticeCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnErrorConditionalOrderCallback(void * pLC_Spi, fnTraderApiOnRtnErrorConditionalOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnErrorConditionalOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnExecOrderCallback(void * pLC_Spi, fnTraderApiOnRtnExecOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnExecOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnExecOrderInsertCallback(void * pLC_Spi, fnTraderApiOnErrRtnExecOrderInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnExecOrderInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnExecOrderActionCallback(void * pLC_Spi, fnTraderApiOnErrRtnExecOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnExecOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnForQuoteInsertCallback(void * pLC_Spi, fnTraderApiOnErrRtnForQuoteInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnForQuoteInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnQuoteCallback(void * pLC_Spi, fnTraderApiOnRtnQuote pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnQuoteCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnQuoteInsertCallback(void * pLC_Spi, fnTraderApiOnErrRtnQuoteInsert pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnQuoteInsertCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnQuoteActionCallback(void * pLC_Spi, fnTraderApiOnErrRtnQuoteAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnQuoteActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnForQuoteRspCallback(void * pLC_Spi, fnTraderApiOnRtnForQuoteRsp pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnForQuoteRspCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryContractBankCallback(void * pLC_Spi, fnTraderApiOnRspQryContractBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryContractBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryParkedOrderCallback(void * pLC_Spi, fnTraderApiOnRspQryParkedOrder pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryParkedOrderCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryParkedOrderActionCallback(void * pLC_Spi, fnTraderApiOnRspQryParkedOrderAction pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryParkedOrderActionCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryTradingNoticeCallback(void * pLC_Spi, fnTraderApiOnRspQryTradingNotice pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryTradingNoticeCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryBrokerTradingParamsCallback(void * pLC_Spi, fnTraderApiOnRspQryBrokerTradingParams pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryBrokerTradingParamsCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQryBrokerTradingAlgosCallback(void * pLC_Spi, fnTraderApiOnRspQryBrokerTradingAlgos pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQryBrokerTradingAlgosCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnFromBankToFutureByBankCallback(void * pLC_Spi, fnTraderApiOnRtnFromBankToFutureByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnFromBankToFutureByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnFromFutureToBankByBankCallback(void * pLC_Spi, fnTraderApiOnRtnFromFutureToBankByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnFromFutureToBankByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromBankToFutureByBankCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromBankToFutureByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromBankToFutureByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromFutureToBankByBankCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromFutureToBankByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromFutureToBankByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnFromBankToFutureByFutureCallback(void * pLC_Spi, fnTraderApiOnRtnFromBankToFutureByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnFromBankToFutureByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnFromFutureToBankByFutureCallback(void * pLC_Spi, fnTraderApiOnRtnFromFutureToBankByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnFromFutureToBankByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromBankToFutureByFutureManualCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromBankToFutureByFutureManual pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromBankToFutureByFutureManualCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromFutureToBankByFutureManualCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromFutureToBankByFutureManual pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromFutureToBankByFutureManualCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnQueryBankBalanceByFutureCallback(void * pLC_Spi, fnTraderApiOnRtnQueryBankBalanceByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnQueryBankBalanceByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnBankToFutureByFutureCallback(void * pLC_Spi, fnTraderApiOnErrRtnBankToFutureByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnBankToFutureByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnFutureToBankByFutureCallback(void * pLC_Spi, fnTraderApiOnErrRtnFutureToBankByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnFutureToBankByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnRepealBankToFutureByFutureManualCallback(void * pLC_Spi, fnTraderApiOnErrRtnRepealBankToFutureByFutureManual pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnRepealBankToFutureByFutureManualCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnRepealFutureToBankByFutureManualCallback(void * pLC_Spi, fnTraderApiOnErrRtnRepealFutureToBankByFutureManual pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnRepealFutureToBankByFutureManualCallback(pCallback);
	}
}
void RegisterTraderApiOnErrRtnQueryBankBalanceByFutureCallback(void * pLC_Spi, fnTraderApiOnErrRtnQueryBankBalanceByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnErrRtnQueryBankBalanceByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromBankToFutureByFutureCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromBankToFutureByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromBankToFutureByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnRepealFromFutureToBankByFutureCallback(void * pLC_Spi, fnTraderApiOnRtnRepealFromFutureToBankByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnRepealFromFutureToBankByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRspFromBankToFutureByFutureCallback(void * pLC_Spi, fnTraderApiOnRspFromBankToFutureByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspFromBankToFutureByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRspFromFutureToBankByFutureCallback(void * pLC_Spi, fnTraderApiOnRspFromFutureToBankByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspFromFutureToBankByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRspQueryBankAccountMoneyByFutureCallback(void * pLC_Spi, fnTraderApiOnRspQueryBankAccountMoneyByFuture pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRspQueryBankAccountMoneyByFutureCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnOpenAccountByBankCallback(void * pLC_Spi, fnTraderApiOnRtnOpenAccountByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnOpenAccountByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnCancelAccountByBankCallback(void * pLC_Spi, fnTraderApiOnRtnCancelAccountByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnCancelAccountByBankCallback(pCallback);
	}
}
void RegisterTraderApiOnRtnChangeAccountByBankCallback(void * pLC_Spi, fnTraderApiOnRtnChangeAccountByBank pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcTraderSpi(pLC_Spi))->RegisterTraderApiOnRtnChangeAccountByBankCallback(pCallback);
	}
}
LC_CTP_API void * CreateLCCThostFtdcTraderApi(const char * con_path)
{
	return (void *)(CThostFtdcTraderApi::CreateFtdcTraderApi(con_path));
}

void ReleaseLCCThostFtdcTraderApi(void * * pLC_Api)
{
	if (*pLC_Api != NULL)
	{
		delete *pLC_Api;
		*pLC_Api = NULL;
	}
}

LC_CTP_API void TraderApiRelease(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->Release();
	}
}

LC_CTP_API void TraderApiInit(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->Init();
	}
}

LC_CTP_API int TraderApiJoin(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->Join();
	}
	return -1;
}

LC_CTP_API void TraderApiRegisterFront(void* pLC_Api, char *pszFrontAddress)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->RegisterFront(pszFrontAddress);
	}
}

LC_CTP_API void TraderApiRegisterNameServer(void* pLC_Api, char *pszNsAddress)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->RegisterNameServer(pszNsAddress);
	}
}

LC_CTP_API void TraderApiRegisterFensUserInfo(void* pLC_Api, struct CThostFtdcFensUserInfoField * pFensUserInfo)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->RegisterFensUserInfo( pFensUserInfo);
	}
}

LC_CTP_API void TraderApiRegisterSpi(void * pLC_Api, void * pLC_Spi)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->RegisterSpi(GetLCCThostFtdcTraderSpi(pLC_Spi));
	}
}

LC_CTP_API void TraderApiSubscribePrivateTopic(void* pLC_Api, THOST_TE_RESUME_TYPE nResumeType)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->SubscribePrivateTopic( nResumeType);
	}
}

LC_CTP_API void TraderApiSubscribePublicTopic(void* pLC_Api, THOST_TE_RESUME_TYPE nResumeType)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcTraderApi(pLC_Api))->SubscribePublicTopic( nResumeType);
	}
}

LC_CTP_API int TraderApiReqAuthenticate(void* pLC_Api, struct CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqAuthenticate(pReqAuthenticateField,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqUserLogin(void* pLC_Api, struct CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqUserLogin(pReqUserLoginField,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqUserLogout(void* pLC_Api, struct CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqUserLogout(pUserLogout,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqUserPasswordUpdate(void* pLC_Api, struct CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqUserPasswordUpdate(pUserPasswordUpdate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqTradingAccountPasswordUpdate(void* pLC_Api, struct CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqOrderInsert(void* pLC_Api, struct CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqOrderInsert(pInputOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqParkedOrderInsert(void* pLC_Api, struct CThostFtdcParkedOrderField *pParkedOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqParkedOrderInsert(pParkedOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqParkedOrderAction(void* pLC_Api, struct CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqParkedOrderAction(pParkedOrderAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqOrderAction(void* pLC_Api, struct CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqOrderAction(pInputOrderAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQueryMaxOrderVolume(void* pLC_Api, struct CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQueryMaxOrderVolume(pQueryMaxOrderVolume,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqSettlementInfoConfirm(void* pLC_Api, struct CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqSettlementInfoConfirm(pSettlementInfoConfirm,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqRemoveParkedOrder(void* pLC_Api, struct CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqRemoveParkedOrder(pRemoveParkedOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqRemoveParkedOrderAction(void* pLC_Api, struct CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqExecOrderInsert(void* pLC_Api, struct CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqExecOrderInsert(pInputExecOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqExecOrderAction(void* pLC_Api, struct CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqExecOrderAction(pInputExecOrderAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqForQuoteInsert(void* pLC_Api, struct CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqForQuoteInsert(pInputForQuote,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQuoteInsert(void* pLC_Api, struct CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQuoteInsert(pInputQuote,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQuoteAction(void* pLC_Api, struct CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQuoteAction(pInputQuoteAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryOrder(void* pLC_Api, struct CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryOrder(pQryOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTrade(void* pLC_Api, struct CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTrade(pQryTrade,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInvestorPosition(void* pLC_Api, struct CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInvestorPosition(pQryInvestorPosition,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTradingAccount(void* pLC_Api, struct CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTradingAccount(pQryTradingAccount,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInvestor(void* pLC_Api, struct CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInvestor(pQryInvestor,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTradingCode(void* pLC_Api, struct CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTradingCode(pQryTradingCode,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInstrumentMarginRate(void* pLC_Api, struct CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInstrumentCommissionRate(void* pLC_Api, struct CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryExchange(void* pLC_Api, struct CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryExchange(pQryExchange,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryProduct(void* pLC_Api, struct CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryProduct(pQryProduct,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInstrument(void* pLC_Api, struct CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInstrument(pQryInstrument,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryDepthMarketData(void* pLC_Api, struct CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryDepthMarketData(pQryDepthMarketData,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQrySettlementInfo(void* pLC_Api, struct CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQrySettlementInfo(pQrySettlementInfo,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTransferBank(void* pLC_Api, struct CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTransferBank(pQryTransferBank,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInvestorPositionDetail(void* pLC_Api, struct CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryNotice(void* pLC_Api, struct CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryNotice(pQryNotice,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQrySettlementInfoConfirm(void* pLC_Api, struct CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInvestorPositionCombineDetail(void* pLC_Api, struct CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryCFMMCTradingAccountKey(void* pLC_Api, struct CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryEWarrantOffset(void* pLC_Api, struct CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryEWarrantOffset(pQryEWarrantOffset,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryInvestorProductGroupMargin(void* pLC_Api, struct CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryExchangeMarginRate(void* pLC_Api, struct CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryExchangeMarginRate(pQryExchangeMarginRate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryExchangeMarginRateAdjust(void* pLC_Api, struct CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryExchangeRate(void* pLC_Api, struct CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryExchangeRate(pQryExchangeRate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQrySecAgentACIDMap(void* pLC_Api, struct CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryOptionInstrTradeCost(void* pLC_Api, struct CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryOptionInstrCommRate(void* pLC_Api, struct CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryExecOrder(void* pLC_Api, struct CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryExecOrder(pQryExecOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryForQuote(void* pLC_Api, struct CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryForQuote(pQryForQuote,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryQuote(void* pLC_Api, struct CThostFtdcQryQuoteField *pQryQuote, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryQuote(pQryQuote,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTransferSerial(void* pLC_Api, struct CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTransferSerial(pQryTransferSerial,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryAccountregister(void* pLC_Api, struct CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryAccountregister(pQryAccountregister,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryContractBank(void* pLC_Api, struct CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryContractBank(pQryContractBank,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryParkedOrder(void* pLC_Api, struct CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryParkedOrder(pQryParkedOrder,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryParkedOrderAction(void* pLC_Api, struct CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryParkedOrderAction(pQryParkedOrderAction,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryTradingNotice(void* pLC_Api, struct CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryTradingNotice(pQryTradingNotice,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryBrokerTradingParams(void* pLC_Api, struct CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryBrokerTradingParams(pQryBrokerTradingParams,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQryBrokerTradingAlgos(void* pLC_Api, struct CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqFromBankToFutureByFuture(void* pLC_Api, struct CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqFromBankToFutureByFuture(pReqTransfer,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqFromFutureToBankByFuture(void* pLC_Api, struct CThostFtdcReqTransferField *pReqTransfer, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqFromFutureToBankByFuture(pReqTransfer,  nRequestID);
	}
	return -1;
}

LC_CTP_API int TraderApiReqQueryBankAccountMoneyByFuture(void* pLC_Api, struct CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcTraderApi(pLC_Api))->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount,  nRequestID);
	}
	return -1;
}

