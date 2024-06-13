  ; ===========================================
  ; quartz.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF QUARTZ_INC
QUARTZ_INC equ <1>

AMGetErrorTextA PROTO :DWORD,:DWORD,:DWORD
AMGetErrorText equ <AMGetErrorTextA>

AMGetErrorTextW PROTO :DWORD,:DWORD,:DWORD
AmpFactorToDB PROTO :DWORD
DBToAmpFactor PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file quartz.inc
echo -----------------------------------------
ENDIF
