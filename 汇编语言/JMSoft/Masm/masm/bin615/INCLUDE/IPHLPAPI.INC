  ; ===========================================
  ; iphlpapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF IPHLPAPI_INC
IPHLPAPI_INC equ <1>

AddIPAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetArpEntTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetIfTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetIpAddrTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetIpForwardTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetIpNetTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetTcpTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
AllocateAndGetUdpTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateIpForwardEntry PROTO :DWORD
CreateIpNetEntry PROTO :DWORD
CreateProxyArpEntry PROTO :DWORD,:DWORD,:DWORD
DeleteIPAddress PROTO :DWORD
DeleteIpForwardEntry PROTO :DWORD
DeleteIpNetEntry PROTO :DWORD
DeleteProxyArpEntry PROTO :DWORD,:DWORD,:DWORD
EnableRouter PROTO :DWORD,:DWORD
FlushIpNetTable PROTO :DWORD
FlushIpNetTableFromStack PROTO :DWORD
GetAdapterIndex PROTO :DWORD,:DWORD
GetAdapterOrderMap PROTO 
GetAdaptersInfo PROTO :DWORD,:DWORD
GetBestInterface PROTO :DWORD,:DWORD
GetBestInterfaceFromStack PROTO :DWORD,:DWORD
GetBestRoute PROTO :DWORD,:DWORD,:DWORD
GetBestRouteFromStack PROTO :DWORD,:DWORD,:DWORD
GetFriendlyIfIndex PROTO :DWORD
GetIcmpStatistics PROTO :DWORD
GetIcmpStatsFromStack PROTO :DWORD
GetIfEntry PROTO :DWORD
GetIfEntryFromStack PROTO :DWORD,:DWORD,:DWORD
GetIfTable PROTO :DWORD,:DWORD,:DWORD
GetIfTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetIgmpList PROTO :DWORD,:DWORD,:DWORD
GetInterfaceInfo PROTO :DWORD,:DWORD
GetIpAddrTable PROTO :DWORD,:DWORD,:DWORD
GetIpAddrTableFromStack PROTO :DWORD,:DWORD,:DWORD
GetIpForwardTable PROTO :DWORD,:DWORD,:DWORD
GetIpForwardTableFromStack PROTO :DWORD,:DWORD,:DWORD
GetIpNetTable PROTO :DWORD,:DWORD,:DWORD
GetIpNetTableFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetIpStatistics PROTO :DWORD
GetIpStatsFromStack PROTO :DWORD
GetNetworkParams PROTO :DWORD,:DWORD
GetNumberOfInterfaces PROTO :DWORD
GetPerAdapterInfo PROTO :DWORD,:DWORD,:DWORD
GetRTTAndHopCount PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetTcpStatistics PROTO :DWORD
GetTcpStatsFromStack PROTO :DWORD
GetTcpTable PROTO :DWORD,:DWORD,:DWORD
GetTcpTableFromStack PROTO :DWORD,:DWORD,:DWORD
GetUdpStatistics PROTO :DWORD
GetUdpStatsFromStack PROTO :DWORD
GetUdpTable PROTO :DWORD,:DWORD,:DWORD
GetUdpTableFromStack PROTO :DWORD,:DWORD,:DWORD
GetUniDirectionalAdapterInfo PROTO :DWORD,:DWORD
InternalCreateIpForwardEntry PROTO :DWORD
InternalCreateIpNetEntry PROTO :DWORD
InternalDeleteIpForwardEntry PROTO :DWORD
InternalDeleteIpNetEntry PROTO :DWORD
InternalGetIfTable PROTO :DWORD,:DWORD,:DWORD
InternalGetIpAddrTable PROTO :DWORD,:DWORD,:DWORD
InternalGetIpForwardTable PROTO :DWORD,:DWORD,:DWORD
InternalGetIpNetTable PROTO :DWORD,:DWORD,:DWORD
InternalGetTcpTable PROTO :DWORD,:DWORD,:DWORD
InternalGetUdpTable PROTO :DWORD,:DWORD,:DWORD
InternalSetIfEntry PROTO :DWORD
InternalSetIpForwardEntry PROTO :DWORD
InternalSetIpNetEntry PROTO :DWORD
InternalSetIpStats PROTO :DWORD
InternalSetTcpEntry PROTO :DWORD
IpReleaseAddress PROTO :DWORD
IpRenewAddress PROTO :DWORD
IsLocalAddress PROTO :DWORD
NTPTimeToNTFileTime PROTO :DWORD,:DWORD,:DWORD
NTTimeToNTPTime PROTO :DWORD,:DWORD
NhGetGuidFromInterfaceName PROTO :DWORD,:DWORD,:DWORD,:DWORD
NhGetInterfaceNameFromGuid PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NhpAllocateAndGetInterfaceInfoFromStack PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NhpGetInterfaceIndexFromStack PROTO :DWORD,:DWORD
NotifyAddrChange PROTO :DWORD,:DWORD
NotifyRouteChange PROTO :DWORD,:DWORD
NotifyRouteChangeEx PROTO :DWORD,:DWORD,:DWORD
PfAddFiltersToInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PfAddGlobalFilterToInterface PROTO :DWORD,:DWORD
PfBindInterfaceToIPAddress PROTO :DWORD,:DWORD,:DWORD
PfBindInterfaceToIndex PROTO :DWORD,:DWORD,:DWORD,:DWORD
PfCreateInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PfDeleteInterface PROTO :DWORD
PfDeleteLog PROTO 
PfGetInterfaceStatistics PROTO :DWORD,:DWORD,:DWORD,:DWORD
PfMakeLog PROTO :DWORD
PfRebindFilters PROTO :DWORD,:DWORD
PfRemoveFilterHandles PROTO :DWORD,:DWORD,:DWORD
PfRemoveFiltersFromInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PfRemoveGlobalFilterFromInterface PROTO :DWORD,:DWORD
PfSetLogBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PfTestPacket PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PfUnBindInterface PROTO :DWORD
SendARP PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetAdapterIpAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetBlockRoutes PROTO :DWORD,:DWORD,:DWORD
SetIfEntry PROTO :DWORD
SetIfEntryToStack PROTO :DWORD,:DWORD
SetIpForwardEntry PROTO :DWORD
SetIpForwardEntryToStack PROTO :DWORD
SetIpMultihopRouteEntryToStack PROTO :DWORD
SetIpNetEntry PROTO :DWORD
SetIpNetEntryToStack PROTO :DWORD,:DWORD
SetIpRouteEntryToStack PROTO :DWORD
SetIpStatistics PROTO :DWORD
SetIpStatsToStack PROTO :DWORD
SetIpTTL PROTO :DWORD
SetProxyArpEntryToStack PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetRouteWithRef PROTO :DWORD
SetTcpEntry PROTO :DWORD
SetTcpEntryToStack PROTO :DWORD
UnenableRouter PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file iphlpapi.inc
echo -----------------------------------------
ENDIF
