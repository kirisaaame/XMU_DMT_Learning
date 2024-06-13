  ; ===========================================
  ; dsound.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DSOUND_INC
DSOUND_INC equ <1>

DirectSoundCaptureCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundCaptureEnumerateA PROTO :DWORD,:DWORD
DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateA>

DirectSoundCaptureEnumerateW PROTO :DWORD,:DWORD
DirectSoundCreate PROTO :DWORD,:DWORD,:DWORD
DirectSoundEnumerateA PROTO :DWORD,:DWORD
DirectSoundEnumerate equ <DirectSoundEnumerateA>

DirectSoundEnumerateW PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dsound.inc
echo -----------------------------------------
ENDIF
