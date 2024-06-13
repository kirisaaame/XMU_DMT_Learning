  ; ===========================================
  ; dsuiext.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DSUIEXT_INC
DSUIEXT_INC equ <1>

CheckDsPolicy PROTO :DWORD,:DWORD
DllMain PROTO :DWORD,:DWORD,:DWORD
DsBrowseForContainerA PROTO :DWORD
DsBrowseForContainer equ <DsBrowseForContainerA>

DsBrowseForContainerW PROTO :DWORD
DsGetFriendlyClassName PROTO :DWORD,:DWORD,:DWORD
DsGetIcon PROTO :DWORD,:DWORD,:DWORD,:DWORD
FormatDirectoryName PROTO :DWORD,:DWORD,:DWORD
GetArrayContents PROTO :DWORD,:DWORD,:DWORD
GetDisplayNameFromADsPath PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetStringElementA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetStringElement equ <GetStringElementA>

GetStringElementW PROTO :DWORD,:DWORD,:DWORD,:DWORD
LocalAllocStringA2W PROTO :DWORD,:DWORD
LocalAllocStringA PROTO :DWORD,:DWORD
LocalAllocString equ <LocalAllocStringA>

LocalAllocStringLenA PROTO :DWORD,:DWORD
LocalAllocStringLen equ <LocalAllocStringLenA>

LocalAllocStringLenW PROTO :DWORD,:DWORD
LocalAllocStringW2A PROTO :DWORD,:DWORD
LocalAllocStringW2 equ <LocalAllocStringW2A>

LocalAllocStringW PROTO :DWORD,:DWORD
LocalFreeStringA PROTO :DWORD
LocalFreeString equ <LocalFreeStringA>

LocalFreeStringW PROTO :DWORD
LocalQueryStringA PROTO :DWORD,:DWORD,:DWORD
LocalQueryString equ <LocalQueryStringA>

LocalQueryStringW PROTO :DWORD,:DWORD,:DWORD
ObjectClassFromSearchColumn PROTO :DWORD,:DWORD
PutStringElementA PROTO :DWORD,:DWORD,:DWORD
PutStringElement equ <PutStringElementA>

PutStringElementW PROTO :DWORD,:DWORD,:DWORD
ShowDirectoryUI PROTO 
StringDPA_AppendStringA PROTO :DWORD,:DWORD,:DWORD
StringDPA_AppendString equ <StringDPA_AppendStringA>

StringDPA_AppendStringW PROTO :DWORD,:DWORD,:DWORD
StringDPA_DeleteString PROTO :DWORD,:DWORD
StringDPA_Destroy PROTO :DWORD
StringDPA_InsertStringA PROTO :DWORD,:DWORD,:DWORD
StringDPA_InsertString equ <StringDPA_InsertStringA>

StringDPA_InsertStringW PROTO :DWORD,:DWORD,:DWORD
StringFromSearchColumn PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dsuiext.inc
echo -----------------------------------------
ENDIF
