  ; ===========================================
  ; dapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DAPI_INC
DAPI_INC equ <1>

BatchExportA PROTO :DWORD
BatchExport equ <BatchExportA>

BatchExportW PROTO :DWORD
BatchImportA PROTO :DWORD
BatchImport equ <BatchImportA>

BatchImportW PROTO :DWORD
DAPIAllocBuffer PROTO :DWORD,:DWORD
DAPIEnd PROTO :DWORD
DAPIFreeMemory PROTO :DWORD
DAPIGetSiteInfoA PROTO :DWORD,:DWORD,:DWORD
DAPIGetSiteInfo equ <DAPIGetSiteInfoA>

DAPIGetSiteInfoW PROTO :DWORD,:DWORD,:DWORD
DAPIReadA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DAPIRead equ <DAPIReadA>

DAPIReadW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DAPIStartA PROTO :DWORD,:DWORD
DAPIStart equ <DAPIStartA>

DAPIStartW PROTO :DWORD,:DWORD
DAPIUninitialize PROTO :DWORD
DAPIWriteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DAPIWrite equ <DAPIWriteA>

DAPIWriteW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DapiLibMain PROTO :DWORD,:DWORD,:DWORD
NTExportA PROTO :DWORD
NTExport equ <NTExportA>

NTExportW PROTO :DWORD
NWExportA PROTO :DWORD
NWExport equ <NWExportA>

NWExportW PROTO :DWORD
SchemaPreloadA PROTO :DWORD,:DWORD
SchemaPreload equ <SchemaPreloadA>

SchemaPreloadW PROTO :DWORD,:DWORD
_BatchExportA PROTO :DWORD
_BatchExport equ <_BatchExportA>


ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dapi.inc
echo -----------------------------------------
ENDIF
