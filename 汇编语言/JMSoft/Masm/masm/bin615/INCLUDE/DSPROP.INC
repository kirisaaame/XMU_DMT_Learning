  ; ===========================================
  ; dsprop.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DSPROP_INC
DSPROP_INC equ <1>

ADsPropCheckIfWritable PROTO :DWORD,:DWORD
ADsPropCreateNotifyObj PROTO :DWORD,:DWORD,:DWORD
ADsPropGetInitInfo PROTO :DWORD,:DWORD
ADsPropSetHwnd PROTO :DWORD,:DWORD
BringSheetToForeground PROTO :DWORD,:DWORD
DllMain PROTO :DWORD,:DWORD,:DWORD
IsSheetAlreadyUp PROTO :DWORD
PostADsPropSheet PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dsprop.inc
echo -----------------------------------------
ENDIF
