  ; ===========================================
  ; rassapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RASSAPI_INC
RASSAPI_INC equ <1>

RasAdminCompressPhoneNumber PROTO :DWORD,:DWORD
RasAdminDLLInit PROTO :DWORD,:DWORD,:DWORD
RasAdminFreeBuffer PROTO :DWORD
RasAdminGetErrorString PROTO :DWORD,:DWORD,:DWORD
RasAdminGetUserAccountServer PROTO :DWORD,:DWORD,:DWORD
RasAdminGetUserParms PROTO :DWORD,:DWORD
RasAdminPortClearStatistics PROTO :DWORD,:DWORD
RasAdminPortDisconnect PROTO :DWORD,:DWORD
RasAdminPortEnum PROTO :DWORD,:DWORD,:DWORD
RasAdminPortGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasAdminServerGetInfo PROTO :DWORD,:DWORD
RasAdminSetUserParms PROTO :DWORD,:DWORD,:DWORD
RasAdminUserGetInfo PROTO :DWORD,:DWORD,:DWORD
RasAdminUserSetInfo PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file rassapi.inc
echo -----------------------------------------
ENDIF
