  ; ===========================================
  ; adptif.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ADPTIF_INC
ADPTIF_INC equ <1>

CreateSocketPort PROTO :DWORD
DeleteSocketPort PROTO :DWORD
FwBindFwInterfaceToAdapter PROTO :DWORD,:DWORD
FwConnectionRequestFailed PROTO :DWORD
FwCreateInterface PROTO :DWORD,:DWORD,:DWORD
FwDeleteInterface PROTO :DWORD
FwDisableFwInterface PROTO :DWORD
FwEnableFwInterface PROTO :DWORD
FwGetInterface PROTO :DWORD,:DWORD,:DWORD
FwGetNotificationResult PROTO :DWORD,:DWORD
FwGetStaticNetbiosNames PROTO :DWORD,:DWORD,:DWORD
FwIsStarted PROTO :DWORD
FwNotifyConnectionRequest PROTO :DWORD,:DWORD,:DWORD
FwSetInterface PROTO :DWORD,:DWORD
FwSetStaticNetbiosNames PROTO :DWORD,:DWORD,:DWORD
FwStart PROTO :DWORD,:DWORD
FwStop PROTO 
FwUnbindFwInterfaceFromAdapter PROTO :DWORD
FwUpdateConfig PROTO :DWORD
FwUpdateRouteTable PROTO :DWORD,:DWORD,:DWORD
GetAdapterNameFromMacAddrW PROTO :DWORD,:DWORD,:DWORD
GetAdapterNameW PROTO :DWORD,:DWORD,:DWORD
GetFilters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxAdjustIoCompletionParams PROTO :DWORD,:DWORD,:DWORD
IpxCreateAdapterConfigurationPort PROTO :DWORD,:DWORD
IpxDeleteAdapterConfigurationPort PROTO :DWORD
IpxDoesRouteExist PROTO :DWORD,:DWORD
IpxGetAdapterConfig PROTO :DWORD,:DWORD
IpxGetAdapterList PROTO :DWORD,:DWORD,:DWORD
IpxGetOverlappedResult PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedAdapterConfigurationStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxGetQueuedCompletionStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxPostQueuedCompletionStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
IpxRecvPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxSendPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IpxWanCreateAdapterConfigurationPort PROTO :DWORD,:DWORD
IpxWanQueryInactivityTimer PROTO :DWORD,:DWORD,:DWORD
IpxWanSetAdapterConfiguration PROTO :DWORD,:DWORD
ServiceMain PROTO :DWORD,:DWORD
SetFilters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file adptif.inc
echo -----------------------------------------
ENDIF
