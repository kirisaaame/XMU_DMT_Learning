  ; ===========================================
  ; url.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF URL_INC
URL_INC equ <1>

AddMIMEFileTypesPS PROTO :DWORD,:DWORD
InetIsOffline PROTO :DWORD
MIMEAssociationDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MIMEAssociationDialog equ <MIMEAssociationDialogA>

MIMEAssociationDialogW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetInetOffline PROTO :DWORD
TranslateURLA PROTO :DWORD,:DWORD,:DWORD
TranslateURL equ <TranslateURLA>

TranslateURLW PROTO :DWORD,:DWORD,:DWORD
URLAssociationDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLAssociationDialog equ <URLAssociationDialogA>

URLAssociationDialogW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file url.inc
echo -----------------------------------------
ENDIF
