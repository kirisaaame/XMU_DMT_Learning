  ; ===========================================
  ; sfc.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SFC_INC
SFC_INC equ <1>

SfcClose PROTO :DWORD
SfcConnectToServer PROTO :DWORD
SfcFileException PROTO :DWORD,:DWORD,:DWORD
SfcGetNextProtectedFile PROTO :DWORD,:DWORD
SfcInitProt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SfcInitiateScan PROTO :DWORD,:DWORD
SfcInstallProtectedFiles PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SfcIsFileProtected PROTO :DWORD,:DWORD
SfcTerminateWatcherThread PROTO 
SfcWLEventLogoff PROTO :DWORD
SfcWLEventLogon PROTO :DWORD
SfpDeleteCatalog PROTO :DWORD,:DWORD
SfpInstallCatalog PROTO :DWORD,:DWORD,:DWORD
SfpVerifyFile PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sfc.inc
echo -----------------------------------------
ENDIF
