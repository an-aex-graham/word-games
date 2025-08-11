@echo off
setlocal enabledelayedexpansion

rem Go to the script's directory (ensure consistent pathing)
cd /d "%~dp0"

rem Initialize file list
set "SRC_FILES="

echo Compiling the following files:
for /r "%CD%\src" %%f in (*.cpp) do (
    echo   %%f
    set "SRC_FILES=!SRC_FILES! "%%f""
)

g++ -g !SRC_FILES! -Iinclude -o main.exe