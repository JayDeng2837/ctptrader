
Pre-Development
=====================================

1. Install the vs2013 first.

2. Build the boost library locally(build.bat). 
Put boost in local dir. Current version is 1.57.0. 
e.g. E:\\libs\\boost\\boost_1_57_0. 
Use the subst_l.bat to simulate the "E:\\libs" to "L:\\". 

4. Use "ctptrader\\C_porting_CTP\\build*.bat" to generate the vs projects from cmake files.

5. In the solution "LTP_C"(platform), the start app is "LCTS".

6. In the solution "StrategyCollection"(strategies), all the projects are strategies which implement the StrategyBase interface.