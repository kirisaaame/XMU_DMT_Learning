  ; ===========================================
  ; olepro32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF OLEPRO32_INC
OLEPRO32_INC equ <1>

OleCreateFontIndirect PROTO :DWORD,:DWORD,:DWORD
OleCreatePictureIndirect PROTO :DWORD,:DWORD,:DWORD,:DWORD
OleCreatePropertyFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleCreatePropertyFrameIndirect PROTO :DWORD
OleIconToCursor PROTO :DWORD,:DWORD
OleLoadPicture PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleTranslateColor PROTO :DWORD,:DWORD,:DWORD
_OleCreateFontIndirect PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file olepro32.inc
echo -----------------------------------------
ENDIF
