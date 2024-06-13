  ; ===========================================
  ; parser.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF PARSER_INC
PARSER_INC equ <1>

AddressToString PROTO :DWORD,:DWORD
ByteToBinary PROTO :DWORD,:DWORD
CanonHex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CanonicalizeHexString PROTO :DWORD,:DWORD,:DWORD
DwordToBinary PROTO :DWORD,:DWORD
GetEtype PROTO :DWORD,:DWORD
GetLLCHeaderLength PROTO :DWORD
GetMacHeaderLength PROTO :DWORD,:DWORD
GetProtocolDescription PROTO :DWORD
GetProtocolDescriptionTable PROTO :DWORD
GetSaps PROTO :DWORD,:DWORD
IsLLCPresent PROTO :DWORD,:DWORD
LookupByteSetString PROTO :DWORD,:DWORD
LookupDwordSetString PROTO :DWORD,:DWORD
LookupWordSetString PROTO :DWORD,:DWORD
StringToAddress PROTO :DWORD,:DWORD
VarLenSmallIntToDword PROTO :DWORD,:DWORD,:DWORD,:DWORD
WordToBinary PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file parser.inc
echo -----------------------------------------
ENDIF
