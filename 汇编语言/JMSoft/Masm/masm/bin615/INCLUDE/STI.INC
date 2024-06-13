  ; ===========================================
  ; sti.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF STI_INC
STI_INC equ <1>

StiCreateInstanceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
StiCreateInstance equ <StiCreateInstanceA>

StiCreateInstanceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
StiPrivateGetDeviceInfoW PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sti.inc
echo -----------------------------------------
ENDIF
