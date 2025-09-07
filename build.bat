@echo off
:: Remove previous build folder
if exist build (
    rmdir /s /q build
)

:: Create build folder and enter it
mkdir build
cd build

:: Run CMake with MinGW Makefiles
cmake -G "MinGW Makefiles" ..

:: Build the project
mingw32-make
