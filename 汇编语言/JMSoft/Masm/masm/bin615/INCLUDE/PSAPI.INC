  ; ===========================================
  ; psapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF PSAPI_INC
PSAPI_INC equ <1>

EmptyWorkingSet PROTO :DWORD
EnumDeviceDrivers PROTO :DWORD,:DWORD,:DWORD
EnumProcessModules PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnumProcesses PROTO :DWORD,:DWORD,:DWORD
GetDeviceDriverBaseNameA PROTO :DWORD,:DWORD,:DWORD
GetDeviceDriverBaseName equ <GetDeviceDriverBaseNameA>

GetDeviceDriverBaseNameW PROTO :DWORD,:DWORD,:DWORD
GetDeviceDriverFileNameA PROTO :DWORD,:DWORD,:DWORD
GetDeviceDriverFileName equ <GetDeviceDriverFileNameA>

GetDeviceDriverFileNameW PROTO :DWORD,:DWORD,:DWORD
GetMappedFileNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetMappedFileName equ <GetMappedFileNameA>

GetMappedFileNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetModuleBaseNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetModuleBaseName equ <GetModuleBaseNameA>

GetModuleBaseNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetModuleFileNameExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetModuleFileNameEx equ <GetModuleFileNameExA>

GetModuleFileNameExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetModuleInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetProcessMemoryInfo PROTO :DWORD,:DWORD,:DWORD
GetWsChanges PROTO :DWORD,:DWORD,:DWORD
InitializeProcessForWsWatch PROTO :DWORD
QueryWorkingSet PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file psapi.inc
echo -----------------------------------------
ENDIF
