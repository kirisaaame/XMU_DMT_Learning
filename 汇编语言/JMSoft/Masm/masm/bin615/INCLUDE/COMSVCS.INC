  ; ===========================================
  ; comsvcs.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF COMSVCS_INC
COMSVCS_INC equ <1>

CoCreateInstanceWithClassInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CoCreateStdTrustable PROTO :DWORD,:DWORD,:DWORD
CoLoadServices PROTO :DWORD,:DWORD,:DWORD,:DWORD
CoVerifyTrust PROTO :DWORD,:DWORD,:DWORD
ComSvcsExceptionFilter PROTO :DWORD,:DWORD,:DWORD
ComSvcsLogError PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateActivityInMTA PROTO :DWORD,:DWORD
CreateActivityInMT equ <CreateActivityInMTA>

DllUnregisterServerWeReallyMeanIt PROTO 
MTSCreateActivity PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file comsvcs.inc
echo -----------------------------------------
ENDIF
