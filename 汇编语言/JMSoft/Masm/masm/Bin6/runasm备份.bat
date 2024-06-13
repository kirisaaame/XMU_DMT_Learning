cls
set path=c:\bin6;%path%
if exist c:\bin6\error.txt  DEL c:\bin6\error.txt
ml.exe   /Fl%1.lst %1.asm   >c:\bin6\merr.txt
cls
c:\bin6\checkerr.exe %2 %3
if exist "c:\bin6\error.txt" exit
cls
%1.exe
pause
exit


