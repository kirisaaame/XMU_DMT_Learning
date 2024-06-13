  ; ===========================================
  ; npptools.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NPPTOOLS_INC
NPPTOOLS_INC equ <1>

ReleaseEventSystem PROTO 
SendEvent PROTO :DWORD
WriteCrackedBlobToFile PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file npptools.inc
echo -----------------------------------------
ENDIF
