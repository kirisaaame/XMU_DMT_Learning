  ; ===========================================
  ; clusapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CLUSAPI_INC
CLUSAPI_INC equ <1>

AddClusterResourceDependency PROTO :DWORD,:DWORD
AddClusterResourceNode PROTO :DWORD,:DWORD
BackupClusterDatabase PROTO :DWORD,:DWORD
CanResourceBeDependent PROTO :DWORD,:DWORD
ChangeClusterResourceGroup PROTO :DWORD,:DWORD
CloseCluster PROTO :DWORD
CloseClusterGroup PROTO :DWORD
CloseClusterNetInterface PROTO :DWORD
CloseClusterNetwork PROTO :DWORD
CloseClusterNode PROTO :DWORD
CloseClusterNotifyPort PROTO :DWORD
CloseClusterResource PROTO :DWORD
ClusterCloseEnum PROTO :DWORD
ClusterControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterGroupCloseEnum PROTO :DWORD
ClusterGroupControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterGroupEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterGroupOpenEnum PROTO :DWORD,:DWORD
ClusterNetInterfaceControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterNetworkCloseEnum PROTO :DWORD
ClusterNetworkControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterNetworkEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterNetworkOpenEnum PROTO :DWORD,:DWORD
ClusterNodeCloseEnum PROTO :DWORD
ClusterNodeControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterNodeEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterNodeOpenEnum PROTO :DWORD,:DWORD
ClusterOpenEnum PROTO :DWORD,:DWORD
ClusterRegCloseKey PROTO :DWORD
ClusterRegCreateKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterRegDeleteKey PROTO :DWORD,:DWORD
ClusterRegDeleteValue PROTO :DWORD,:DWORD
ClusterRegEnumKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterRegEnumValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterRegGetKeySecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD
ClusterRegOpenKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
ClusterRegQueryInfoKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterRegQueryValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterRegSetKeySecurity PROTO :DWORD,:DWORD,:DWORD
ClusterRegSetValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterResourceCloseEnum PROTO :DWORD
ClusterResourceControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterResourceEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterResourceOpenEnum PROTO :DWORD,:DWORD
ClusterResourceTypeCloseEnum PROTO :DWORD
ClusterResourceTypeControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterResourceTypeEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ClusterResourceTypeOpenEnum PROTO :DWORD,:DWORD,:DWORD
CreateClusterGroup PROTO :DWORD,:DWORD
CreateClusterNotifyPort PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateClusterResource PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateClusterResourceType PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeleteClusterGroup PROTO :DWORD
DeleteClusterResource PROTO :DWORD
DeleteClusterResourceType PROTO :DWORD,:DWORD
EvictClusterNode PROTO :DWORD
FailClusterResource PROTO :DWORD
GetClusterFromGroup PROTO :DWORD
GetClusterFromNetInterface PROTO :DWORD
GetClusterFromNetwork PROTO :DWORD
GetClusterFromNode PROTO :DWORD
GetClusterFromResource PROTO :DWORD
GetClusterGroupKey PROTO :DWORD,:DWORD
GetClusterGroupState PROTO :DWORD,:DWORD,:DWORD
GetClusterInformation PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetClusterKey PROTO :DWORD,:DWORD
GetClusterNetInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClusterNetInterfaceKey PROTO :DWORD,:DWORD
GetClusterNetInterfaceState PROTO :DWORD
GetClusterNetworkId PROTO :DWORD,:DWORD,:DWORD
GetClusterNetworkKey PROTO :DWORD,:DWORD
GetClusterNetworkState PROTO :DWORD
GetClusterNodeId PROTO :DWORD,:DWORD,:DWORD
GetClusterNodeKey PROTO :DWORD,:DWORD
GetClusterNodeState PROTO :DWORD
GetClusterNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClusterQuorumResource PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClusterResourceKey PROTO :DWORD,:DWORD
GetClusterResourceNetworkName PROTO :DWORD,:DWORD,:DWORD
GetClusterResourceState PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetClusterResourceTypeKey PROTO :DWORD,:DWORD,:DWORD
GetNodeClusterState PROTO :DWORD,:DWORD
MoveClusterGroup PROTO :DWORD,:DWORD
OfflineClusterGroup PROTO :DWORD
OfflineClusterResource PROTO :DWORD
OnlineClusterGroup PROTO :DWORD,:DWORD
OnlineClusterResource PROTO :DWORD
OpenCluster PROTO :DWORD
OpenClusterGroup PROTO :DWORD,:DWORD
OpenClusterNetInterface PROTO :DWORD,:DWORD
OpenClusterNetwork PROTO :DWORD,:DWORD
OpenClusterNode PROTO :DWORD,:DWORD
OpenClusterResource PROTO :DWORD,:DWORD
PauseClusterNode PROTO :DWORD
RegisterClusterNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD
RemoveClusterResourceDependency PROTO :DWORD,:DWORD
RemoveClusterResourceNode PROTO :DWORD,:DWORD
RestoreClusterDatabase PROTO :DWORD,:DWORD,:DWORD
ResumeClusterNode PROTO :DWORD
SetClusterGroupName PROTO :DWORD,:DWORD
SetClusterGroupNodeList PROTO :DWORD,:DWORD,:DWORD
SetClusterName PROTO :DWORD,:DWORD
SetClusterNetworkName PROTO :DWORD,:DWORD
SetClusterNetworkPriorityOrder PROTO :DWORD,:DWORD,:DWORD
SetClusterQuorumResource PROTO :DWORD,:DWORD,:DWORD
SetClusterResourceName PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file clusapi.inc
echo -----------------------------------------
ENDIF
