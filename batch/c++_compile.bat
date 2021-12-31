::badger
@echo off
title c++_compile
::call :set_con_size 100,30

:setup
set def_file_name=main
set file_extension=cpp
goto input

:input
echo type 'd' to get default value
set /p file_path="c++ file path: "
set /p file_name="c++ file name: "
if /i %file_name%==d set file_name=%def_file_name%
set /p exe_path="exe file path: "
if /i %exe_path%==d set exe_path=%file_path%
set /p exe_name="exe file name: "
if /i %exe_name%==d set exe_name=%file_name%

set file_dir=%file_path%\%file_name%.%file_extension%
set exe_dir=%exe_path%\%exe_name%.exe

::if(call :check_file %file_dir%)==0(goto setup)

call :loop option

:option
echo file:
echo c++ file: %file_dir%
echo exe file: %exe_dir%
echo.
call :line_segment
echo command:
echo type 'c' to compile the program
echo type 'f' to change the file value
echo type 'r' to run the program
echo type 'o' to open the file
echo type 'rr' to read file
echo type 'n' to create new console
echo type 'cc' to set color of console
echo type 'h' to get help
echo type 'e' to exit this batch program
call :line_segment
goto decide

:decide
set /p a1="what do you want to do? "
cls
if /i %a1%==c goto compile
if /i %a1%==f goto setup
if /i %a1%==r goto run
if /i %a1%==o goto open
if /i %a1%==rr goto read
if /i %a1%==n call :new_con && call :loop option
if /i %a1%==cc goto :set_color
::if /i %a1%==h start google.com
if /i %a1%==e goto leave
echo '%a1%' is not a valid command
call :loop option

:compile
echo compile output:
echo _______________
echo.
g++ %file_dir% -o %exe_dir%
call :loop option

:run
start %exe_dir%
call :loop option

:open
start %file_dir%
call :loop option

:read
for /f "tokens=*" %%a in (%file_dir%) do (echo %%a)
call :loop option

:leave
echo leave the program...
call :wait 1
exit
exit /b 0

:input
set /p a1=%~1
set %~2=%a1%
exit /b 0

:line_segment
echo ------------------------------
exit /b 0

:check_file
set out=0
if exist %~1(echo %~1 exist. && out=0)^
else(echo %~1 does not exist! && out=1)
exit /b out

:wait
timeout /t %~1 /noBreak>nul
exit /b 0

:new_con
start
exit /b 0

:set_color
set /p a1="color: "
color %a1%
call :loop option

:set_con_size
mode con cols=%~1 lines=%~2
exit /b 0

:stop
pause
cls
exit /b 0

:loop
call :stop
goto %~1
exit /b %errorLevel%
::add: echo colors for 'set_color'