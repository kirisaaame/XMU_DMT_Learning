  ; ===========================================
  ; certidl.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CERTIDL_INC
CERTIDL_INC equ <1>

CertServerRequest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MIDL_user_allocate PROTO :DWORD
MIDL_user_free PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file certidl.inc
echo -----------------------------------------
ENDIF
