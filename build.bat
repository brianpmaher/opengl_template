@echo off

setlocal EnableDelayedExpansion

set "startTime=%time: =0%"

rem ////////////////////////////////////////////////////////////////////////////////
rem                                   Config
rem ////////////////////////////////////////////////////////////////////////////////

:startConfig

set debugBuild=0
set cleanBuildCache=0
set runAfterBuild=1

:endConfig

rem ////////////////////////////////////////////////////////////////////////////////
rem                               Setup compiler
rem ////////////////////////////////////////////////////////////////////////////////

:startCompilerSetup

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

set flags=/nologo /W4 /wd5105 /std:c17
if %debugBuild% == 1 (
    set flags=%flags% /Zi /Od
) else (
    set flags=%flags% /O2
)

:endCompilerSetup

rem ////////////////////////////////////////////////////////////////////////////////
rem                               Manage build cache
rem ////////////////////////////////////////////////////////////////////////////////

:startManageBuildCache

if exist build call rmdir /s /q build

mkdir build

if %cleanBuildCache% == 1 (
    if exist build_cache call rmdir /s /q build_cache
)

if not exist build_cache mkdir build_cache

:endManageBuildCache

rem ////////////////////////////////////////////////////////////////////////////////
rem                                 Compile GLAD
rem ////////////////////////////////////////////////////////////////////////////////

:startCompileGlad

if exist build_cache\glad.obj goto endCompileGlad

echo COMPILE-INFO: Compiling GLAD. Future builds will be faster.

set defines=
set includes=/I include
set sources=code\third_party\glad.c

call cl /c %flags% %defines% %includes% %sources%

move glad.obj build_cache

:endCompileGlad

rem ////////////////////////////////////////////////////////////////////////////////
rem                                 Compile game
rem ////////////////////////////////////////////////////////////////////////////////

:startCompileGame

set defines=
set includes=/I include
set sources=code\*.c build_cache\*.obj
set libs=lib\glfw3dll.lib
set exeName=game.exe

copy lib\glfw3.dll build >nul 2>nul

call cl %flags% %defines% %includes% %sources% %libs% /Fe:build\%exeName%

if %errorlevel% == 0 (
    set compilationSuccess=1
) else (
    set compilationSuccess=0
)

move *.pdb build >nul 2>nul

call del *.obj

:endCompileGame

rem ////////////////////////////////////////////////////////////////////////////////
rem                              Compilation metrics
rem ////////////////////////////////////////////////////////////////////////////////

:startCompilationMetrics

set "endTime=%time: =0%"

rem Get elapsed time:
set "end=!endTime:%time:~8,1%=%%100)*100+1!"  &  set "start=!startTime:%time:~8,1%=%%100)*100+1!"
set /A "elap=((((10!end:%time:~2,1%=%%100)*60+1!%%100)-((((10!start:%time:~2,1%=%%100)*60+1!%%100), elap-=(elap>>31)*24*60*60*100"

rem Convert elapsed time to HH:MM:SS:CC format:
set /A "cc=elap%%100+100,elap/=100,ss=elap%%60+100,elap/=60,mm=elap%%60+100,hh=elap/60+100"

echo COMPILE-INFO: build time %hh:~1%%time:~2,1%%mm:~1%%time:~2,1%%ss:~1%%time:~8,1%%cc:~1%

:endCompilationMetrics

rem ////////////////////////////////////////////////////////////////////////////////
rem                                   Run game
rem ////////////////////////////////////////////////////////////////////////////////

:startRunGame

if %runAfterBuild% == 0 goto endRunGame

if %compilationSuccess% == 1 (
    if %debugBuild% == 1 (
        call remedybg build\%exeName%
    ) else (
        call build\%exeName%
    )
)

:endRunGame
