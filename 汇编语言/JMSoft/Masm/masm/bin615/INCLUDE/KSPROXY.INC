  ; ===========================================
  ; ksproxy.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF KSPROXY_INC
KSPROXY_INC equ <1>

KsGetMediaType PROTO :DWORD,:DWORD,:DWORD,:DWORD
KsGetMediaTypeCount PROTO :DWORD,:DWORD,:DWORD
KsGetMultiplePinFactoryItems PROTO :DWORD,:DWORD,:DWORD,:DWORD
KsOpenDefaultDevice PROTO :DWORD,:DWORD,:DWORD
KsResolveRequiredAttributes PROTO :DWORD,:DWORD
KsSynchronousDeviceControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ksproxy.inc
echo -----------------------------------------
ENDIF
