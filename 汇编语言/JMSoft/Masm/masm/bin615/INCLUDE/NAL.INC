  ; ===========================================
  ; nal.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NAL_INC
NAL_INC equ <1>

AllocNetworkBuffer PROTO :DWORD,:DWORD
CancelTransmit PROTO :DWORD,:DWORD
ClearStatistics PROTO :DWORD
CloseNetwork PROTO :DWORD,:DWORD
CompactNetworkBuffer PROTO :DWORD
ContinueCapturing PROTO :DWORD
DestroyNetworkID PROTO :DWORD
EnumNetworks PROTO 
FreeNetworkBuffer PROTO :DWORD
GetBufferSize PROTO :DWORD
GetBufferTimeStamp PROTO :DWORD,:DWORD
GetBufferTotalBytesCaptured PROTO :DWORD
GetBufferTotalFramesCaptured PROTO :DWORD
GetNetworkBuffer PROTO :DWORD
GetNetworkCallback PROTO :DWORD
GetNetworkFrame PROTO :DWORD,:DWORD
GetNetworkID PROTO :DWORD
GetNetworkInfo PROTO :DWORD
GetNetworkInstanceData PROTO :DWORD
GetReconnectInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
NetworkProc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OpenNetwork PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PauseCapturing PROTO :DWORD
QueryNetworkStatus PROTO :DWORD,:DWORD
SetNetworkBuffer PROTO :DWORD,:DWORD
SetNetworkCallback PROTO :DWORD,:DWORD
SetNetworkFilter PROTO :DWORD,:DWORD,:DWORD
SetNetworkInstanceData PROTO :DWORD,:DWORD
SetReconnectInfo PROTO :DWORD,:DWORD,:DWORD
SetupNetwork PROTO :DWORD,:DWORD
StartCapturing PROTO :DWORD,:DWORD
StationQuery PROTO :DWORD,:DWORD,:DWORD,:DWORD
StopCapturing PROTO :DWORD
TransmitQueue PROTO :DWORD,:DWORD
TransmitSpecialFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD
_AllocNetworkBuffer PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file nal.inc
echo -----------------------------------------
ENDIF
