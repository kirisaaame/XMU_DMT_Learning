  ; ===========================================
  ; ntdsbcli.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NTDSBCLI_INC
NTDSBCLI_INC equ <1>

DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
DsBackupClose PROTO :DWORD
DsBackupEnd PROTO :DWORD
DsBackupFree PROTO :DWORD
DsBackupGetBackupLogsA PROTO :DWORD,:DWORD,:DWORD
DsBackupGetBackupLogs equ <DsBackupGetBackupLogsA>

DsBackupGetBackupLogsW PROTO :DWORD,:DWORD,:DWORD
DsBackupGetDatabaseNamesA PROTO :DWORD,:DWORD,:DWORD
DsBackupGetDatabaseNames equ <DsBackupGetDatabaseNamesA>

DsBackupGetDatabaseNamesW PROTO :DWORD,:DWORD,:DWORD
DsBackupOpenFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsBackupOpenFile equ <DsBackupOpenFileA>

DsBackupOpenFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsBackupPrepareA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsBackupPrepare equ <DsBackupPrepareA>

DsBackupPrepareW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsBackupRead PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsBackupTruncateLogs PROTO :DWORD
DsIsNTDSOnlineA PROTO :DWORD,:DWORD
DsIsNTDSOnline equ <DsIsNTDSOnlineA>

DsIsNTDSOnlineW PROTO :DWORD,:DWORD
DsRestoreCheckExpiryToken PROTO :DWORD,:DWORD
DsRestoreEnd PROTO :DWORD
DsRestoreGetDatabaseLocationsA PROTO :DWORD,:DWORD,:DWORD
DsRestoreGetDatabaseLocations equ <DsRestoreGetDatabaseLocationsA>

DsRestoreGetDatabaseLocationsW PROTO :DWORD,:DWORD,:DWORD
DsRestorePrepareA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRestorePrepare equ <DsRestorePrepareA>

DsRestorePrepareW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRestoreRegisterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRestoreRegister equ <DsRestoreRegisterA>

DsRestoreRegisterComplete PROTO :DWORD,:DWORD
DsRestoreRegisterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsSetAuthIdentityA PROTO :DWORD,:DWORD,:DWORD
DsSetAuthIdentity equ <DsSetAuthIdentityA>

DsSetAuthIdentityW PROTO :DWORD,:DWORD,:DWORD
DsSetCurrentBackupLogA PROTO :DWORD,:DWORD
DsSetCurrentBackupLog equ <DsSetCurrentBackupLogA>

DsSetCurrentBackupLogW PROTO :DWORD,:DWORD
I_DsCheckBackupLogs PROTO :DWORD
I_DsRestoreW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ntdsbcli.inc
echo -----------------------------------------
ENDIF
