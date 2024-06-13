  ; ===========================================
  ; msimg32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSIMG32_INC
MSIMG32_INC equ <1>

AlphaBlend PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GradientFill PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TransparentBlt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file msimg32.inc
echo -----------------------------------------
ENDIF
