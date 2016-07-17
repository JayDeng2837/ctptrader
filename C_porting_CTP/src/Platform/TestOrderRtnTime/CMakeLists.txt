CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(LIBRARY_OUTPUT_PATH ${STRATEGYBASE_LIB_BASE})

SET(build_target "TestOrderRtnTime")

INCLUDE_DIRECTORIES (
	${STRATEGYBASE_H_BASE}
)

LINK_DIRECTORIES (
	${STRATEGYBASE_LIB_BASE}
)

# generate project
#rw_module_source_list
rw_module_source_all()

add_library(
	${build_target}
	SHARED
	
	${rw_module_source_list}
)

ADD_DEFINITIONS(-DSTRATEGY_INTERNAL)

ADD_DEFINITIONS(-DUSE_IOC)

IF (WIN32)

ADD_DEFINITIONS(-DDLL_EXPORT)

target_link_libraries (
	${build_target}
	
	Utilities.lib
	StrategyBase.lib
	tbb.lib
	${Boost_LIBRARIES}
)

ELSE (WIN32)

ENDIF (WIN32)

set_source_files_properties(${build_target} PROPERTIES
       COMPILE_FLAGS  "${EXTRA_OPTIONS}")

get_target_property(target_file_name ${build_target} LOCATION)

add_custom_command(TARGET ${build_target} POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy ${target_file_name} ${BIN_PATH}/$(Configuration)
				   )

set_target_properties( ${build_target} PROPERTIES LINKER_LANGUAGE "CXX")

ADD_DEPENDENCIES(${build_target} StrategyBase)
