@echo off
set include=D:\VCSOFT\MASM\软件发布\Release\masm\masm\bin615\include;%include%
set lib=D:\VCSOFT\MASM\软件发布\Release\masm\masm\bin615\lib;%lib%
set path=D:\VCSOFT\MASM\软件发布\Release\masm\masm\bin615\bin;%path%
if exist %1.exe del %1.exe
ml /c /coff /Zi %1.asm 
if not exist %1.obj goto mlerr
if exist %1.res goto LinkWithRc
if not exist %1.rc goto LinkWithoutRc
rc %1.rc
if not exist %1.res goto rcerr
:LinkWithRc
Link /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV %1.obj %1.res 
echo     link with the resource file.
goto pos2
:LinkWithoutRc
Link /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV %1.obj 
echo     without the resource file. 
:pos2 
del %1.obj %1.ilk 
goto over
:rcerr
echo Resource file error!
:mlerr
echo assemble error!
:over
echo on
