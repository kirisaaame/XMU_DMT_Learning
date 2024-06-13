  ; ===========================================
  ; sporder.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SPORDER_INC
SPORDER_INC equ <1>

WSCWriteNameSpaceOrder PROTO :DWORD,:DWORD
WSCWriteProviderOrder PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sporder.inc
echo -----------------------------------------
ENDIF
