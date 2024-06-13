  ; ===========================================
  ; toolbar.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF TOOLBAR_INC
TOOLBAR_INC equ <1>

CreateToolbar PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ToolbarWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
_CreateToolbar PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file toolbar.inc
echo -----------------------------------------
ENDIF
