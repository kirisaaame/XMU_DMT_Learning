  ; ===========================================
  ; dlcapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DLCAPI_INC
DLCAPI_INC equ <1>

AcsLan PROTO :DWORD,:DWORD
DlcCallDriver PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAdapterNameFromNumber PROTO :DWORD,:DWORD
GetAdapterNumberFromName PROTO :DWORD,:DWORD
NtAcsLan PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dlcapi.inc
echo -----------------------------------------
ENDIF
