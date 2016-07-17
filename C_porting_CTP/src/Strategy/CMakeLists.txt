CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(StrategyCollection C CXX)

SET(CMAKES_ROOT ${PROJECT_SOURCE_DIR}/../..)

SET(THIRD_PARTY_ROOT ${PROJECT_SOURCE_DIR}/../../../ThirdParty)

include (${CMAKES_ROOT}/../cmake/common.cmake)

include (${CMAKES_ROOT}/../cmake/boost_common.cmake)

SET(COMMON_HEADER_BASE ${HEADER_BASE}/Common)

SET(UTILS_H_BASE ${HEADER_BASE}/Utils)
SET(UTILS_LIB_BASE ${LIB_BASE}/Utils)

SET(STRATEGYBASE_H_BASE ${HEADER_BASE}/StrategyBase)
SET(STRATEGYBASE_LIB_BASE ${LIB_BASE}/StrategyBase)

if (WIN32)

SET(TBB_H_PATH ${THIRD_PARTY_HEADER_BASE}/TBB)
SET(TBB_LIB_PATH ${THIRD_PARTY_LIB_BASE}/TBB/win32)

else(WIN32)
endif(WIN32)

macro(rw_module_source_all)  
    file(GLOB_RECURSE rw_module_source_list . "*.c*" "*.h" "*.hpp" "*.inl")  
    aux_source_directory(. rw_module_source_list)  
endmacro(rw_module_source_all)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

INCLUDE_DIRECTORIES (
	${COMMON_HEADER_BASE}
	${UTILS_H_BASE}
	${STRATEGYBASE_H_BASE}
)

LINK_DIRECTORIES (
	${UTILS_LIB_BASE}
	${STRATEGYBASE_LIB_BASE}
)

ADD_SUBDIRECTORY(BidOrderStrategy)
