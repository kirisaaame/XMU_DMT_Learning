  ; ===========================================
  ; sqlakw32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SQLAKW32_INC
SQLAKW32_INC equ <1>

LibMain PROTO :DWORD,:DWORD,:DWORD
sqlaaloc PROTO :DWORD,:DWORD,:DWORD,:DWORD
sqlacall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqladloc PROTO :DWORD,:DWORD
sqlakver PROTO :DWORD,:DWORD,:DWORD,:DWORD
sqlasets PROTO :DWORD,:DWORD,:DWORD
sqlasetv PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
sqlastop PROTO :DWORD
sqlastrt PROTO :DWORD,:DWORD,:DWORD
sqlausda PROTO :DWORD,:DWORD,:DWORD
sqlestar PROTO 
sqlestpd PROTO :DWORD
sqlestrd PROTO :DWORD,:DWORD,:DWORD,:DWORD
sqlxcall PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sqlakw32.inc
echo -----------------------------------------
ENDIF
