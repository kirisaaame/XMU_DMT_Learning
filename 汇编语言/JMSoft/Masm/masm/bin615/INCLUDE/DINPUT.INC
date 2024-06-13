  ; ===========================================
  ; dinput.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DINPUT_INC
DINPUT_INC equ <1>

DirectInputCreateA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectInputCreate equ <DirectInputCreateA>

DirectInputCreateEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectInputCreateW PROTO :DWORD,:DWORD,:DWORD,:DWORD
_DirectInputCreateW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dinput.inc
echo -----------------------------------------
ENDIF
