  ; ===========================================
  ; shfolder.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SHFOLDER_INC
SHFOLDER_INC equ <1>

SHGetFolderPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFolderPath equ <SHGetFolderPathA>

SHGetFolderPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file shfolder.inc
echo -----------------------------------------
ENDIF
