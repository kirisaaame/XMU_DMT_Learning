  ; ===========================================
  ; qosname.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF QOSNAME_INC
QOSNAME_INC equ <1>

WPUGetQOSTemplate PROTO :DWORD,:DWORD,:DWORD
WSCInstallQOSTemplate PROTO :DWORD,:DWORD,:DWORD
WSCRemoveQOSTemplate PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file qosname.inc
echo -----------------------------------------
ENDIF
