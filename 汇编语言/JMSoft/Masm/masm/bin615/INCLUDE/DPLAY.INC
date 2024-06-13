  ; ===========================================
  ; dplay.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DPLAY_INC
DPLAY_INC equ <1>

DirectPlayCreate PROTO :DWORD,:DWORD,:DWORD
DirectPlayEnumerate PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dplay.inc
echo -----------------------------------------
ENDIF
