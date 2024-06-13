  ; ===========================================
  ; fmistr32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF FMISTR32_INC
FMISTR32_INC equ <1>

GetFmiReturnCode PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFmiReturnCode_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file fmistr32.inc
echo -----------------------------------------
ENDIF
