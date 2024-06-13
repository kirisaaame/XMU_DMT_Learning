  ; ===========================================
  ; patchwiz.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF PATCHWIZ_INC
PATCHWIZ_INC equ <1>

UiCreatePatchPackageA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UiCreatePatchPackage equ <UiCreatePatchPackageA>

UiCreatePatchPackageW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file patchwiz.inc
echo -----------------------------------------
ENDIF
