  ; ===========================================
  ; dtccm.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DTCCM_INC
DTCCM_INC equ <1>

DllGetDTCConnectionManager PROTO :DWORD,:DWORD,:DWORD
ShutDownCM PROTO 
_DllGetDTCConnectionManager PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dtccm.inc
echo -----------------------------------------
ENDIF
