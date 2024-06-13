  ; ===========================================
  ; comdlg32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF COMDLG32_INC
COMDLG32_INC equ <1>

ChooseColorA PROTO :DWORD
ChooseColor equ <ChooseColorA>

ChooseColorW PROTO :DWORD
ChooseFontA PROTO :DWORD
ChooseFont equ <ChooseFontA>

ChooseFontW PROTO :DWORD
CommDlgExtendedError PROTO 
FindTextA PROTO :DWORD
FindText equ <FindTextA>

FindTextW PROTO :DWORD
FormatCharDlgProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFileTitleA PROTO :DWORD,:DWORD,:DWORD
GetFileTitle equ <GetFileTitleA>

GetFileTitleW PROTO :DWORD,:DWORD,:DWORD
GetOpenFileNameA PROTO :DWORD
GetOpenFileName equ <GetOpenFileNameA>

GetOpenFileNameW PROTO :DWORD
GetSaveFileNameA PROTO :DWORD
GetSaveFileName equ <GetSaveFileNameA>

GetSaveFileNameW PROTO :DWORD
LoadAlterBitmap PROTO :DWORD,:DWORD,:DWORD
PageSetupDlgA PROTO :DWORD
PageSetupDlg equ <PageSetupDlgA>

PageSetupDlgW PROTO :DWORD
PrintDlgA PROTO :DWORD
PrintDlg equ <PrintDlgA>

PrintDlgExA PROTO :DWORD
PrintDlgEx equ <PrintDlgExA>

PrintDlgExW PROTO :DWORD
PrintDlgW PROTO :DWORD
ReplaceTextA PROTO :DWORD
ReplaceText equ <ReplaceTextA>

ReplaceTextW PROTO :DWORD
Ssync_ANSI_UNICODE_Struct_For_WOW PROTO :DWORD,:DWORD,:DWORD
WantArrows PROTO :DWORD,:DWORD,:DWORD,:DWORD
dwLBSubclass PROTO :DWORD,:DWORD,:DWORD,:DWORD
dwOKSubclass PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file comdlg32.inc
echo -----------------------------------------
ENDIF
