  ; ===========================================
  ; rpcns4.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RPCNS4_INC
RPCNS4_INC equ <1>

I_GetDefaultEntrySyntax PROTO 
I_RpcNsGetBuffer PROTO :DWORD
I_RpcNsRaiseException PROTO :DWORD,:DWORD
I_RpcNsSendReceive PROTO :DWORD,:DWORD
I_RpcReBindBuffer PROTO :DWORD
RpcIfIdVectorFree PROTO :DWORD
RpcNsBindingExportA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingExport equ <RpcNsBindingExportA>

RpcNsBindingExportPnPA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingExportPnP equ <RpcNsBindingExportPnPA>

RpcNsBindingExportPnPW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingExportW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingImportBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingImportBegin equ <RpcNsBindingImportBeginA>

RpcNsBindingImportBeginW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingImportDone PROTO :DWORD
RpcNsBindingImportNext PROTO :DWORD,:DWORD
RpcNsBindingLookupBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingLookupBegin equ <RpcNsBindingLookupBeginA>

RpcNsBindingLookupBeginW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingLookupDone PROTO :DWORD
RpcNsBindingLookupNext PROTO :DWORD,:DWORD
RpcNsBindingSelect PROTO :DWORD,:DWORD
RpcNsBindingUnexportA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingUnexport equ <RpcNsBindingUnexportA>

RpcNsBindingUnexportPnPA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingUnexportPnP equ <RpcNsBindingUnexportPnPA>

RpcNsBindingUnexportPnPW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsBindingUnexportW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsEntryExpandNameA PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryExpandName equ <RpcNsEntryExpandNameA>

RpcNsEntryExpandNameW PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryObjectInqBeginA PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryObjectInqBegin equ <RpcNsEntryObjectInqBeginA>

RpcNsEntryObjectInqBeginW PROTO :DWORD,:DWORD,:DWORD
RpcNsEntryObjectInqDone PROTO :DWORD
RpcNsEntryObjectInqNext PROTO :DWORD,:DWORD
RpcNsGroupDeleteA PROTO :DWORD,:DWORD
RpcNsGroupDelete equ <RpcNsGroupDeleteA>

RpcNsGroupDeleteW PROTO :DWORD,:DWORD
RpcNsGroupMbrAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrAdd equ <RpcNsGroupMbrAddA>

RpcNsGroupMbrAddW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrInqBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrInqBegin equ <RpcNsGroupMbrInqBeginA>

RpcNsGroupMbrInqBeginW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrInqDone PROTO :DWORD
RpcNsGroupMbrInqNextA PROTO :DWORD,:DWORD
RpcNsGroupMbrInqNext equ <RpcNsGroupMbrInqNextA>

RpcNsGroupMbrInqNextW PROTO :DWORD,:DWORD
RpcNsGroupMbrRemoveA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsGroupMbrRemove equ <RpcNsGroupMbrRemoveA>

RpcNsGroupMbrRemoveW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcNsMgmtBindingUnexportA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsMgmtBindingUnexport equ <RpcNsMgmtBindingUnexportA>

RpcNsMgmtBindingUnexportW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsMgmtEntryCreateA PROTO :DWORD,:DWORD
RpcNsMgmtEntryCreate equ <RpcNsMgmtEntryCreateA>

RpcNsMgmtEntryCreateW PROTO :DWORD,:DWORD
RpcNsMgmtEntryDeleteA PROTO :DWORD,:DWORD
RpcNsMgmtEntryDelete equ <RpcNsMgmtEntryDeleteA>

RpcNsMgmtEntryDeleteW PROTO :DWORD,:DWORD
RpcNsMgmtEntryInqIfIdsA PROTO :DWORD,:DWORD,:DWORD
RpcNsMgmtEntryInqIfIds equ <RpcNsMgmtEntryInqIfIdsA>

RpcNsMgmtEntryInqIfIdsW PROTO :DWORD,:DWORD,:DWORD
RpcNsMgmtHandleSetExpAge PROTO :DWORD,:DWORD
RpcNsMgmtInqExpAge PROTO :DWORD
RpcNsMgmtSetExpAge PROTO :DWORD
RpcNsProfileDeleteA PROTO :DWORD,:DWORD
RpcNsProfileDelete equ <RpcNsProfileDeleteA>

RpcNsProfileDeleteW PROTO :DWORD,:DWORD
RpcNsProfileEltAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltAdd equ <RpcNsProfileEltAddA>

RpcNsProfileEltAddW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqBeginA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqBegin equ <RpcNsProfileEltInqBeginA>

RpcNsProfileEltInqBeginW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqDone PROTO :DWORD
RpcNsProfileEltInqNextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltInqNext equ <RpcNsProfileEltInqNextA>

RpcNsProfileEltInqNextW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltRemoveA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcNsProfileEltRemove equ <RpcNsProfileEltRemoveA>

RpcNsProfileEltRemoveW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file rpcns4.inc
echo -----------------------------------------
ENDIF
