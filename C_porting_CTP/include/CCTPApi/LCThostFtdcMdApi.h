#ifndef LCTHOSTFTDCMDAPI_H
#define LCTHOSTFTDCMDAPI_H

#include "common_macro.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ThostFtdcUserApiStruct.h"

//define function pointers
typedef void (* fnMdApiOnFrontConnected)();
typedef void (* fnMdApiOnFrontDisconnected)(int nReason);
typedef void (* fnMdApiOnHeartBeatWarning)(int nTimeLapse);
typedef void (* fnMdApiOnRspUserLogin)(struct CThostFtdcRspUserLoginField *pRspUserLogin, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspUserLogout)(struct CThostFtdcUserLogoutField *pUserLogout, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspError)(struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspSubMarketData)(struct CThostFtdcSpecificInstrumentField *pSpecificInstrument, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspUnSubMarketData)(struct CThostFtdcSpecificInstrumentField *pSpecificInstrument, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspSubForQuoteRsp)(struct CThostFtdcSpecificInstrumentField *pSpecificInstrument, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRspUnSubForQuoteRsp)(struct CThostFtdcSpecificInstrumentField *pSpecificInstrument, struct CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
typedef void (* fnMdApiOnRtnDepthMarketData)(struct CThostFtdcDepthMarketDataField *pDepthMarketData);
typedef void (* fnMdApiOnRtnForQuoteRsp)(struct CThostFtdcForQuoteRspField *pForQuoteRsp);

//register callbacks
LC_CTP_API void * CreateLCCThostFtdcMdSpi();
LC_CTP_API void ReleaseLCCThostFtdcMdSpi(void * * pLC_Spi);
LC_CTP_API void RegisterMdApiOnFrontConnectedCallback(void * pLC_Spi, fnMdApiOnFrontConnected pCallback);
LC_CTP_API void RegisterMdApiOnFrontDisconnectedCallback(void * pLC_Spi, fnMdApiOnFrontDisconnected pCallback);
LC_CTP_API void RegisterMdApiOnHeartBeatWarningCallback(void * pLC_Spi, fnMdApiOnHeartBeatWarning pCallback);
LC_CTP_API void RegisterMdApiOnRspUserLoginCallback(void * pLC_Spi, fnMdApiOnRspUserLogin pCallback);
LC_CTP_API void RegisterMdApiOnRspUserLogoutCallback(void * pLC_Spi, fnMdApiOnRspUserLogout pCallback);
LC_CTP_API void RegisterMdApiOnRspErrorCallback(void * pLC_Spi, fnMdApiOnRspError pCallback);
LC_CTP_API void RegisterMdApiOnRspSubMarketDataCallback(void * pLC_Spi, fnMdApiOnRspSubMarketData pCallback);
LC_CTP_API void RegisterMdApiOnRspUnSubMarketDataCallback(void * pLC_Spi, fnMdApiOnRspUnSubMarketData pCallback);
LC_CTP_API void RegisterMdApiOnRspSubForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRspSubForQuoteRsp pCallback);
LC_CTP_API void RegisterMdApiOnRspUnSubForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRspUnSubForQuoteRsp pCallback);
LC_CTP_API void RegisterMdApiOnRtnDepthMarketDataCallback(void * pLC_Spi, fnMdApiOnRtnDepthMarketData pCallback);
LC_CTP_API void RegisterMdApiOnRtnForQuoteRspCallback(void * pLC_Spi, fnMdApiOnRtnForQuoteRsp pCallback);

//api method porting
LC_CTP_API void * CreateLCCThostFtdcMdApi(const char * con_path, bool bIsUsingUdp, bool bIsMulticast);
LC_CTP_API void ReleaseLCCThostFtdcMdApi(void * * pLC_Api);
LC_CTP_API void MdApiRelease(void * pLC_Api);
LC_CTP_API void MdApiInit(void * pLC_Api);
LC_CTP_API int MdApiJoin(void * pLC_Api);
LC_CTP_API void MdApiRegisterFront(void * pLC_Api, char *pszFrontAddress);
LC_CTP_API void MdApiRegisterNameServer(void * pLC_Api, char *pszNsAddress);
LC_CTP_API void MdApiRegisterFensUserInfo(void * pLC_Api, struct CThostFtdcFensUserInfoField * pFensUserInfo);
LC_CTP_API void MdApiRegisterSpi(void * pLC_Api, void * pLC_Spi);
LC_CTP_API int MdApiSubscribeMarketData(void * pLC_Api, char *ppInstrumentID[], int nCount);
LC_CTP_API int MdApiUnSubscribeMarketData(void * pLC_Api, char *ppInstrumentID[], int nCount);
LC_CTP_API int MdApiSubscribeForQuoteRsp(void * pLC_Api, char *ppInstrumentID[], int nCount);
LC_CTP_API int MdApiUnSubscribeForQuoteRsp(void * pLC_Api, char *ppInstrumentID[], int nCount);
LC_CTP_API int MdApiReqUserLogin(void * pLC_Api, struct CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID);
LC_CTP_API int MdApiReqUserLogout(void * pLC_Api, struct CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

#ifdef __cplusplus
}
#endif
#endif
