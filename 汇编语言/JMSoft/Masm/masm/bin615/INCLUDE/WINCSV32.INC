  ; ===========================================
  ; wincsv32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINCSV32_INC
WINCSV32_INC equ <1>

ACSSVC PROTO :DWORD
ACSSVC_C PROTO :DWORD
ACSSVC_C_ext PROTO :DWORD
ACSSVC_P PROTO :DWORD
ACSSVC_P_ext PROTO :DWORD
ACSSVC_ext PROTO :DWORD
GetCsvReturnCode PROTO :DWORD,:DWORD,:DWORD
GetCsvReturnCode_ext PROTO :DWORD,:DWORD,:DWORD
WinAsyncCSV PROTO :DWORD,:DWORD
WinAsyncCSV_ext PROTO :DWORD,:DWORD
WinCSV PROTO :DWORD
WinCSVCleanup PROTO 
WinCSVCleanup_ext PROTO 
WinCSVStartup PROTO :DWORD,:DWORD
WinCSVStartup_ext PROTO :DWORD,:DWORD
WinCSV_ext PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file wincsv32.inc
echo -----------------------------------------
ENDIF
