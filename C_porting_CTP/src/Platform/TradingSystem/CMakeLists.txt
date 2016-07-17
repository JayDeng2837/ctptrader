CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(EXECUTABLE_OUTPUT_PATH ${BIN_PATH})

SET(build_target "LCTS")

INCLUDE_DIRECTORIES (
	.
	./service
	./worker
	./wrapper
	./manager
	./queue
	
	./lcts
	${CTP_H_BASE}
	${CTP_CAPI_H_BASE}
	${PDCURSES_H_BASE}
	${STRATEGYBASE_H_BASE}
	${ZMQ_H_BASE}
	${PROTOBUF_H_BASE}
)

LINK_DIRECTORIES (
	${CTP_LIB_BASE}
	${PDCURSES_LIB_BASE}
	${STRATEGYBASE_LIB_BASE}
	${ZMQ_LIB_BASE}
	${PROTOBUF_LIB_BASE}
)

IF (WIN32)

INCLUDE_DIRECTORIES (
	${VLD_H_BASE}
)
LINK_DIRECTORIES (
	${VLD_LIB_BASE}
)
ELSE (WIN32)

ENDIF (WIN32)

# generate project
rw_module_source_all()

FILE(GLOB_RECURSE queue_code "queue/*.*")

FILE(GLOB_RECURSE mgr_code "manager/*.*")

FILE(GLOB_RECURSE wrapper_code "wrapper/*.*")

FILE(GLOB_RECURSE worker_code "worker/*.*")

FILE(GLOB_RECURSE service_code "service/*.*")

FILE(GLOB_RECURSE proto_files "../../Protos/lcts/*.proto" "../../Protos/*.bat")

FILE(GLOB_RECURSE proto_pb_files "lcts/*pb.*")

source_group(core FILES ${rw_module_source_list})

source_group(queue FILES ${queue_code})

source_group(manager FILES ${mgr_code})

source_group(wrapper FILES ${wrapper_code})

source_group(worker FILES ${worker_code})

source_group(service FILES ${service_code})

source_group(proto_file FILES ${proto_files})

source_group(proto_pb FILES ${proto_pb_files})

add_executable(
	${build_target}
	${rw_module_source_list}
	${proto_files}
)

ADD_DEFINITIONS(-D_ATOMIC_HAS_ARITHMETIC_OPS)
ADD_DEFINITIONS(-DSTRATEGY_EXTERNAL)
ADD_DEFINITIONS(-DLOCK_FREE_OMS)
ADD_DEFINITIONS(-DNO_FILE_LINE)
ADD_DEFINITIONS(-DHAS_LOG_CALLBACK_F)
#ADD_DEFINITIONS(-DNO_TRADER)

#ADD_DEFINITIONS(-DDEMO)

IF (WIN32)

target_link_libraries (	
	${build_target}
	
	thostmduserapi.lib
	thosttraderapi.lib
	Utilities.lib
	tbb.lib
	StrategyBase.lib
	libzmq.lib
	libprotobuf.lib
	vld.lib
)

ELSE (WIN32)

ENDIF (WIN32)

target_link_libraries (
	${build_target}
	${Boost_LIBRARIES}
)

set_target_properties( ${build_target} PROPERTIES LINKER_LANGUAGE "CXX")

SET(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "NODEFAULTLIBS:library")

ADD_DEPENDENCIES(${build_target} CTPCApi Utilities StrategyBase)
