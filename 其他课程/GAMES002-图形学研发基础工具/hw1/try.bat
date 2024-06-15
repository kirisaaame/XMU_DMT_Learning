md copied
for /l %%i in (0,1,9) do echo.>file0%%i.txt
for /l %%i in (10,1,99) do echo.>file%%i.txt
for /R %%f in (file*.txt) do copy "%%f" "./copied"
