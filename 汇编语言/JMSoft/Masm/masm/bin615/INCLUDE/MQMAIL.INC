  ; ===========================================
  ; mqmail.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MQMAIL_INC
MQMAIL_INC equ <1>

FGetAliasFromDestination PROTO :DWORD,:DWORD,:DWORD
FStringContainsDBCS PROTO :DWORD
GetQLabelFromDestination PROTO :DWORD
HrAddPrefixStr PROTO :DWORD,:DWORD,:DWORD
HrCopyData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HrCreateDestStr PROTO :DWORD,:DWORD,:DWORD
HrCreateUnicodeStr PROTO :DWORD,:DWORD,:DWORD
HrFileTimeToMimeDate PROTO :DWORD,:DWORD,:DWORD
HrFormatMessageV PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrGetTempFName PROTO :DWORD,:DWORD
HrGetTempFNameByDirPfx PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrMimeDateToFileTime PROTO :DWORD,:DWORD,:DWORD
HrParseMimeRecip PROTO :DWORD,:DWORD,:DWORD
HrParseMimeRecips PROTO :DWORD,:DWORD,:DWORD
HrQuoteString PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrTimeToFileTime PROTO :DWORD,:DWORD
HrUnQuoteString PROTO :DWORD,:DWORD,:DWORD
MQMailComposeBody PROTO :DWORD,:DWORD,:DWORD
MQMailFreeMemory PROTO :DWORD
MQMailParseBody PROTO :DWORD,:DWORD,:DWORD
TrimFix PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mqmail.inc
echo -----------------------------------------
ENDIF
