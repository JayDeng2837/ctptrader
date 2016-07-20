
Update Third-party Libraries
=====================================

1. Update Boost
    if u wanna update the boost version, just compile the new boost library and modify the "ctptrader\cmake\boost_common.cmake" accordingly.

2. Update CTP API
    1) Add folder for new version CTP api in "ctptrader\ThirdParty\include\win32\ctp_api","ctptrader\ThirdParty\lib\win32\ctp_api" put api files into the folder.
    2) run the script "gen_c_code.py" in "ctptrader\C_porting_CTP".
    3) recompile the platform and strategies solutions.