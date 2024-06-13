  ; ===========================================
  ; rasapi32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RASAPI32_INC
RASAPI32_INC equ <1>

DDMGetPhonebookInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DwCloneEntry PROTO :DWORD,:DWORD,:DWORD
DwDeleteSubEntry PROTO :DWORD,:DWORD,:DWORD
DwEnumEntriesForAllUsers PROTO :DWORD,:DWORD,:DWORD
DwEnumEntryDetails PROTO :DWORD,:DWORD,:DWORD,:DWORD
FreeSharedAccessApplication PROTO :DWORD
FreeSharedAccessServer PROTO :DWORD
RasAutoDialSharedConnection PROTO 
RasAutodialAddressToNetwork PROTO :DWORD,:DWORD,:DWORD
RasAutodialEntryToNetwork PROTO :DWORD,:DWORD,:DWORD
RasClearConnectionStatistics PROTO :DWORD
RasClearLinkStatistics PROTO :DWORD,:DWORD
RasConnectionNotificationA PROTO :DWORD,:DWORD,:DWORD
RasConnectionNotification equ <RasConnectionNotificationA>

RasConnectionNotificationW PROTO :DWORD,:DWORD,:DWORD
RasCreatePhonebookEntryA PROTO :DWORD,:DWORD
RasCreatePhonebookEntry equ <RasCreatePhonebookEntryA>

RasCreatePhonebookEntryW PROTO :DWORD,:DWORD
RasDeleteEntryA PROTO :DWORD,:DWORD
RasDeleteEntry equ <RasDeleteEntryA>

RasDeleteEntryW PROTO :DWORD,:DWORD
RasDialA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasDial equ <RasDialA>

RasDialW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasDialWow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasEditPhonebookEntryA PROTO :DWORD,:DWORD,:DWORD
RasEditPhonebookEntry equ <RasEditPhonebookEntryA>

RasEditPhonebookEntryW PROTO :DWORD,:DWORD,:DWORD
RasEnumAutodialAddressesA PROTO :DWORD,:DWORD,:DWORD
RasEnumAutodialAddresses equ <RasEnumAutodialAddressesA>

RasEnumAutodialAddressesW PROTO :DWORD,:DWORD,:DWORD
RasEnumConnectionsA PROTO :DWORD,:DWORD,:DWORD
RasEnumConnections equ <RasEnumConnectionsA>

RasEnumConnectionsW PROTO :DWORD,:DWORD,:DWORD
RasEnumConnectionsWow PROTO :DWORD,:DWORD,:DWORD
RasEnumDevicesA PROTO :DWORD,:DWORD,:DWORD
RasEnumDevices equ <RasEnumDevicesA>

RasEnumDevicesW PROTO :DWORD,:DWORD,:DWORD
RasEnumEntriesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasEnumEntries equ <RasEnumEntriesA>

RasEnumEntriesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasEnumEntriesWow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasFreeEapUserIdentityA PROTO :DWORD
RasFreeEapUserIdentity equ <RasFreeEapUserIdentityA>

RasFreeEapUserIdentityW PROTO :DWORD
RasFreeLanConnTable PROTO :DWORD,:DWORD
RasFreeSharedAccessSettings PROTO :DWORD
RasGetAutodialAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetAutodialAddress equ <RasGetAutodialAddressA>

RasGetAutodialAddressW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetAutodialEnableA PROTO :DWORD,:DWORD
RasGetAutodialEnable equ <RasGetAutodialEnableA>

RasGetAutodialEnableW PROTO :DWORD,:DWORD
RasGetAutodialParamA PROTO :DWORD,:DWORD,:DWORD
RasGetAutodialParam equ <RasGetAutodialParamA>

RasGetAutodialParamW PROTO :DWORD,:DWORD,:DWORD
RasGetConnectResponse PROTO :DWORD,:DWORD
RasGetConnectStatusA PROTO :DWORD,:DWORD
RasGetConnectStatus equ <RasGetConnectStatusA>

RasGetConnectStatusW PROTO :DWORD,:DWORD
RasGetConnectStatusWow PROTO :DWORD,:DWORD
RasGetConnectionStatistics PROTO :DWORD,:DWORD
RasGetCountryInfoA PROTO :DWORD,:DWORD
RasGetCountryInfo equ <RasGetCountryInfoA>

RasGetCountryInfoW PROTO :DWORD,:DWORD
RasGetCredentialsA PROTO :DWORD,:DWORD,:DWORD
RasGetCredentials equ <RasGetCredentialsA>

RasGetCredentialsW PROTO :DWORD,:DWORD,:DWORD
RasGetCustomAuthDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasGetCustomAuthData equ <RasGetCustomAuthDataA>

RasGetCustomAuthDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasGetEapUserDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEapUserData equ <RasGetEapUserDataA>

RasGetEapUserDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEapUserIdentityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEapUserIdentity equ <RasGetEapUserIdentityA>

RasGetEapUserIdentityW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEntryDialParamsA PROTO :DWORD,:DWORD,:DWORD
RasGetEntryDialParams equ <RasGetEntryDialParamsA>

RasGetEntryDialParamsW PROTO :DWORD,:DWORD,:DWORD
RasGetEntryHrasconnA PROTO :DWORD,:DWORD,:DWORD
RasGetEntryHrasconn equ <RasGetEntryHrasconnA>

RasGetEntryHrasconnW PROTO :DWORD,:DWORD,:DWORD
RasGetEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetEntryProperties equ <RasGetEntryPropertiesA>

RasGetEntryPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
RasGetErrorString equ <RasGetErrorStringA>

RasGetErrorStringW PROTO :DWORD,:DWORD,:DWORD
RasGetErrorStringWow PROTO :DWORD,:DWORD,:DWORD
RasGetHport PROTO :DWORD
RasGetLinkStatistics PROTO :DWORD,:DWORD,:DWORD
RasGetProjectionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasGetProjectionInfo equ <RasGetProjectionInfoA>

RasGetProjectionInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasGetSubEntryHandleA PROTO :DWORD,:DWORD,:DWORD
RasGetSubEntryHandle equ <RasGetSubEntryHandleA>

RasGetSubEntryHandleW PROTO :DWORD,:DWORD,:DWORD
RasGetSubEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasGetSubEntryProperties equ <RasGetSubEntryPropertiesA>

RasGetSubEntryPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasHangUpA PROTO :DWORD
RasHangUp equ <RasHangUpA>

RasHangUpW PROTO :DWORD
RasHangUpWow PROTO :DWORD
RasInvokeEapUI PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasIsRouterConnection PROTO :DWORD
RasIsSharedConnection PROTO :DWORD,:DWORD
RasLoadSharedAccessSettings PROTO :DWORD
RasNameFromSharedConnection PROTO :DWORD,:DWORD
RasQueryLanConnTable PROTO :DWORD,:DWORD,:DWORD
RasQueryRedialOnLinkFailure PROTO :DWORD,:DWORD,:DWORD
RasQuerySharedAutoDial PROTO :DWORD
RasQuerySharedConnection PROTO :DWORD
RasQuerySharedConnectionCredentials PROTO :DWORD,:DWORD
RasQuerySharedPrivateLan PROTO :DWORD
RasQuerySharedPrivateLanAddress PROTO :DWORD
RasRenameEntryA PROTO :DWORD,:DWORD,:DWORD
RasRenameEntry equ <RasRenameEntryA>

RasRenameEntryW PROTO :DWORD,:DWORD,:DWORD
RasSaveSharedAccessSettings PROTO :DWORD
RasSetAutodialAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetAutodialAddress equ <RasSetAutodialAddressA>

RasSetAutodialAddressW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetAutodialEnableA PROTO :DWORD,:DWORD
RasSetAutodialEnable equ <RasSetAutodialEnableA>

RasSetAutodialEnableW PROTO :DWORD,:DWORD
RasSetAutodialParamA PROTO :DWORD,:DWORD,:DWORD
RasSetAutodialParam equ <RasSetAutodialParamA>

RasSetAutodialParamW PROTO :DWORD,:DWORD,:DWORD
RasSetCredentialsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasSetCredentials equ <RasSetCredentialsA>

RasSetCredentialsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasSetCustomAuthDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasSetCustomAuthData equ <RasSetCustomAuthDataA>

RasSetCustomAuthDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasSetEapUserDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetEapUserData equ <RasSetEapUserDataA>

RasSetEapUserDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetEntryDialParamsA PROTO :DWORD,:DWORD,:DWORD
RasSetEntryDialParams equ <RasSetEntryDialParamsA>

RasSetEntryDialParamsW PROTO :DWORD,:DWORD,:DWORD
RasSetEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetEntryProperties equ <RasSetEntryPropertiesA>

RasSetEntryPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetOldPassword PROTO :DWORD,:DWORD
RasSetSharedAutoDial PROTO :DWORD
RasSetSharedConnectionCredentials PROTO :DWORD,:DWORD
RasSetSubEntryPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasSetSubEntryProperties equ <RasSetSubEntryPropertiesA>

RasSetSubEntryPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RasShareConnection PROTO :DWORD,:DWORD
RasUnshareConnection PROTO :DWORD
RasValidateEntryNameA PROTO :DWORD,:DWORD
RasValidateEntryName equ <RasValidateEntryNameA>

RasValidateEntryNameW PROTO :DWORD,:DWORD
RasfileClose PROTO :DWORD
RasfileDeleteLine PROTO :DWORD
RasfileFindFirstLine PROTO :DWORD,:DWORD,:DWORD
RasfileFindLastLine PROTO :DWORD,:DWORD,:DWORD
RasfileFindMarkedLine PROTO :DWORD,:DWORD
RasfileFindNextKeyLine PROTO :DWORD,:DWORD,:DWORD
RasfileFindNextLine PROTO :DWORD,:DWORD,:DWORD
RasfileFindPrevLine PROTO :DWORD,:DWORD,:DWORD
RasfileFindSectionLine PROTO :DWORD,:DWORD,:DWORD
RasfileGetKeyValueFields PROTO :DWORD,:DWORD,:DWORD
RasfileGetLine PROTO :DWORD
RasfileGetLineMark PROTO :DWORD
RasfileGetLineText PROTO :DWORD,:DWORD
RasfileGetLineType PROTO :DWORD
RasfileGetSectionName PROTO :DWORD,:DWORD
RasfileInsertLine PROTO :DWORD,:DWORD,:DWORD
RasfileLoad PROTO :DWORD,:DWORD,:DWORD,:DWORD
RasfileLoadInfo PROTO :DWORD,:DWORD
RasfilePutKeyValueFields PROTO :DWORD,:DWORD,:DWORD
RasfilePutLineMark PROTO :DWORD,:DWORD
RasfilePutLineText PROTO :DWORD,:DWORD
RasfilePutSectionName PROTO :DWORD,:DWORD
RasfileWrite PROTO :DWORD,:DWORD
SharedAccessResponseListToString PROTO :DWORD,:DWORD
SharedAccessResponseStringToList PROTO :DWORD,:DWORD,:DWORD
UnInitializeRAS PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file rasapi32.inc
echo -----------------------------------------
ENDIF
