  ; ===========================================
  ; slbs.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SLBS_INC
SLBS_INC equ <1>

ColumnLBClass_ListBoxWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
ColumnLBClass_TitleListBoxWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
ColumnLBClass_WndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
DLLEntry PROTO :DWORD,:DWORD,:DWORD
LBSubclassProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegisterVListBox PROTO :DWORD
VListBoxWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
_ColumnLBClass_ListBoxWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file slbs.inc
echo -----------------------------------------
ENDIF
