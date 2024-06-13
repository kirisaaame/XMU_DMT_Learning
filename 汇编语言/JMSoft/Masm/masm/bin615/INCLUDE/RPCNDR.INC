  ; ===========================================
  ; rpcndr.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RPCNDR_INC
RPCNDR_INC equ <1>

MIDL_user_allocate PROTO :DWORD
RpcRaiseException PROTO :DWORD
_midl_allocate PROTO :DWORD
midl_allocate PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file rpcndr.inc
echo -----------------------------------------
ENDIF
