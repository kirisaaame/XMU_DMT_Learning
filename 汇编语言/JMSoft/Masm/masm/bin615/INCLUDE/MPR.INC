  ; ===========================================
  ; mpr.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MPR_INC
MPR_INC equ <1>

MultinetGetConnectionPerformanceA PROTO :DWORD,:DWORD
MultinetGetConnectionPerformance equ <MultinetGetConnectionPerformanceA>

MultinetGetConnectionPerformanceW PROTO :DWORD,:DWORD
WNetAddConnection2A PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnection2 equ <WNetAddConnection2A>

WNetAddConnection2W PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnection3A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnection3 equ <WNetAddConnection3A>

WNetAddConnection3W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetAddConnectionA PROTO :DWORD,:DWORD,:DWORD
WNetAddConnection equ <WNetAddConnectionA>

WNetAddConnectionW PROTO :DWORD,:DWORD,:DWORD
WNetCancelConnection2A PROTO :DWORD,:DWORD,:DWORD
WNetCancelConnection2 equ <WNetCancelConnection2A>

WNetCancelConnection2W PROTO :DWORD,:DWORD,:DWORD
WNetCancelConnectionA PROTO :DWORD,:DWORD
WNetCancelConnection equ <WNetCancelConnectionA>

WNetCancelConnectionW PROTO :DWORD,:DWORD
WNetCloseEnum PROTO :DWORD
WNetConnectionDialog1A PROTO :DWORD
WNetConnectionDialog1 equ <WNetConnectionDialog1A>

WNetConnectionDialog1W PROTO :DWORD
WNetConnectionDialog PROTO :DWORD,:DWORD
WNetDisconnectDialog1A PROTO :DWORD
WNetDisconnectDialog1 equ <WNetDisconnectDialog1A>

WNetDisconnectDialog1W PROTO :DWORD
WNetDisconnectDialog PROTO :DWORD,:DWORD
WNetEnumResourceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetEnumResource equ <WNetEnumResourceA>

WNetEnumResourceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetConnectionA PROTO :DWORD,:DWORD,:DWORD
WNetGetConnection equ <WNetGetConnectionA>

WNetGetConnectionW PROTO :DWORD,:DWORD,:DWORD
WNetGetLastErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetGetLastError equ <WNetGetLastErrorA>

WNetGetLastErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetGetNetworkInformationA PROTO :DWORD,:DWORD
WNetGetNetworkInformation equ <WNetGetNetworkInformationA>

WNetGetNetworkInformationW PROTO :DWORD,:DWORD
WNetGetProviderNameA PROTO :DWORD,:DWORD,:DWORD
WNetGetProviderName equ <WNetGetProviderNameA>

WNetGetProviderNameW PROTO :DWORD,:DWORD,:DWORD
WNetGetResourceInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetResourceInformation equ <WNetGetResourceInformationA>

WNetGetResourceInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetResourceParentA PROTO :DWORD,:DWORD,:DWORD
WNetGetResourceParent equ <WNetGetResourceParentA>

WNetGetResourceParentW PROTO :DWORD,:DWORD,:DWORD
WNetGetUniversalNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetUniversalName equ <WNetGetUniversalNameA>

WNetGetUniversalNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
WNetGetUserA PROTO :DWORD,:DWORD,:DWORD
WNetGetUser equ <WNetGetUserA>

WNetGetUserW PROTO :DWORD,:DWORD,:DWORD
WNetOpenEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetOpenEnum equ <WNetOpenEnumA>

WNetOpenEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetSetLastErrorA PROTO :DWORD,:DWORD,:DWORD
WNetSetLastError equ <WNetSetLastErrorA>

WNetSetLastErrorW PROTO :DWORD,:DWORD,:DWORD
WNetUseConnectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WNetUseConnection equ <WNetUseConnectionA>

WNetUseConnectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mpr.inc
echo -----------------------------------------
ENDIF
