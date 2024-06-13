  ; ===========================================
  ; fcachdll.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF FCACHDLL_INC
FCACHDLL_INC equ <1>

AddRefContext PROTO :DWORD
AssociateContextWithName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AssociateFile PROTO :DWORD
AssociateFileEx PROTO :DWORD,:DWORD,:DWORD
CacheCreateFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
CacheRemoveFiles PROTO :DWORD,:DWORD
CacheRichCreateFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
CloseNonCachedFile PROTO :DWORD
CompleteDotStuffingOnWrites PROTO :DWORD,:DWORD
FIOInitialize PROTO :DWORD
FIOReadFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
FIOReadFileEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FIOTerminate PROTO 
FIOWriteFile PROTO :DWORD,:DWORD,:DWORD,:DWORD
FIOWriteFileEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindContextFromName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindOrCreateNameCache PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindSyncContextFromName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetDotStuffState PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFileSizeFromContext PROTO :DWORD,:DWORD
GetIsFileDotTerminated PROTO :DWORD
InitializeCache PROTO 
InsertFile PROTO :DWORD,:DWORD,:DWORD
InvalidateName PROTO :DWORD,:DWORD,:DWORD
ProduceDotStuffedContext PROTO :DWORD,:DWORD,:DWORD
ProduceDotStuffedContextInContext PROTO :DWORD,:DWORD,:DWORD,:DWORD
ReleaseContext PROTO :DWORD
ReleaseNameCache PROTO :DWORD
SetDotScanningOnReads PROTO :DWORD,:DWORD
SetDotScanningOnWrites PROTO :DWORD,:DWORD
SetDotStuffState PROTO :DWORD,:DWORD,:DWORD
SetDotStuffingOnWrites PROTO :DWORD,:DWORD,:DWORD
SetIsFileDotTerminated PROTO :DWORD,:DWORD
SetNameCacheSecurityFunction PROTO :DWORD,:DWORD
TerminateCache PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file fcachdll.inc
echo -----------------------------------------
ENDIF
