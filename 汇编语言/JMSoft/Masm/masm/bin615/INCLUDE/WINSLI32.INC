  ; ===========================================
  ; winsli32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINSLI32_INC
WINSLI32_INC equ <1>

DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
DllEntryPoint_ext PROTO :DWORD,:DWORD,:DWORD
GetLuaReturnCode PROTO :DWORD,:DWORD,:DWORD
GetLuaReturnCode_ext PROTO :DWORD,:DWORD,:DWORD
SLI PROTO :DWORD
SLI_CALL PROTO :DWORD
SLI_CALL_ext PROTO :DWORD
SLI_ext PROTO :DWORD
WinSLI PROTO :DWORD,:DWORD
WinSLICleanup PROTO 
WinSLICleanup_ext PROTO 
WinSLIStartup PROTO :DWORD,:DWORD
WinSLIStartup_ext PROTO :DWORD,:DWORD
WinSLI_ext PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winsli32.inc
echo -----------------------------------------
ENDIF
