  ; ===========================================
  ; nddeapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NDDEAPI_INC
NDDEAPI_INC equ <1>

NDdeGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
NDdeGetErrorString equ <NDdeGetErrorStringA>

NDdeGetErrorStringW PROTO :DWORD,:DWORD,:DWORD
NDdeGetShareSecurityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeGetShareSecurity equ <NDdeGetShareSecurityA>

NDdeGetShareSecurityW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeGetTrustedShareA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeGetTrustedShare equ <NDdeGetTrustedShareA>

NDdeGetTrustedShareW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeIsValidAppTopicListA PROTO :DWORD
NDdeIsValidAppTopicList equ <NDdeIsValidAppTopicListA>

NDdeIsValidAppTopicListW PROTO :DWORD
NDdeIsValidShareNameA PROTO :DWORD
NDdeIsValidShareName equ <NDdeIsValidShareNameA>

NDdeIsValidShareNameW PROTO :DWORD
NDdeSetShareSecurityA PROTO :DWORD,:DWORD,:DWORD,:DWORD
NDdeSetShareSecurity equ <NDdeSetShareSecurityA>

NDdeSetShareSecurityW PROTO :DWORD,:DWORD,:DWORD,:DWORD
NDdeSetTrustedShareA PROTO :DWORD,:DWORD,:DWORD
NDdeSetTrustedShare equ <NDdeSetTrustedShareA>

NDdeSetTrustedShareW PROTO :DWORD,:DWORD,:DWORD
NDdeShareAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareAdd equ <NDdeShareAddA>

NDdeShareAddW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareDelA PROTO :DWORD,:DWORD,:DWORD
NDdeShareDel equ <NDdeShareDelA>

NDdeShareDelW PROTO :DWORD,:DWORD,:DWORD
NDdeShareEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareEnum equ <NDdeShareEnumA>

NDdeShareEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareGetInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareGetInfo equ <NDdeShareGetInfoA>

NDdeShareGetInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareSetInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeShareSetInfo equ <NDdeShareSetInfoA>

NDdeShareSetInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeSpecialCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeSpecialCommand equ <NDdeSpecialCommandA>

NDdeSpecialCommandW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeTrustedShareEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NDdeTrustedShareEnum equ <NDdeTrustedShareEnumA>

NDdeTrustedShareEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file nddeapi.inc
echo -----------------------------------------
ENDIF
