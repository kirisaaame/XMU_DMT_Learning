  ; ===========================================
  ; icmui.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ICMUI_INC
ICMUI_INC equ <1>

SetupColorMatchingA PROTO :DWORD
SetupColorMatching equ <SetupColorMatchingA>

SetupColorMatchingW PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file icmui.inc
echo -----------------------------------------
ENDIF
