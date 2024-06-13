  ; ===========================================
  ; wow32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WOW32_INC
WOW32_INC equ <1>

CopyDropFilesFrom16 PROTO :DWORD
CopyDropFilesFrom32 PROTO :DWORD
GetCommHandle PROTO :DWORD
GetCommShadowMSR PROTO :DWORD
W32Dispatch PROTO 
W32HungAppNotifyThread PROTO :DWORD
W32Init PROTO 
WOW32DriverCallback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOW32ResolveHandle PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOW32ResolveMemory PROTO :DWORD
WOWCallback16 PROTO :DWORD,:DWORD
WOWCallback16Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WOWDirectedYield16 PROTO :DWORD
WOWFreeMetafile PROTO :DWORD
WOWGetVDMPointer PROTO :DWORD,:DWORD,:DWORD
WOWGetVDMPointerFix PROTO :DWORD,:DWORD,:DWORD
WOWGetVDMPointerUnfix PROTO :DWORD
WOWGlobalAlloc16 PROTO :DWORD,:DWORD
WOWGlobalAllocLock16 PROTO :DWORD,:DWORD,:DWORD
WOWGlobalFree16 PROTO :DWORD
WOWGlobalLock16 PROTO :DWORD
WOWGlobalLockSize16 PROTO :DWORD,:DWORD
WOWGlobalUnlock16 PROTO :DWORD
WOWGlobalUnlockFree16 PROTO :DWORD
WOWHandle16 PROTO :DWORD,:DWORD
WOWHandle32 PROTO :DWORD,:DWORD
WOWUseMciavi16 PROTO 
WOWYield16 PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file wow32.inc
echo -----------------------------------------
ENDIF
