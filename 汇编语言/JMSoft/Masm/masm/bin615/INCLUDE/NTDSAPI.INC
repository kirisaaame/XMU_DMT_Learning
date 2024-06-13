  ; ===========================================
  ; ntdsapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NTDSAPI_INC
NTDSAPI_INC equ <1>

DsAddSidHistoryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsAddSidHistory equ <DsAddSidHistoryA>

DsAddSidHistoryW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsBindA PROTO :DWORD,:DWORD,:DWORD
DsBind equ <DsBindA>

DsBindW PROTO :DWORD,:DWORD,:DWORD
DsBindWithCredA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsBindWithCred equ <DsBindWithCredA>

DsBindWithCredW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsBindWithSpnA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsBindWithSpn equ <DsBindWithSpnA>

DsBindWithSpnW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsClientMakeSpnForTargetServerA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsClientMakeSpnForTargetServer equ <DsClientMakeSpnForTargetServerA>

DsClientMakeSpnForTargetServerW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsCrackNamesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsCrackNames equ <DsCrackNamesA>

DsCrackNamesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsCrackSpnA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsCrackSpn equ <DsCrackSpnA>

DsCrackSpnW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsFreeDomainControllerInfoA PROTO :DWORD,:DWORD,:DWORD
DsFreeDomainControllerInfo equ <DsFreeDomainControllerInfoA>

DsFreeDomainControllerInfoW PROTO :DWORD,:DWORD,:DWORD
DsFreeNameResultA PROTO :DWORD
DsFreeNameResult equ <DsFreeNameResultA>

DsFreeNameResultW PROTO :DWORD
DsFreePasswordCredentials PROTO :DWORD
DsFreeSchemaGuidMapA PROTO :DWORD
DsFreeSchemaGuidMap equ <DsFreeSchemaGuidMapA>

DsFreeSchemaGuidMapW PROTO :DWORD
DsFreeSpnArrayA PROTO :DWORD,:DWORD
DsFreeSpnArray equ <DsFreeSpnArrayA>

DsFreeSpnArrayW PROTO :DWORD,:DWORD
DsGetDomainControllerInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetDomainControllerInfo equ <DsGetDomainControllerInfoA>

DsGetDomainControllerInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetSpnA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsGetSpn equ <DsGetSpnA>

DsGetSpnW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsInheritSecurityIdentityA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsInheritSecurityIdentity equ <DsInheritSecurityIdentityA>

DsInheritSecurityIdentityW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsListDomainsInSiteA PROTO :DWORD,:DWORD,:DWORD
DsListDomainsInSite equ <DsListDomainsInSiteA>

DsListDomainsInSiteW PROTO :DWORD,:DWORD,:DWORD
DsListInfoForServerA PROTO :DWORD,:DWORD,:DWORD
DsListInfoForServer equ <DsListInfoForServerA>

DsListInfoForServerW PROTO :DWORD,:DWORD,:DWORD
DsListRolesA PROTO :DWORD,:DWORD
DsListRoles equ <DsListRolesA>

DsListRolesW PROTO :DWORD,:DWORD
DsListServersForDomainInSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsListServersForDomainInSite equ <DsListServersForDomainInSiteA>

DsListServersForDomainInSiteW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsListServersInSiteA PROTO :DWORD,:DWORD,:DWORD
DsListServersInSite equ <DsListServersInSiteA>

DsListServersInSiteW PROTO :DWORD,:DWORD,:DWORD
DsListSitesA PROTO :DWORD,:DWORD
DsListSites equ <DsListSitesA>

DsListSitesW PROTO :DWORD,:DWORD
DsMakePasswordCredentialsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsMakePasswordCredentials equ <DsMakePasswordCredentialsA>

DsMakePasswordCredentialsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsMakeSpnA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsMakeSpn equ <DsMakeSpnA>

DsMakeSpnW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsMapSchemaGuidsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsMapSchemaGuids equ <DsMapSchemaGuidsA>

DsMapSchemaGuidsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsQuoteRdnValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsQuoteRdnValue equ <DsQuoteRdnValueA>

DsQuoteRdnValueW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsRemoveDsDomainA PROTO :DWORD,:DWORD
DsRemoveDsDomain equ <DsRemoveDsDomainA>

DsRemoveDsDomainW PROTO :DWORD,:DWORD
DsRemoveDsServerA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsRemoveDsServer equ <DsRemoveDsServerA>

DsRemoveDsServerW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaAdd equ <DsReplicaAddA>

DsReplicaAddW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaConsistencyCheck PROTO :DWORD,:DWORD,:DWORD
DsReplicaDelA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsReplicaDel equ <DsReplicaDelA>

DsReplicaDelW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsReplicaFreeInfo PROTO :DWORD,:DWORD
DsReplicaGetInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaModifyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaModify equ <DsReplicaModifyA>

DsReplicaModifyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaSyncA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsReplicaSync equ <DsReplicaSyncA>

DsReplicaSyncAllA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaSyncAll equ <DsReplicaSyncAllA>

DsReplicaSyncAllW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaSyncW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsReplicaUpdateRefsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsReplicaUpdateRefs equ <DsReplicaUpdateRefsA>

DsReplicaUpdateRefsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsServerRegisterSpnA PROTO :DWORD,:DWORD,:DWORD
DsServerRegisterSpn equ <DsServerRegisterSpnA>

DsServerRegisterSpnW PROTO :DWORD,:DWORD,:DWORD
DsUnBindA PROTO :DWORD
DsUnBind equ <DsUnBindA>

DsUnBindW PROTO :DWORD
DsUnquoteRdnValueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsUnquoteRdnValue equ <DsUnquoteRdnValueA>

DsUnquoteRdnValueW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DsWriteAccountSpnA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DsWriteAccountSpn equ <DsWriteAccountSpnA>

DsWriteAccountSpnW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ntdsapi.inc
echo -----------------------------------------
ENDIF
