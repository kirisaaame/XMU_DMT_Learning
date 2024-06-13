  ; ===========================================
  ; bdnapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF BDNAPI_INC
BDNAPI_INC equ <1>

BdnConnectionClose PROTO :DWORD
BdnCreateRegulatedMulticast PROTO :DWORD,:DWORD,:DWORD
BdnCreateRegulatedMulticastRaw PROTO :DWORD,:DWORD,:DWORD
BdnForwardMulticast PROTO :DWORD,:DWORD,:DWORD
BdnGetReservationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnGetReservation equ <BdnGetReservationA>

BdnGetReservationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnLookupReservationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnLookupReservation equ <BdnLookupReservationA>

BdnLookupReservationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnLookupServiceA PROTO :DWORD,:DWORD
BdnLookupService equ <BdnLookupServiceA>

BdnLookupServiceW PROTO :DWORD,:DWORD
BdnOpenTunnel PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnReleaseAddress PROTO :DWORD,:DWORD,:DWORD
BdnReserveAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnReserveBandwidthA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnReserveBandwidth equ <BdnReserveBandwidthA>

BdnReserveBandwidthW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnSend PROTO :DWORD,:DWORD,:DWORD
BdnSendRaw PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnSendTo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BdnServiceClose PROTO :DWORD
BdnServiceCreate PROTO :DWORD
BdnServiceGetValue PROTO :DWORD,:DWORD,:DWORD
BdnServiceGetValueStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD
BdnServiceGetValueString equ <BdnServiceGetValueStringA>

BdnServiceGetValueStringW PROTO :DWORD,:DWORD,:DWORD,:DWORD
BdnServiceSetValue PROTO :DWORD,:DWORD,:DWORD
BdnServiceSetValueStringA PROTO :DWORD,:DWORD,:DWORD
BdnServiceSetValueString equ <BdnServiceSetValueStringA>

BdnServiceSetValueStringW PROTO :DWORD,:DWORD,:DWORD
BdnStopMulticast PROTO :DWORD,:DWORD
msbdnClearReservation PROTO :DWORD,:DWORD
msbdnClearReservationEx PROTO :DWORD,:DWORD
msbdnClose PROTO :DWORD
msbdnForwardMulticast PROTO :DWORD,:DWORD,:DWORD,:DWORD
msbdnForwardMulticastEx PROTO :DWORD,:DWORD,:DWORD
msbdnGetReservationEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnLookupReservation PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnLookupReservationEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnOpenTunnelEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnRelinquishAddress PROTO :DWORD,:DWORD,:DWORD
msbdnRelinquishAddressEx PROTO :DWORD,:DWORD,:DWORD
msbdnReserveAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnReserveAddressEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnReserveBandwidth PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnReserveBandwidthEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnSend PROTO :DWORD,:DWORD,:DWORD
msbdnSendRaw PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnSendTo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
msbdnStopMulticast PROTO :DWORD,:DWORD
msbdnStopMulticastEx PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file bdnapi.inc
echo -----------------------------------------
ENDIF
