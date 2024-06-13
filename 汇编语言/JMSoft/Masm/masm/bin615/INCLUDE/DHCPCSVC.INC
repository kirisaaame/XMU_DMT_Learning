  ; ===========================================
  ; dhcpcsvc.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DHCPCSVC_INC
DHCPCSVC_INC equ <1>

DhcpAcquireParameters PROTO :DWORD
DhcpCApiCleanup PROTO 
DhcpCApiInitialize PROTO :DWORD
DhcpDeRegisterOptions PROTO :DWORD
DhcpDeRegisterParamChange PROTO :DWORD,:DWORD,:DWORD
DhcpDelPersistentRequestParams PROTO :DWORD,:DWORD
DhcpEnumClasses PROTO :DWORD,:DWORD,:DWORD,:DWORD
DhcpHandlePnPEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpLeaseIpAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpLeaseIpAddressEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpNotifyConfigChange PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpNotifyConfigChangeEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpOpenGlobalEvent PROTO 
DhcpPersistentRequestParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpQueryHWInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRegisterOptions PROTO :DWORD,:DWORD,:DWORD,:DWORD
DhcpRegisterParamChange PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpReleaseIpAddressLease PROTO :DWORD,:DWORD
DhcpReleaseIpAddressLeaseEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
DhcpReleaseParameters PROTO :DWORD
DhcpRemoveDNSRegistrations PROTO 
DhcpRenewIpAddressLease PROTO :DWORD,:DWORD,:DWORD,:DWORD
DhcpRenewIpAddressLeaseEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRequestOptions PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpRequestParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DhcpStaticRefreshParams PROTO :DWORD
DhcpUndoRequestParams PROTO :DWORD,:DWORD,:DWORD,:DWORD
McastApiCleanup PROTO 
McastApiStartup PROTO :DWORD
McastEnumerateScopes PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
McastGenUID PROTO :DWORD
McastReleaseAddress PROTO :DWORD,:DWORD,:DWORD
McastRenewAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD
McastRequestAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ServiceEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dhcpcsvc.inc
echo -----------------------------------------
ENDIF
