  ; ===========================================
  ; adme.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ADME_INC
ADME_INC equ <1>

DllRegisterServer PROTO 
DllUnregisterServer PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file adme.inc
echo -----------------------------------------
ENDIF
