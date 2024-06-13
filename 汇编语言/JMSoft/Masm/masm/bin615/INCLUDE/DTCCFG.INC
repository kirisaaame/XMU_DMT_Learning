  ; ===========================================
  ; dtccfg.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DTCCFG_INC
DTCCFG_INC equ <1>

CPlApplet PROTO :DWORD,:DWORD,:DWORD,:DWORD
_CPlApplet PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dtccfg.inc
echo -----------------------------------------
ENDIF
