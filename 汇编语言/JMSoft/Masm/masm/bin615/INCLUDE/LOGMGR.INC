  ; ===========================================
  ; logmgr.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF LOGMGR_INC
LOGMGR_INC equ <1>

DllGetClassObject PROTO :DWORD,:DWORD,:DWORD
DllRegisterServer PROTO 
DllUnregisterServer PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file logmgr.inc
echo -----------------------------------------
ENDIF
