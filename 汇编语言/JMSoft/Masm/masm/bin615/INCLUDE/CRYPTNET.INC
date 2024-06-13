  ; ===========================================
  ; cryptnet.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CRYPTNET_INC
CRYPTNET_INC equ <1>

CryptGetObjectUrl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptInstallCancelRetrieval PROTO :DWORD,:DWORD,:DWORD,:DWORD
CryptRetrieveObjectByUrlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptRetrieveObjectByUrl equ <CryptRetrieveObjectByUrlA>

CryptRetrieveObjectByUrlW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CryptUninstallCancelRetrieval PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file cryptnet.inc
echo -----------------------------------------
ENDIF
