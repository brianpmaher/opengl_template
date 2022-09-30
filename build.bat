@echo off

rem TODO: Compile glad.c separately

set debugBuild=0
set exeName=game.exe

call cl >nul 2>nul

if not %errorlevel% == 0 (
    echo COMPILE-INFO: Setting up cl compiler.
    echo COMPILE-INFO: Future build runs will be faster.
    call vcvarsall.bat x64 >nul 2>nul
)

if not %errorlevel% == 0 (
    echo COMPILE-ERROR: cl compiler is required.
    echo COMPILE-ERROR: Install Microsoft Visual Studio 2022 and make sure vcvarsall.bat is in your PATH.
    exit /b 1
)

if exist build call rmdir /s /q build

mkdir build

set defines=
set includes=/I include
set sources=code\third_party\*.c code\*.c
set libs=lib\glfw3dll.lib

set flags=/nologo /W4 /wd5105 /std:c17
if %debugBuild% == 1 (
    set flags=%flags% /Zi /Od
) else (
    set flags=%flags% /O2
)

copy lib\glfw3.dll build >nul 2>nul

call cl %flags% %defines% %includes% %sources% %libs% /Fe:build\%exeName%

move *.pdb build >nul 2>nul

call del *.obj

if %errorlevel% == 0 (
    if %debugBuild% == 1 (
        call remedybg build\%exeName%
    ) else (
        call build\%exeName%
    )
)
