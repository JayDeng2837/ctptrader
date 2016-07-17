mkdir strategy_build

cd strategy_build

cmake ../../src/Strategy -G "Visual Studio 12" -Wno-dev -DBoost_DEBUG=ON

pause