  ; ===========================================
  ; tapi32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF TAPI32_INC
TAPI32_INC equ <1>

GetTheFunctionPtr PROTO :DWORD,:DWORD
lineAccept PROTO :DWORD,:DWORD,:DWORD
lineAddProviderA PROTO :DWORD,:DWORD,:DWORD
lineAddProvider equ <lineAddProviderA>

lineAddProviderW PROTO :DWORD,:DWORD,:DWORD
lineAddToConference PROTO :DWORD,:DWORD
lineAgentSpecific PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineAnswer PROTO :DWORD,:DWORD,:DWORD
lineBlindTransferA PROTO :DWORD,:DWORD,:DWORD
lineBlindTransfer equ <lineBlindTransferA>

lineBlindTransferW PROTO :DWORD,:DWORD,:DWORD
lineClose PROTO :DWORD
lineCompleteCall PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineCompleteTransfer PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineConfigDialogA PROTO :DWORD,:DWORD,:DWORD
lineConfigDialog equ <lineConfigDialogA>

lineConfigDialogEditA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineConfigDialogEdit equ <lineConfigDialogEditA>

lineConfigDialogEditW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineConfigDialogW PROTO :DWORD,:DWORD,:DWORD
lineConfigProvider PROTO :DWORD,:DWORD
lineCreateAgentA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineCreateAgent equ <lineCreateAgentA>

lineCreateAgentSessionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineCreateAgentSession equ <lineCreateAgentSessionA>

lineCreateAgentSessionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineCreateAgentW PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineDeallocateCall PROTO :DWORD
lineDevSpecific PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineDevSpecificFeature PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineDialA PROTO :DWORD,:DWORD,:DWORD
lineDial equ <lineDialA>

lineDialW PROTO :DWORD,:DWORD,:DWORD
lineDrop PROTO :DWORD,:DWORD,:DWORD
lineForwardA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineForward equ <lineForwardA>

lineForwardW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGatherDigitsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGatherDigits equ <lineGatherDigitsA>

lineGatherDigitsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGenerateDigitsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGenerateDigits equ <lineGenerateDigitsA>

lineGenerateDigitsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGenerateTone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressCaps equ <lineGetAddressCapsA>

lineGetAddressCapsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressIDA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressID equ <lineGetAddressIDA>

lineGetAddressIDW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAddressStatusA PROTO :DWORD,:DWORD,:DWORD
lineGetAddressStatus equ <lineGetAddressStatusA>

lineGetAddressStatusW PROTO :DWORD,:DWORD,:DWORD
lineGetAgentActivityListA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentActivityList equ <lineGetAgentActivityListA>

lineGetAgentActivityListW PROTO :DWORD,:DWORD,:DWORD
lineGetAgentCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAgentCaps equ <lineGetAgentCapsA>

lineGetAgentCapsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAgentGroupListA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentGroupList equ <lineGetAgentGroupListA>

lineGetAgentGroupListW PROTO :DWORD,:DWORD,:DWORD
lineGetAgentInfo PROTO :DWORD,:DWORD,:DWORD
lineGetAgentSessionInfo PROTO :DWORD,:DWORD,:DWORD
lineGetAgentSessionList PROTO :DWORD,:DWORD,:DWORD
lineGetAgentStatusA PROTO :DWORD,:DWORD,:DWORD
lineGetAgentStatus equ <lineGetAgentStatusA>

lineGetAgentStatusW PROTO :DWORD,:DWORD,:DWORD
lineGetAppPriorityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetAppPriority equ <lineGetAppPriorityA>

lineGetAppPriorityW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetCallInfoA PROTO :DWORD,:DWORD
lineGetCallInfo equ <lineGetCallInfoA>

lineGetCallInfoW PROTO :DWORD,:DWORD
lineGetCallStatus PROTO :DWORD,:DWORD
lineGetConfRelatedCalls PROTO :DWORD,:DWORD
lineGetCountryA PROTO :DWORD,:DWORD,:DWORD
lineGetCountry equ <lineGetCountryA>

lineGetCountryW PROTO :DWORD,:DWORD,:DWORD
lineGetDevCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetDevCaps equ <lineGetDevCapsA>

lineGetDevCapsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetDevConfigA PROTO :DWORD,:DWORD,:DWORD
lineGetDevConfig equ <lineGetDevConfigA>

lineGetDevConfigW PROTO :DWORD,:DWORD,:DWORD
lineGetGroupListA PROTO :DWORD,:DWORD
lineGetGroupList equ <lineGetGroupListA>

lineGetGroupListW PROTO :DWORD,:DWORD
lineGetIDA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetID equ <lineGetIDA>

lineGetIDW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineGetIconA PROTO :DWORD,:DWORD,:DWORD
lineGetIcon equ <lineGetIconA>

lineGetIconW PROTO :DWORD,:DWORD,:DWORD
lineGetLineDevStatusA PROTO :DWORD,:DWORD
lineGetLineDevStatus equ <lineGetLineDevStatusA>

lineGetLineDevStatusW PROTO :DWORD,:DWORD
lineGetMessage PROTO :DWORD,:DWORD,:DWORD
lineGetNewCalls PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGetNumRings PROTO :DWORD,:DWORD,:DWORD
lineGetProviderListA PROTO :DWORD,:DWORD
lineGetProviderList equ <lineGetProviderListA>

lineGetProviderListW PROTO :DWORD,:DWORD
lineGetProxyStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineGetQueueInfo PROTO :DWORD,:DWORD,:DWORD
lineGetQueueListA PROTO :DWORD,:DWORD,:DWORD
lineGetQueueList equ <lineGetQueueListA>

lineGetQueueListW PROTO :DWORD,:DWORD,:DWORD
lineGetRequestA PROTO :DWORD,:DWORD,:DWORD
lineGetRequest equ <lineGetRequestA>

lineGetRequestW PROTO :DWORD,:DWORD,:DWORD
lineGetStatusMessages PROTO :DWORD,:DWORD,:DWORD
lineGetTranslateCapsA PROTO :DWORD,:DWORD,:DWORD
lineGetTranslateCaps equ <lineGetTranslateCapsA>

lineGetTranslateCapsW PROTO :DWORD,:DWORD,:DWORD
lineHandoffA PROTO :DWORD,:DWORD,:DWORD
lineHandoff equ <lineHandoffA>

lineHandoffW PROTO :DWORD,:DWORD,:DWORD
lineHold PROTO :DWORD
lineInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineInitializeExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineInitializeEx equ <lineInitializeExA>

lineInitializeExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineMakeCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineMakeCall equ <lineMakeCallA>

lineMakeCallW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineMonitorDigits PROTO :DWORD,:DWORD
lineMonitorMedia PROTO :DWORD,:DWORD
lineMonitorTones PROTO :DWORD,:DWORD,:DWORD
lineNegotiateAPIVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineNegotiateExtVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineOpenA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineOpen equ <lineOpenA>

lineOpenW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineParkA PROTO :DWORD,:DWORD,:DWORD,:DWORD
linePark equ <lineParkA>

lineParkW PROTO :DWORD,:DWORD,:DWORD,:DWORD
linePickupA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
linePickup equ <linePickupA>

linePickupW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
linePrepareAddToConferenceA PROTO :DWORD,:DWORD,:DWORD
linePrepareAddToConference equ <linePrepareAddToConferenceA>

linePrepareAddToConferenceW PROTO :DWORD,:DWORD,:DWORD
lineProxyMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineProxyResponse PROTO :DWORD,:DWORD,:DWORD
lineRedirectA PROTO :DWORD,:DWORD,:DWORD
lineRedirect equ <lineRedirectA>

lineRedirectW PROTO :DWORD,:DWORD,:DWORD
lineRegisterRequestRecipient PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineReleaseUserUserInfo PROTO :DWORD
lineRemoveFromConference PROTO :DWORD
lineRemoveProvider PROTO :DWORD,:DWORD
lineSecureCall PROTO :DWORD
lineSendUserUserInfo PROTO :DWORD,:DWORD,:DWORD
lineSetAgentActivity PROTO :DWORD,:DWORD,:DWORD
lineSetAgentGroup PROTO :DWORD,:DWORD,:DWORD
lineSetAgentMeasurementPeriod PROTO :DWORD,:DWORD,:DWORD
lineSetAgentSessionState PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetAgentState PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetAgentStateEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetAppPriorityA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetAppPriority equ <lineSetAppPriorityA>

lineSetAppPriorityW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetAppSpecific PROTO :DWORD,:DWORD
lineSetCallData PROTO :DWORD,:DWORD,:DWORD
lineSetCallParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallPrivilege PROTO :DWORD,:DWORD
lineSetCallQualityOfService PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetCallTreatment PROTO :DWORD,:DWORD
lineSetCurrentLocation PROTO :DWORD,:DWORD
lineSetDevConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetDevConfig equ <lineSetDevConfigA>

lineSetDevConfigW PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetLineDevStatus PROTO :DWORD,:DWORD,:DWORD
lineSetMediaControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetMediaMode PROTO :DWORD,:DWORD
lineSetNumRings PROTO :DWORD,:DWORD,:DWORD
lineSetQueueMeasurementPeriod PROTO :DWORD,:DWORD,:DWORD
lineSetStatusMessages PROTO :DWORD,:DWORD,:DWORD
lineSetTerminal PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetTollListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetTollList equ <lineSetTollListA>

lineSetTollListW PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineSetupConferenceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetupConference equ <lineSetupConferenceA>

lineSetupConferenceW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineSetupTransferA PROTO :DWORD,:DWORD,:DWORD
lineSetupTransfer equ <lineSetupTransferA>

lineSetupTransferW PROTO :DWORD,:DWORD,:DWORD
lineShutdown PROTO :DWORD
lineSwapHold PROTO :DWORD,:DWORD
lineTranslateAddressA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineTranslateAddress equ <lineTranslateAddressA>

lineTranslateAddressW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineTranslateDialogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineTranslateDialog equ <lineTranslateDialogA>

lineTranslateDialogW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
lineUncompleteCall PROTO :DWORD,:DWORD
lineUnhold PROTO :DWORD
lineUnparkA PROTO :DWORD,:DWORD,:DWORD,:DWORD
lineUnpark equ <lineUnparkA>

lineUnparkW PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneClose PROTO :DWORD
phoneConfigDialogA PROTO :DWORD,:DWORD,:DWORD
phoneConfigDialog equ <phoneConfigDialogA>

phoneConfigDialogW PROTO :DWORD,:DWORD,:DWORD
phoneDevSpecific PROTO :DWORD,:DWORD,:DWORD
phoneGetButtonInfoA PROTO :DWORD,:DWORD,:DWORD
phoneGetButtonInfo equ <phoneGetButtonInfoA>

phoneGetButtonInfoW PROTO :DWORD,:DWORD,:DWORD
phoneGetData PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneGetDevCapsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneGetDevCaps equ <phoneGetDevCapsA>

phoneGetDevCapsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneGetDisplay PROTO :DWORD,:DWORD
phoneGetGain PROTO :DWORD,:DWORD,:DWORD
phoneGetHookSwitch PROTO :DWORD,:DWORD
phoneGetIDA PROTO :DWORD,:DWORD,:DWORD
phoneGetID equ <phoneGetIDA>

phoneGetIDW PROTO :DWORD,:DWORD,:DWORD
phoneGetIconA PROTO :DWORD,:DWORD,:DWORD
phoneGetIcon equ <phoneGetIconA>

phoneGetIconW PROTO :DWORD,:DWORD,:DWORD
phoneGetLamp PROTO :DWORD,:DWORD,:DWORD
phoneGetMessage PROTO :DWORD,:DWORD,:DWORD
phoneGetRing PROTO :DWORD,:DWORD,:DWORD
phoneGetStatusA PROTO :DWORD,:DWORD
phoneGetStatus equ <phoneGetStatusA>

phoneGetStatusMessages PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneGetStatusW PROTO :DWORD,:DWORD
phoneGetVolume PROTO :DWORD,:DWORD,:DWORD
phoneInitialize PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneInitializeExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneInitializeEx equ <phoneInitializeExA>

phoneInitializeExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneNegotiateAPIVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneNegotiateExtVersion PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneSetButtonInfoA PROTO :DWORD,:DWORD,:DWORD
phoneSetButtonInfo equ <phoneSetButtonInfoA>

phoneSetButtonInfoW PROTO :DWORD,:DWORD,:DWORD
phoneSetData PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneSetDisplay PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
phoneSetGain PROTO :DWORD,:DWORD,:DWORD
phoneSetHookSwitch PROTO :DWORD,:DWORD,:DWORD
phoneSetLamp PROTO :DWORD,:DWORD,:DWORD
phoneSetRing PROTO :DWORD,:DWORD,:DWORD
phoneSetStatusMessages PROTO :DWORD,:DWORD,:DWORD,:DWORD
phoneSetVolume PROTO :DWORD,:DWORD,:DWORD
phoneShutdown PROTO :DWORD
tapiGetLocationInfoA PROTO :DWORD,:DWORD
tapiGetLocationInfo equ <tapiGetLocationInfoA>

tapiGetLocationInfoW PROTO :DWORD,:DWORD
tapiRequestDrop PROTO :DWORD,:DWORD
tapiRequestMakeCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD
tapiRequestMakeCall equ <tapiRequestMakeCallA>

tapiRequestMakeCallW PROTO :DWORD,:DWORD,:DWORD,:DWORD
tapiRequestMediaCallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
tapiRequestMediaCall equ <tapiRequestMediaCallA>

tapiRequestMediaCallW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file tapi32.inc
echo -----------------------------------------
ENDIF
