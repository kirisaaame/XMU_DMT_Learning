  ; ===========================================
  ; winstrm.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINSTRM_INC
WINSTRM_INC equ <1>

OpenStream PROTO :DWORD
getmsg PROTO :DWORD,:DWORD,:DWORD,:DWORD
poll PROTO :DWORD,:DWORD,:DWORD
putmsg PROTO :DWORD,:DWORD,:DWORD,:DWORD
s_ioctl PROTO :DWORD,:DWORD,:DWORD
s_open PROTO :DWORD,:DWORD,:DWORD
s_perror PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winstrm.inc
echo -----------------------------------------
ENDIF
