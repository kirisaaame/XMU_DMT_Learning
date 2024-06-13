  ; ===========================================
  ; sadapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SADAPI_INC
SADAPI_INC equ <1>

MIDL_user_allocate PROTO :DWORD
MIDL_user_free PROTO :DWORD
NdrClientInitializeNew PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantArrayBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantArrayMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConformantArrayUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrConformantStringBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrConformantStringMarshall PROTO :DWORD,:DWORD,:DWORD
NdrConvert PROTO :DWORD,:DWORD
NdrFreeBuffer PROTO :DWORD
NdrGetBuffer PROTO :DWORD,:DWORD,:DWORD
NdrPointerBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrPointerMarshall PROTO :DWORD,:DWORD,:DWORD
NdrPointerUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
NdrSendReceive PROTO :DWORD,:DWORD
NdrSimpleStructBufferSize PROTO :DWORD,:DWORD,:DWORD
NdrSimpleStructMarshall PROTO :DWORD,:DWORD,:DWORD
NdrSimpleStructUnmarshall PROTO :DWORD,:DWORD,:DWORD,:DWORD
RpcBindingFree PROTO :DWORD
RpcBindingFromStringBindingW PROTO :DWORD,:DWORD
RpcBindingSetAuthInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcEpResolveBinding PROTO :DWORD,:DWORD
RpcNetworkIsProtseqValidW PROTO :DWORD
RpcStringBindingComposeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RpcStringFreeW PROTO :DWORD
SAD_EcGetProxies PROTO :DWORD,:DWORD,:DWORD
SAD_EcGetProxiesBI PROTO :DWORD,:DWORD,:DWORD
SAD_FreeBackupListNode PROTO :DWORD
SAD_FreeProxyListNode PROTO :DWORD
SAD_ScBindA PROTO :DWORD,:DWORD
SAD_ScBind equ <SAD_ScBindA>

SAD_ScBindW PROTO :DWORD,:DWORD
SAD_ScBulkCreateMultiProxyA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_ScBulkCreateMultiProxy equ <SAD_ScBulkCreateMultiProxyA>

SAD_ScBulkCreateMultiProxyW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_ScBulkCreateProxyA PROTO :DWORD,:DWORD,:DWORD
SAD_ScBulkCreateProxy equ <SAD_ScBulkCreateProxyA>

SAD_ScBulkCreateProxyW PROTO :DWORD,:DWORD,:DWORD
SAD_ScBulkProxyHaltA PROTO :DWORD,:DWORD
SAD_ScBulkProxyHalt equ <SAD_ScBulkProxyHaltA>

SAD_ScBulkProxyHaltW PROTO :DWORD,:DWORD
SAD_ScBulkUpdateMultiProxy PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SAD_ScGetBackupListNodeW PROTO :DWORD,:DWORD
SAD_ScGetBulkProxyStatusA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SAD_ScGetBulkProxyStatus equ <SAD_ScGetBulkProxyStatusA>

SAD_ScGetBulkProxyStatusW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SAD_ScIsProxyUniqueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_ScIsProxyUnique equ <SAD_ScIsProxyUniqueA>

SAD_ScIsProxyUniqueW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_ScRunDRACheck PROTO :DWORD,:DWORD
SAD_ScRunRIDA PROTO :DWORD
SAD_ScRunRID equ <SAD_ScRunRIDA>

SAD_ScRunRIDExA PROTO :DWORD,:DWORD,:DWORD
SAD_ScRunRIDEx equ <SAD_ScRunRIDExA>

SAD_ScRunRIDExW PROTO :DWORD,:DWORD,:DWORD
SAD_ScRunRIDW PROTO :DWORD
SAD_ScSaveGatewayTrackingData PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_ScSaveTrackingData PROTO :DWORD,:DWORD,:DWORD,:DWORD
SAD_Unbind PROTO :DWORD
UuidToStringW PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sadapi.inc
echo -----------------------------------------
ENDIF
