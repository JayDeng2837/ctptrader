#include "LCThostFtdcMdApi.h"
#include "LCThostFtdcMdApiImpl.hpp"

void * CreateLCCThostFtdcMdSpi()
{
	return (void *)(new LCCThostFtdcMdSpi);
}

void ReleaseLCCThostFtdcMdSpi(void * * pLC_Spi)
{
	if (*pLC_Spi != NULL)
	{
		delete *pLC_Spi;
		*pLC_Spi = NULL;
	}
}

void RegisterMdApiOnFrontConnectedCallback(void * pLC_Spi, fnMdApiOnFrontConnected pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnFrontConnectedCallback(pCallback);
	}
}
void RegisterMdApiOnFrontDisconnectedCallback(void * pLC_Spi, fnMdApiOnFrontDisconnected pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnFrontDisconnectedCallback(pCallback);
	}
}
void RegisterMdApiOnHeartBeatWarningCallback(void * pLC_Spi, fnMdApiOnHeartBeatWarning pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnHeartBeatWarningCallback(pCallback);
	}
}
void RegisterMdApiOnRspUserLoginCallback(void * pLC_Spi, fnMdApiOnRspUserLogin pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspUserLoginCallback(pCallback);
	}
}
void RegisterMdApiOnRspUserLogoutCallback(void * pLC_Spi, fnMdApiOnRspUserLogout pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspUserLogoutCallback(pCallback);
	}
}
void RegisterMdApiOnRspErrorCallback(void * pLC_Spi, fnMdApiOnRspError pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspErrorCallback(pCallback);
	}
}
void RegisterMdApiOnRspSubMarketDataCallback(void * pLC_Spi, fnMdApiOnRspSubMarketData pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspSubMarketDataCallback(pCallback);
	}
}
void RegisterMdApiOnRspUnSubMarketDataCallback(void * pLC_Spi, fnMdApiOnRspUnSubMarketData pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspUnSubMarketDataCallback(pCallback);
	}
}
void RegisterMdApiOnRspSubForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRspSubForQuoteRsp pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspSubForQuoteRspCallback(pCallback);
	}
}
void RegisterMdApiOnRspUnSubForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRspUnSubForQuoteRsp pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRspUnSubForQuoteRspCallback(pCallback);
	}
}
void RegisterMdApiOnRtnDepthMarketDataCallback(void * pLC_Spi, fnMdApiOnRtnDepthMarketData pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRtnDepthMarketDataCallback(pCallback);
	}
}
void RegisterMdApiOnRtnForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRtnForQuoteRsp pCallback)
{
	if (pLC_Spi != NULL)
	{
		(GetLCCThostFtdcMdSpi(pLC_Spi))->RegisterMdApiOnRtnForQuoteRspCallback(pCallback);
	}
}
LC_CTP_API void * CreateLCCThostFtdcMdApi(const char * con_path, bool bIsUsingUdp, bool bIsMulticast)
{
	return (void *)(CThostFtdcMdApi::CreateFtdcMdApi(con_path, bIsUsingUdp, bIsMulticast));
}

void ReleaseLCCThostFtdcMdApi(void * * pLC_Api)
{
	if (*pLC_Api != NULL)
	{
		delete *pLC_Api;
		*pLC_Api = NULL;
	}
}

LC_CTP_API void MdApiRelease(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->Release();
	}
}

LC_CTP_API void MdApiInit(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->Init();
	}
}

LC_CTP_API int MdApiJoin(void* pLC_Api)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->Join();
	}
	return -1;
}

LC_CTP_API void MdApiRegisterFront(void* pLC_Api, char *pszFrontAddress)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->RegisterFront(pszFrontAddress);
	}
}

LC_CTP_API void MdApiRegisterNameServer(void* pLC_Api, char *pszNsAddress)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->RegisterNameServer(pszNsAddress);
	}
}

LC_CTP_API void MdApiRegisterFensUserInfo(void* pLC_Api, struct CThostFtdcFensUserInfoField * pFensUserInfo)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->RegisterFensUserInfo( pFensUserInfo);
	}
}

LC_CTP_API void MdApiRegisterSpi(void * pLC_Api, void * pLC_Spi)
{
	if (pLC_Api != NULL)
	{
		(GetCThostFtdcMdApi(pLC_Api))->RegisterSpi(GetLCCThostFtdcMdSpi(pLC_Spi));
	}
}

LC_CTP_API int MdApiSubscribeMarketData(void* pLC_Api, char *ppInstrumentID[], int nCount)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->SubscribeMarketData(ppInstrumentID,  nCount);
	}
	return -1;
}

LC_CTP_API int MdApiUnSubscribeMarketData(void* pLC_Api, char *ppInstrumentID[], int nCount)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->UnSubscribeMarketData(ppInstrumentID,  nCount);
	}
	return -1;
}

LC_CTP_API int MdApiSubscribeForQuoteRsp(void* pLC_Api, char *ppInstrumentID[], int nCount)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->SubscribeForQuoteRsp(ppInstrumentID,  nCount);
	}
	return -1;
}

LC_CTP_API int MdApiUnSubscribeForQuoteRsp(void* pLC_Api, char *ppInstrumentID[], int nCount)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->UnSubscribeForQuoteRsp(ppInstrumentID,  nCount);
	}
	return -1;
}

LC_CTP_API int MdApiReqUserLogin(void* pLC_Api, struct CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->ReqUserLogin(pReqUserLoginField,  nRequestID);
	}
	return -1;
}

LC_CTP_API int MdApiReqUserLogout(void* pLC_Api, struct CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	if (pLC_Api != NULL)
	{
		return (GetCThostFtdcMdApi(pLC_Api))->ReqUserLogout(pUserLogout,  nRequestID);
	}
	return -1;
}

