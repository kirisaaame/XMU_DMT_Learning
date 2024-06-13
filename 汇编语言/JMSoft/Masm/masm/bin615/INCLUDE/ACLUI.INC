  ; ===========================================
  ; aclui.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ACLUI_INC
ACLUI_INC equ <1>

CreateSecurityPage PROTO :DWORD
EditSecurity PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file aclui.inc
echo -----------------------------------------
ENDIF
