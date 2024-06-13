  ; ===========================================
  ; mobsync.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MOBSYNC_INC
MOBSYNC_INC equ <1>

RunDllRegister PROTO :DWORD,:DWORD,:DWORD,:DWORD
SyncMgrResolveConflictA PROTO :DWORD,:DWORD
SyncMgrResolveConflict equ <SyncMgrResolveConflictA>

SyncMgrResolveConflictW PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mobsync.inc
echo -----------------------------------------
ENDIF
