  ; ===========================================
  ; mprapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MPRAPI_INC
MPRAPI_INC equ <1>

CompressPhoneNumber PROTO :DWORD,:DWORD
MprAdminBufferFree PROTO :DWORD
MprAdminConnectionClearStats PROTO :DWORD,:DWORD
MprAdminConnectionEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminConnectionGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminDeregisterConnectionNotification PROTO :DWORD,:DWORD
MprAdminDeviceEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminEstablishDomainRasServer PROTO :DWORD,:DWORD,:DWORD
MprAdminGetErrorString PROTO :DWORD,:DWORD
MprAdminGetPDCServer PROTO :DWORD,:DWORD,:DWORD
MprAdminInterfaceConnect PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceDelete PROTO :DWORD,:DWORD
MprAdminInterfaceDeviceGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceDeviceSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceDisconnect PROTO :DWORD,:DWORD
MprAdminInterfaceEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceGetCredentials PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceGetCredentialsEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceGetHandle PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceQueryUpdateResult PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceSetCredentials PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceSetCredentialsEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceTransportAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceTransportGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceTransportRemove PROTO :DWORD,:DWORD,:DWORD
MprAdminInterfaceTransportSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminInterfaceUpdatePhonebookInfo PROTO :DWORD,:DWORD
MprAdminInterfaceUpdateRoutes PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminIsDomainRasServer PROTO :DWORD,:DWORD,:DWORD
MprAdminIsServiceRunning PROTO :DWORD
MprAdminMIBBufferFree PROTO :DWORD
MprAdminMIBEntryCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBEntryDelete PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBEntryGet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBEntryGetFirst PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBEntryGetNext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBEntrySet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminMIBServerConnect PROTO :DWORD,:DWORD
MprAdminMIBServerDisconnect PROTO :DWORD
MprAdminPortClearStats PROTO :DWORD,:DWORD
MprAdminPortDisconnect PROTO :DWORD,:DWORD
MprAdminPortEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminPortGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminPortReset PROTO :DWORD,:DWORD
MprAdminRegisterConnectionNotification PROTO :DWORD,:DWORD
MprAdminSendUserMessage PROTO :DWORD,:DWORD,:DWORD
MprAdminServerConnect PROTO :DWORD,:DWORD
MprAdminServerDisconnect PROTO :DWORD
MprAdminServerGetInfo PROTO :DWORD,:DWORD,:DWORD
MprAdminTransportCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminTransportGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminTransportSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprAdminUpgradeUsers PROTO :DWORD,:DWORD
MprAdminUserClose PROTO :DWORD
MprAdminUserGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminUserOpen PROTO :DWORD,:DWORD,:DWORD
MprAdminUserRead PROTO :DWORD,:DWORD,:DWORD
MprAdminUserReadProfFlags PROTO :DWORD,:DWORD
MprAdminUserServerConnect PROTO :DWORD,:DWORD,:DWORD
MprAdminUserServerDisconnect PROTO :DWORD
MprAdminUserSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprAdminUserWrite PROTO :DWORD,:DWORD,:DWORD
MprAdminUserWriteProfFlags PROTO :DWORD,:DWORD
MprConfigBufferFree PROTO :DWORD
MprConfigGetFriendlyName PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprConfigGetGuidName PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceDelete PROTO :DWORD,:DWORD
MprConfigInterfaceEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceGetHandle PROTO :DWORD,:DWORD,:DWORD
MprConfigInterfaceGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportGetHandle PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportRemove PROTO :DWORD,:DWORD,:DWORD
MprConfigInterfaceTransportSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigServerBackup PROTO :DWORD,:DWORD
MprConfigServerConnect PROTO :DWORD,:DWORD
MprConfigServerDisconnect PROTO :DWORD
MprConfigServerGetInfo PROTO :DWORD,:DWORD,:DWORD
MprConfigServerInstall PROTO :DWORD,:DWORD
MprConfigServerRefresh PROTO :DWORD
MprConfigServerRestore PROTO :DWORD,:DWORD
MprConfigTransportCreate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigTransportDelete PROTO :DWORD,:DWORD
MprConfigTransportEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigTransportGetHandle PROTO :DWORD,:DWORD,:DWORD
MprConfigTransportGetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprConfigTransportSetInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprDomainQueryAccess PROTO :DWORD,:DWORD
MprDomainQueryRasServer PROTO :DWORD,:DWORD,:DWORD
MprDomainRegisterRasServer PROTO :DWORD,:DWORD,:DWORD
MprDomainSetAccess PROTO :DWORD,:DWORD
MprGetUsrParams PROTO :DWORD,:DWORD,:DWORD
MprInfoBlockAdd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprInfoBlockFind PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprInfoBlockQuerySize PROTO :DWORD
MprInfoBlockRemove PROTO :DWORD,:DWORD,:DWORD
MprInfoBlockSet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MprInfoCreate PROTO :DWORD,:DWORD
MprInfoDelete PROTO :DWORD
MprInfoDuplicate PROTO :DWORD,:DWORD
MprInfoRemoveAll PROTO :DWORD,:DWORD
MprPortSetUsage PROTO :DWORD
MprSetupIpInIpInterfaceFriendlyNameCreate PROTO :DWORD,:DWORD
MprSetupIpInIpInterfaceFriendlyNameDelete PROTO :DWORD,:DWORD
MprSetupIpInIpInterfaceFriendlyNameEnum PROTO :DWORD,:DWORD,:DWORD
MprSetupIpInIpInterfaceFriendlyNameFree PROTO :DWORD
RasPrivilegeAndCallBackNumber PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mprapi.inc
echo -----------------------------------------
ENDIF
