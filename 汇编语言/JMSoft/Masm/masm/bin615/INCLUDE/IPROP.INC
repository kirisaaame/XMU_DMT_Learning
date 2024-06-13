  ; ===========================================
  ; iprop.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF IPROP_INC
IPROP_INC equ <1>

FmtIdToPropStgName PROTO :DWORD,:DWORD
FreePropVariantArray PROTO :DWORD,:DWORD
PropStgNameToFmtId PROTO :DWORD,:DWORD
PropVariantClear PROTO :DWORD
PropVariantCopy PROTO :DWORD,:DWORD
StgCreatePropSetStg PROTO :DWORD,:DWORD,:DWORD
StgCreatePropStg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StgOpenPropStg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file iprop.inc
echo -----------------------------------------
ENDIF
