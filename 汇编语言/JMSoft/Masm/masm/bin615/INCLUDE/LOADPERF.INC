  ; ===========================================
  ; loadperf.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF LOADPERF_INC
LOADPERF_INC equ <1>

BackupPerfRegistryToFileW PROTO :DWORD,:DWORD
InstallPerfDllA PROTO :DWORD,:DWORD,:DWORD
InstallPerfDll equ <InstallPerfDllA>

InstallPerfDllW PROTO :DWORD,:DWORD,:DWORD
LoadMofFromInstalledServiceA PROTO :DWORD,:DWORD,:DWORD
LoadMofFromInstalledService equ <LoadMofFromInstalledServiceA>

LoadMofFromInstalledServiceW PROTO :DWORD,:DWORD,:DWORD
LoadPerfCounterTextStringsA PROTO :DWORD,:DWORD
LoadPerfCounterTextStrings equ <LoadPerfCounterTextStringsA>

LoadPerfCounterTextStringsW PROTO :DWORD,:DWORD
RestorePerfRegistryFromFileW PROTO :DWORD,:DWORD
SetServiceAsTrustedA PROTO :DWORD,:DWORD
SetServiceAsTrusted equ <SetServiceAsTrustedA>

SetServiceAsTrustedW PROTO :DWORD,:DWORD
UnloadPerfCounterTextStringsA PROTO :DWORD,:DWORD
UnloadPerfCounterTextStrings equ <UnloadPerfCounterTextStringsA>

UnloadPerfCounterTextStringsW PROTO :DWORD,:DWORD
UpdatePerfNameFilesA PROTO :DWORD,:DWORD,:DWORD,:DWORD
UpdatePerfNameFiles equ <UpdatePerfNameFilesA>

UpdatePerfNameFilesW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file loadperf.inc
echo -----------------------------------------
ENDIF
