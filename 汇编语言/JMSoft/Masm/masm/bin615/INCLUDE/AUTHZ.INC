  ; ===========================================
  ; authz.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF AUTHZ_INC
AUTHZ_INC equ <1>

AuthzAccessCheck PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzAddSidsToContext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzCachedAccessCheck PROTO :DWORD,:DWORD,:DWORD,:DWORD
AuthzFreeAuditEvent PROTO :DWORD
AuthzFreeAuditInfo PROTO :DWORD,:DWORD
AuthzFreeContext PROTO :DWORD
AuthzFreeHandle PROTO :DWORD
AuthzFreeRMAuditInfo PROTO :DWORD
AuthzFreeResourceManager PROTO :DWORD
AuthzGetInformationFromAuditInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzGetInformationFromContext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzGetInformationFromRMAuditInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzGetInformationFromResourceManager PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeAuditEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeAuditInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromAuthzContext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromSid PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeContextFromToken PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeRMAuditInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzInitializeResourceManager PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzLogAuditEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
AuthzModifyRMAuditInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzOpenObjectAuditAlarm PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AuthzRegisterAuditEvent PROTO :DWORD,:DWORD
AuthzUnregisterAuditEvent PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file authz.inc
echo -----------------------------------------
ENDIF
