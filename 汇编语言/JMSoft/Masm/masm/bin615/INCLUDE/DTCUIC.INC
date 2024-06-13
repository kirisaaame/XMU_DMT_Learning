  ; ===========================================
  ; dtcuic.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DTCUIC_INC
DTCUIC_INC equ <1>

DllGetClassObject PROTO :DWORD,:DWORD,:DWORD
DllRegisterServer PROTO 
DllUnregisterServer PROTO 
_DllGetClassObject PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dtcuic.inc
echo -----------------------------------------
ENDIF
