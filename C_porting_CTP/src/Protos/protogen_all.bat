@echo off

set TOOL_PATH=..\..\..\Tools\Google.ProtocolBuffers.2.4.1.555\tools

set PACKAGE=lcts

set CPP_FOLDER=..\Platform\TradingSystem

set C_SUFFIX=_c

set CSHARP_SUFFIX=_csharp

if not exist %CPP_FOLDER% md %CPP_FOLDER%

for /d %%i in (log_info market_data) do (

%TOOL_PATH%\protoc --proto_path=. --include_imports --descriptor_set_out=%PACKAGE%/%%i%CSHARP_SUFFIX%.protobin %PACKAGE%/%%i%CSHARP_SUFFIX%.proto

%TOOL_PATH%\ProtoGen.exe %PACKAGE%/%%i%CSHARP_SUFFIX%.protobin -output_directory=./../Monitor/Msg_def

%TOOL_PATH%\protoc --proto_path=. --include_imports --cpp_out=.\%CPP_FOLDER% --descriptor_set_out=%PACKAGE%/%%i%C_SUFFIX%.protobin %PACKAGE%/%%i.proto

echo %%i
echo ......

)

del %PACKAGE%\*.protobin

echo to quit!

pause