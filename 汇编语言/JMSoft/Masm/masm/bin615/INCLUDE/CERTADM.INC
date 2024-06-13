  ; ===========================================
  ; certadm.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CERTADM_INC
CERTADM_INC equ <1>

CertSrvBackupClose PROTO :DWORD
CertSrvBackupEnd PROTO :DWORD
CertSrvBackupFree PROTO :DWORD
CertSrvBackupGetBackupLogsW PROTO :DWORD,:DWORD,:DWORD
CertSrvBackupGetDatabaseNamesW PROTO :DWORD,:DWORD,:DWORD
CertSrvBackupGetDynamicFileListW PROTO :DWORD,:DWORD,:DWORD
CertSrvBackupOpenFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CertSrvBackupPrepareW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CertSrvBackupRead PROTO :DWORD,:DWORD,:DWORD,:DWORD
CertSrvBackupTruncateLogs PROTO :DWORD
CertSrvIsServerOnlineW PROTO :DWORD,:DWORD
CertSrvRestoreEnd PROTO :DWORD
CertSrvRestoreGetDatabaseLocationsW PROTO :DWORD,:DWORD,:DWORD
CertSrvRestorePrepareW PROTO :DWORD,:DWORD,:DWORD
CertSrvRestoreRegisterComplete PROTO :DWORD,:DWORD
CertSrvRestoreRegisterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CertSrvServerControlW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file certadm.inc
echo -----------------------------------------
ENDIF
