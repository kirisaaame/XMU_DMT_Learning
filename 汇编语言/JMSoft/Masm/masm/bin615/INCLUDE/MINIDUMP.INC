  ; ===========================================
  ; minidump.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MINIDUMP_INC
MINIDUMP_INC equ <1>

AllocMemory PROTO :DWORD
BindImports PROTO 
CalculateSizeForModules PROTO :DWORD,:DWORD
CalculateSizeForSystemInfo PROTO :DWORD,:DWORD
CalculateSizeForThreads PROTO :DWORD,:DWORD
CalculateStreamInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ChangeDefaultFields PROTO :DWORD,:DWORD
CheckSum PROTO :DWORD,:DWORD,:DWORD
ExecuteCallbacks PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FailCreateToolhelp32Snapshot PROTO :DWORD,:DWORD
FailEnumProcessModules PROTO :DWORD,:DWORD,:DWORD,:DWORD
FailGetModuleFileNameExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FailModule32First PROTO :DWORD,:DWORD
FailModule32Next PROTO :DWORD,:DWORD
FailNtOpenThread PROTO :DWORD,:DWORD,:DWORD,:DWORD
FailNtQueryInformationProcess PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FailNtQueryInformationThread PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FailNtQuerySystemInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
FailOpenThread PROTO :DWORD,:DWORD,:DWORD
FailReadDumpStream PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FailThread32First PROTO :DWORD,:DWORD
FailThread32Next PROTO :DWORD,:DWORD
FailWriteDump PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FreeExceptionInfo PROTO :DWORD
FreeExceptionPointers PROTO :DWORD
FreeImports PROTO 
FreeMemory PROTO :DWORD
GenAllocateModuleObject PROTO :DWORD,:DWORD
GenAllocateProcessObject PROTO :DWORD,:DWORD
GenAllocateThreadObject PROTO :DWORD,:DWORD
GenFreeModuleObject PROTO :DWORD
GenFreeProcessInfo PROTO :DWORD
GenFreeProcessObject PROTO :DWORD
GenFreeThreadObject PROTO :DWORD
GenGetDataContributors PROTO :DWORD,:DWORD
GenGetDebugRecord PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GenGetProcessInfo PROTO :DWORD,:DWORD,:DWORD
GenGetSystemType PROTO :DWORD,:DWORD,:DWORD,:DWORD
GenGetTibAddress PROTO :DWORD
GenGetVersionInfo PROTO :DWORD,:DWORD
GenOpenMapping PROTO :DWORD,:DWORD
GenOpenThread PROTO :DWORD,:DWORD,:DWORD
GetCpuInformation PROTO :DWORD
GetExceptionInfo PROTO :DWORD,:DWORD,:DWORD
GetFileVersionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFileVersionInfo equ <GetFileVersionInfoA>

GetFileVersionInfoSizeA PROTO :DWORD,:DWORD
GetFileVersionInfoSize equ <GetFileVersionInfoSizeA>

MarshalExceptionPointers PROTO :DWORD,:DWORD,:DWORD
MiniDumpFree PROTO 
MiniDumpReadDumpStream PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MiniDumpSetup PROTO 
MiniDumpWriteDump PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
Nt4EnumProcessModules PROTO :DWORD,:DWORD,:DWORD,:DWORD
Nt4FindModule PROTO :DWORD,:DWORD,:DWORD
Nt4GetModuleFileNameExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
Nt4GetProcessInfo PROTO :DWORD,:DWORD,:DWORD
Nt4OpenThread PROTO :DWORD,:DWORD,:DWORD
NtxAllocateModuleObject PROTO :DWORD,:DWORD
NtxGetProcessInfo PROTO :DWORD,:DWORD,:DWORD
NtxGetTibAddress PROTO :DWORD
ProcessThread32First PROTO :DWORD,:DWORD,:DWORD
ProcessThread32Next PROTO :DWORD,:DWORD,:DWORD
ReAllocMemory PROTO :DWORD,:DWORD
VerQueryValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
VerQueryValue equ <VerQueryValueA>

WinFree PROTO 
WinGetModuleSize PROTO :DWORD
WinGetProcessInfo PROTO :DWORD,:DWORD,:DWORD
WinInitialize PROTO 
WinOpenThread PROTO :DWORD,:DWORD,:DWORD
WinpCheckOpenThread PROTO 
WinpCheckThread PROTO :DWORD
WinpGetAllocHandleFromStream PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinpGetCurrentPdb PROTO 
WinpGetCurrentTib PROTO 
WinpGetObfuscator PROTO 
WinpInitAllocHandle PROTO 
WinpOpenThreadInternal PROTO :DWORD,:DWORD,:DWORD
WinpTidToTDB PROTO :DWORD
WriteAtOffset PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteDirectoryEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteDirectoryTable PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteDumpData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteException PROTO :DWORD,:DWORD,:DWORD
WriteHeader PROTO :DWORD,:DWORD
WriteMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteMemoryFromProcess PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteMemoryListHeader PROTO :DWORD,:DWORD
WriteModule PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteModuleList PROTO :DWORD,:DWORD,:DWORD
WriteOther PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteStringToPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
WriteSystemInfo PROTO :DWORD,:DWORD
WriteThread PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteThreadList PROTO :DWORD,:DWORD,:DWORD
WriteUserStreams PROTO :DWORD,:DWORD,:DWORD,:DWORD
X86CpuId PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_xxxAddressInSectionTable PROTO :DWORD,:DWORD,:DWORD
xxxAddressInSectionTable PROTO :DWORD,:DWORD,:DWORD
xxxImageDirectoryEntryToData PROTO :DWORD,:DWORD,:DWORD,:DWORD
xxxImageNtHeader PROTO :DWORD
xxxSectionTableFromVirtualAddress PROTO :DWORD,:DWORD,:DWORD
xxxpImageDirectoryEntryToData32 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
xxxpImageDirectoryEntryToData64 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file minidump.inc
echo -----------------------------------------
ENDIF
