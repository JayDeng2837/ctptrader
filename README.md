# ctptrader

0. install the vs2013 first.

1. build the boost library locally(build.bat). put boost in local dir. 
    current version is 1.57.0. e.g. E:\libs\boost\boost_1_57_0. 
	use the subst_l.bat to simulate the "E:\libs" to "L:".
	if u wanna update the boost version, just compile the new boost library and modify the "ctptrader\cmake\boost_common.cmake" accordingly.

2. use "ctptrader\C_porting_CTP\build\*.bat" to generate the vs projects from cmake files.

3. in the solution "LTP_C"(platform), the start app is "LCTS".

4. in the solution "StrategyCollection"(strategies), all the projects are strategies which implement the StrategyBase interface.

tips:
   steps to update ctp lib:
   1. add folder for new version CTP api in "ctptrader\ThirdParty\include\win32\ctp_api","ctptrader\ThirdParty\lib\win32\ctp_api"
      put api files into the folder.
   2. run the script "gen_c_code.py" in "ctptrader\C_porting_CTP".
   3. recompile the platform and strategies solutions.
