  ; ===========================================
  ; riched20.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RICHED20_INC
RICHED20_INC equ <1>

CreateTextServices PROTO :DWORD,:DWORD,:DWORD
RichEdit10ANSIWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
RichEditANSIWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file riched20.inc
echo -----------------------------------------
ENDIF
