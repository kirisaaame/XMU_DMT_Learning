  ; ===========================================
  ; oledlg.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF OLEDLG_INC
OLEDLG_INC equ <1>

OleUIAddVerbMenuA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleUIAddVerbMenu equ <OleUIAddVerbMenuA>

OleUIAddVerbMenuW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleUIBusyA PROTO :DWORD
OleUIBusy equ <OleUIBusyA>

OleUIBusyW PROTO :DWORD
OleUICanConvertOrActivateAs PROTO :DWORD,:DWORD,:DWORD
OleUIChangeIconA PROTO :DWORD
OleUIChangeIcon equ <OleUIChangeIconA>

OleUIChangeIconW PROTO :DWORD
OleUIChangeSourceA PROTO :DWORD
OleUIChangeSource equ <OleUIChangeSourceA>

OleUIChangeSourceW PROTO :DWORD
OleUIConvertA PROTO :DWORD
OleUIConvert equ <OleUIConvertA>

OleUIConvertW PROTO :DWORD
OleUIEditLinksA PROTO :DWORD
OleUIEditLinks equ <OleUIEditLinksA>

OleUIEditLinksW PROTO :DWORD
OleUIInsertObjectA PROTO :DWORD
OleUIInsertObject equ <OleUIInsertObjectA>

OleUIInsertObjectW PROTO :DWORD
OleUIObjectPropertiesA PROTO :DWORD
OleUIObjectProperties equ <OleUIObjectPropertiesA>

OleUIObjectPropertiesW PROTO :DWORD
OleUIPasteSpecialA PROTO :DWORD
OleUIPasteSpecial equ <OleUIPasteSpecialA>

OleUIPasteSpecialW PROTO :DWORD
OleUIUpdateLinksA PROTO :DWORD,:DWORD,:DWORD,:DWORD
OleUIUpdateLinks equ <OleUIUpdateLinksA>

OleUIUpdateLinksW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file oledlg.inc
echo -----------------------------------------
ENDIF
