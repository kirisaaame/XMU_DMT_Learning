  ; ===========================================
  ; htmlhelp.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF HTMLHELP_INC
HTMLHELP_INC equ <1>

HtmlHelpA PROTO :DWORD,:DWORD,:DWORD,:DWORD
HtmlHelp equ <HtmlHelpA>

HtmlHelpW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file htmlhelp.inc
echo -----------------------------------------
ENDIF
