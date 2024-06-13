cls
set path=c:\bin5;%path%
if exist c:\bin5\error.txt  DEL c:\bin5\error.txt
c:\bin5\masm.exe %1.asm,,,NULL >c:\bin5\merr.txt
if exist %1.obj c:\bin5\link.exe %1.obj,,,, >nul
cls
c:\bin5\checkerr.exe %2 %3
if exist "c:\bin5\error.txt" exit
cls
%1.exe
pause
exit





