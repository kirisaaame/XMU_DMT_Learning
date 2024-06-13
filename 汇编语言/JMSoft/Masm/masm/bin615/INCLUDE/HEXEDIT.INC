  ; ===========================================
  ; hexedit.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF HEXEDIT_INC
HEXEDIT_INC equ <1>

DLLEntry PROTO :DWORD,:DWORD,:DWORD
HexEditClass_Register PROTO :DWORD
HexEditClass_UnRegister PROTO :DWORD
HexEditClass_WndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
_DLLEntry PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file hexedit.inc
echo -----------------------------------------
ENDIF
