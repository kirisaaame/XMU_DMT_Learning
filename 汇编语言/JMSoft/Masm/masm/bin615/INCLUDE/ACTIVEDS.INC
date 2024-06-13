  ; ===========================================
  ; activeds.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ACTIVEDS_INC
ACTIVEDS_INC equ <1>

ADsBuildEnumerator PROTO :DWORD,:DWORD
ADsBuildVarArrayInt PROTO :DWORD,:DWORD,:DWORD
ADsBuildVarArrayStr PROTO :DWORD,:DWORD,:DWORD
ADsDecodeBinaryData PROTO :DWORD,:DWORD,:DWORD
ADsEncodeBinaryData PROTO :DWORD,:DWORD,:DWORD
ADsEnumerateNext PROTO :DWORD,:DWORD,:DWORD,:DWORD
ADsFreeEnumerator PROTO :DWORD
ADsGetLastError PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ADsGetObject PROTO :DWORD,:DWORD,:DWORD
ADsOpenObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ADsSetLastError PROTO :DWORD,:DWORD,:DWORD
AdsFreeAdsValues PROTO :DWORD,:DWORD
AdsTypeToPropVariant PROTO :DWORD,:DWORD,:DWORD
AllocADsMem PROTO :DWORD
AllocADsStr PROTO :DWORD
FreeADsMem PROTO :DWORD
FreeADsStr PROTO :DWORD
PropVariantToAdsType PROTO :DWORD,:DWORD,:DWORD,:DWORD
ReallocADsMem PROTO :DWORD,:DWORD,:DWORD
ReallocADsStr PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file activeds.inc
echo -----------------------------------------
ENDIF
