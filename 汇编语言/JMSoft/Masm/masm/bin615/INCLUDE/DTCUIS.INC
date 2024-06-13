  ; ===========================================
  ; dtcuis.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DTCUIS_INC
DTCUIS_INC equ <1>

DllCreateInstanceDTCUIS PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DllGetClassObject PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dtcuis.inc
echo -----------------------------------------
ENDIF
