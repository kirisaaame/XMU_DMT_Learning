  ; ===========================================
  ; winrui32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINRUI32_INC
WINRUI32_INC equ <1>

GetLuaReturnCode PROTO :DWORD,:DWORD,:DWORD
GetLuaReturnCode_ext PROTO :DWORD,:DWORD,:DWORD
RUI PROTO :DWORD
RUI_CALL PROTO :DWORD
RUI_CALL_ext PROTO :DWORD
RUI_ext PROTO :DWORD
WinRUI PROTO :DWORD,:DWORD
WinRUICleanup PROTO 
WinRUICleanup_ext PROTO 
WinRUIGetLastInitStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
WinRUIGetLastInitStatus_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD
WinRUIRegisterTN3270ServiceCallback PROTO :DWORD
WinRUIStartup PROTO :DWORD,:DWORD
WinRUIStartup_ext PROTO :DWORD,:DWORD
WinRUI_ext PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winrui32.inc
echo -----------------------------------------
ENDIF
