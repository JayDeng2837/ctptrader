mkdir platform_build

cd platform_build

cmake ../../src/Platform -G "Visual Studio 12" -Wno-dev -DBoost_DEBUG=ON

pause