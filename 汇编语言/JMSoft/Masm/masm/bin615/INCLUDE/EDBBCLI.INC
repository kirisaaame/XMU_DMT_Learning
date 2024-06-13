  ; ===========================================
  ; edbbcli.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF EDBBCLI_INC
EDBBCLI_INC equ <1>

BackupFree PROTO :DWORD
DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
HrBackupClose PROTO :DWORD
HrBackupEnd PROTO :DWORD
HrBackupGetBackupLogsA PROTO :DWORD,:DWORD,:DWORD
HrBackupGetBackupLogs equ <HrBackupGetBackupLogsA>

HrBackupGetBackupLogsW PROTO :DWORD,:DWORD,:DWORD
HrBackupGetDatabaseNamesA PROTO :DWORD,:DWORD,:DWORD
HrBackupGetDatabaseNames equ <HrBackupGetDatabaseNamesA>

HrBackupGetDatabaseNamesW PROTO :DWORD,:DWORD,:DWORD
HrBackupOpenFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrBackupOpenFile equ <HrBackupOpenFileA>

HrBackupOpenFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrBackupPrepareA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HrBackupPrepare equ <HrBackupPrepareA>

HrBackupPrepareW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HrBackupRead PROTO :DWORD,:DWORD,:DWORD,:DWORD
HrBackupTruncateLogs PROTO :DWORD
HrRestoreEnd PROTO :DWORD
HrRestoreGetDatabaseLocationsA PROTO :DWORD,:DWORD,:DWORD
HrRestoreGetDatabaseLocations equ <HrRestoreGetDatabaseLocationsA>

HrRestoreGetDatabaseLocationsW PROTO :DWORD,:DWORD,:DWORD
HrRestorePrepareA PROTO :DWORD,:DWORD,:DWORD
HrRestorePrepare equ <HrRestorePrepareA>

HrRestorePrepareW PROTO :DWORD,:DWORD,:DWORD
HrRestoreRegisterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HrRestoreRegister equ <HrRestoreRegisterA>

HrRestoreRegisterComplete PROTO :DWORD,:DWORD
HrRestoreRegisterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HrSetCurrentBackupLogA PROTO :DWORD,:DWORD,:DWORD
HrSetCurrentBackupLog equ <HrSetCurrentBackupLogA>

HrSetCurrentBackupLogW PROTO :DWORD,:DWORD,:DWORD
I_HrCheckBackupLogs PROTO :DWORD
I_HrRestoreW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_BackupFree PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file edbbcli.inc
echo -----------------------------------------
ENDIF
