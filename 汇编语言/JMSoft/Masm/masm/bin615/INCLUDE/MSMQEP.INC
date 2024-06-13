  ; ===========================================
  ; msmqep.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSMQEP_INC
MSMQEP_INC equ <1>

IsBadReadPtr PROTO :DWORD,:DWORD
IsBadWritePtr PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file msmqep.inc
echo -----------------------------------------
ENDIF
