  ; ===========================================
  ; randlib.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RANDLIB_INC
RANDLIB_INC equ <1>

A_SHAFinalNS PROTO :DWORD,:DWORD
A_SHAInit PROTO :DWORD
A_SHAUpdateNS PROTO :DWORD,:DWORD,:DWORD
AccessSeed PROTO :DWORD,:DWORD
DeInitRand PROTO :DWORD,:DWORD
DestroyCircularHash PROTO :DWORD
GatherCPUSpecificCounters PROTO :DWORD,:DWORD
GatherCPUSpecificCountersPrivileged PROTO :DWORD,:DWORD
GatherRandomKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
GatherRandomKeyFastUserMode PROTO :DWORD,:DWORD,:DWORD,:DWORD
GenRandom PROTO :DWORD,:DWORD,:DWORD
GetCircularHashValue PROTO :DWORD,:DWORD,:DWORD
InitCircularHash PROTO :DWORD,:DWORD,:DWORD,:DWORD
InitRand PROTO :DWORD,:DWORD
IsRNGWinNT PROTO 
MD4Final PROTO :DWORD
MD4Init PROTO :DWORD
MD4Update PROTO :DWORD,:DWORD,:DWORD
NewGenRandom PROTO :DWORD,:DWORD,:DWORD,:DWORD
NewGenRandomEx PROTO :DWORD,:DWORD,:DWORD
RandomFillBuffer PROTO :DWORD,:DWORD
ReadMMXCounters PROTO :DWORD,:DWORD,:DWORD
ReadP5Counters PROTO :DWORD,:DWORD,:DWORD
ReadSeed PROTO :DWORD,:DWORD
UpdateCircularHash PROTO :DWORD,:DWORD,:DWORD
VeryLargeHashUpdate PROTO :DWORD,:DWORD,:DWORD
WriteSeed PROTO :DWORD,:DWORD
rc4 PROTO :DWORD,:DWORD,:DWORD
rc4_key PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file randlib.inc
echo -----------------------------------------
ENDIF
