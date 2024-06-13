  ; ===========================================
  ; dtcutil.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DTCUTIL_INC
DTCUTIL_INC equ <1>

DllGetDTCUtilObject PROTO :DWORD,:DWORD,:DWORD
_DllGetDTCUtilObject PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dtcutil.inc
echo -----------------------------------------
ENDIF
