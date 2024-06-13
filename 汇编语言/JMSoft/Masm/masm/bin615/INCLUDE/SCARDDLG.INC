  ; ===========================================
  ; scarddlg.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SCARDDLG_INC
SCARDDLG_INC equ <1>

GetOpenCardNameA PROTO :DWORD
GetOpenCardName equ <GetOpenCardNameA>

GetOpenCardNameW PROTO :DWORD
SCardDlgExtendedError PROTO 
SCardUIDlgSelectCardA PROTO :DWORD
SCardUIDlgSelectCard equ <SCardUIDlgSelectCardA>

SCardUIDlgSelectCardW PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file scarddlg.inc
echo -----------------------------------------
ENDIF
