  ; ===========================================
  ; ntquery.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NTQUERY_INC
NTQUERY_INC equ <1>

BindIFilterFromStorage PROTO :DWORD,:DWORD,:DWORD
BindIFilterFromStream PROTO :DWORD,:DWORD,:DWORD
CIBuildQueryNode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIBuildQueryTree PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CICreateCommand PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIMakeICommand PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIRestrictionToFullTree PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CIState PROTO :DWORD,:DWORD,:DWORD
CITextToFullTree PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToFullTreeEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToSelectTree PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CITextToSelectTreeEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LoadIFilter PROTO :DWORD,:DWORD,:DWORD
LocateCatalogsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LocateCatalogs equ <LocateCatalogsA>

LocateCatalogsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetCatalogState PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ntquery.inc
echo -----------------------------------------
ENDIF
