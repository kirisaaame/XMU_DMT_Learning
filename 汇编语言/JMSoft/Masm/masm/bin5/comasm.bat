cls
if exist c:\bin5\error.txt  DEL c:\bin5\error.txt
c:\bin5\masm.exe  %1.asm,,,NULL >c:\bin5\merr.txt
c:\bin5\checkerr.exe
if exist "c:\bin5\error.txt" exit
exit


