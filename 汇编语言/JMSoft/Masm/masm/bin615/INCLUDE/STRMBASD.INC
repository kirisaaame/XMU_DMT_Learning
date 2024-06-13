  ; ===========================================
  ; strmbasd.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF STRMBASD_INC
STRMBASD_INC equ <1>

AMGetWideString PROTO :DWORD,:DWORD
AMovieDllRegisterServer2 PROTO :DWORD
AMovieDllRegisterServer PROTO 
AMovieDllUnregisterServer PROTO 
AMovieSetupRegisterFilter2 PROTO :DWORD,:DWORD,:DWORD
AMovieSetupRegisterFilter PROTO :DWORD,:DWORD,:DWORD
AMovieSetupRegisterServer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AMovieSetupUnregisterServer PROTO :DWORD,:DWORD,:DWORD,:DWORD
ContainsPalette PROTO :DWORD
ConvertVideoInfoToVideoInfo2 PROTO :DWORD
CreateAudioMediaType PROTO :DWORD,:DWORD,:DWORD
CreateMemoryAllocator PROTO :DWORD
CreatePosPassThru PROTO :DWORD,:DWORD,:DWORD,:DWORD
DirectDrawCreateFromDevice PROTO :DWORD,:DWORD,:DWORD
DirectDrawCreateFromDeviceEx PROTO :DWORD,:DWORD,:DWORD
DllCanUnloadNow PROTO 
DllEntryPoint PROTO :DWORD,:DWORD,:DWORD
DllGetClassObject PROTO :DWORD,:DWORD,:DWORD
EliminateSubKey PROTO :DWORD,:DWORD
FreeBSTR PROTO :DWORD
GetBitCount PROTO :DWORD
GetBitmapFormatSize PROTO :DWORD
GetBitmapPalette PROTO :DWORD
GetBitmapSize PROTO :DWORD
GetBitmapSubtype PROTO :DWORD
GetInterface PROTO :DWORD,:DWORD
GetSubtypeNameA PROTO :DWORD
GetSubtypeName equ <GetSubtypeNameA>

GetSubtypeNameW PROTO :DWORD
GetTrueColorType PROTO :DWORD
IsEqualGUID PROTO :DWORD,:DWORD
ReadInt PROTO :DWORD,:DWORD
RegisterAllServers PROTO :DWORD,:DWORD
WriteBSTR PROTO :DWORD,:DWORD
WriteInt PROTO :DWORD,:DWORD
memmoveInternal PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file strmbasd.inc
echo -----------------------------------------
ENDIF
