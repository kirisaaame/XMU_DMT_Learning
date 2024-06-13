  ; ===========================================
  ; dmapiw32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DMAPIW32_INC
DMAPIW32_INC equ <1>

DBGMEM_AddRef PROTO :DWORD
DBGMEM_Alloc PROTO :DWORD,:DWORD
DBGMEM_DidAlloc PROTO :DWORD,:DWORD
DBGMEM_Free PROTO :DWORD,:DWORD
DBGMEM_GetSize PROTO :DWORD,:DWORD
DBGMEM_HeapMinimize PROTO :DWORD
DBGMEM_QueryInterface PROTO :DWORD,:DWORD,:DWORD
DBGMEM_Realloc PROTO :DWORD,:DWORD,:DWORD
DBGMEM_Release PROTO :DWORD
DBGMEM_ReportLeak PROTO :DWORD,:DWORD
DBGMEM_ValidatePblk PROTO :DWORD,:DWORD,:DWORD
DBGMEM_ValidatePv PROTO :DWORD,:DWORD,:DWORD
DebugOutputFn PROTO :DWORD
IsDBGServiceAnExe PROTO 
LogIt PROTO :DWORD,:DWORD
MNLS_lstrlenW PROTO :DWORD
MessageBoxFn PROTO :DWORD,:DWORD,:DWORD
MessageBoxFnThreadMain PROTO :DWORD
PblkDequeue PROTO :DWORD
PblkEnqueue PROTO :DWORD
VMValidatePvEx PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dmapiw32.inc
echo -----------------------------------------
ENDIF
