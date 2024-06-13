  ; ===========================================
  ; winfax.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINFAX_INC
WINFAX_INC equ <1>

FaxAbort PROTO :DWORD,:DWORD
FaxAccessCheck PROTO :DWORD,:DWORD
FaxClose PROTO :DWORD
FaxCompleteJobParamsA PROTO :DWORD,:DWORD
FaxCompleteJobParams equ <FaxCompleteJobParamsA>

FaxCompleteJobParamsW PROTO :DWORD,:DWORD
FaxConnectFaxServerA PROTO :DWORD,:DWORD
FaxConnectFaxServer equ <FaxConnectFaxServerA>

FaxConnectFaxServerW PROTO :DWORD,:DWORD
FaxEnableRoutingMethodA PROTO :DWORD,:DWORD,:DWORD
FaxEnableRoutingMethod equ <FaxEnableRoutingMethodA>

FaxEnableRoutingMethodW PROTO :DWORD,:DWORD,:DWORD
FaxEnumGlobalRoutingInfoA PROTO :DWORD,:DWORD,:DWORD
FaxEnumGlobalRoutingInfo equ <FaxEnumGlobalRoutingInfoA>

FaxEnumGlobalRoutingInfoW PROTO :DWORD,:DWORD,:DWORD
FaxEnumJobsA PROTO :DWORD,:DWORD,:DWORD
FaxEnumJobs equ <FaxEnumJobsA>

FaxEnumJobsW PROTO :DWORD,:DWORD,:DWORD
FaxEnumPortsA PROTO :DWORD,:DWORD,:DWORD
FaxEnumPorts equ <FaxEnumPortsA>

FaxEnumPortsW PROTO :DWORD,:DWORD,:DWORD
FaxEnumRoutingMethodsA PROTO :DWORD,:DWORD,:DWORD
FaxEnumRoutingMethods equ <FaxEnumRoutingMethodsA>

FaxEnumRoutingMethodsW PROTO :DWORD,:DWORD,:DWORD
FaxFreeBuffer PROTO :DWORD
FaxGetConfigurationA PROTO :DWORD,:DWORD
FaxGetConfiguration equ <FaxGetConfigurationA>

FaxGetConfigurationW PROTO :DWORD,:DWORD
FaxGetDeviceStatusA PROTO :DWORD,:DWORD
FaxGetDeviceStatus equ <FaxGetDeviceStatusA>

FaxGetDeviceStatusW PROTO :DWORD,:DWORD
FaxGetJobA PROTO :DWORD,:DWORD,:DWORD
FaxGetJob equ <FaxGetJobA>

FaxGetJobW PROTO :DWORD,:DWORD,:DWORD
FaxGetLoggingCategoriesA PROTO :DWORD,:DWORD,:DWORD
FaxGetLoggingCategories equ <FaxGetLoggingCategoriesA>

FaxGetLoggingCategoriesW PROTO :DWORD,:DWORD,:DWORD
FaxGetPageData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxGetPortA PROTO :DWORD,:DWORD
FaxGetPort equ <FaxGetPortA>

FaxGetPortW PROTO :DWORD,:DWORD
FaxGetRoutingInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxGetRoutingInfo equ <FaxGetRoutingInfoA>

FaxGetRoutingInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxInitializeEventQueue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxOpenPort PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxPrintCoverPageA PROTO :DWORD,:DWORD
FaxPrintCoverPage equ <FaxPrintCoverPageA>

FaxPrintCoverPageW PROTO :DWORD,:DWORD
FaxRegisterRoutingExtensionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxRegisterServiceProviderW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxSendDocumentA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxSendDocument equ <FaxSendDocumentA>

FaxSendDocumentForBroadcastA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxSendDocumentForBroadcast equ <FaxSendDocumentForBroadcastA>

FaxSendDocumentForBroadcastW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxSendDocumentW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FaxSetConfigurationA PROTO :DWORD,:DWORD
FaxSetConfiguration equ <FaxSetConfigurationA>

FaxSetConfigurationW PROTO :DWORD,:DWORD
FaxSetGlobalRoutingInfoA PROTO :DWORD,:DWORD
FaxSetGlobalRoutingInfo equ <FaxSetGlobalRoutingInfoA>

FaxSetGlobalRoutingInfoW PROTO :DWORD,:DWORD
FaxSetJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxSetJob equ <FaxSetJobA>

FaxSetJobW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxSetLoggingCategoriesA PROTO :DWORD,:DWORD,:DWORD
FaxSetLoggingCategories equ <FaxSetLoggingCategoriesA>

FaxSetLoggingCategoriesW PROTO :DWORD,:DWORD,:DWORD
FaxSetPortA PROTO :DWORD,:DWORD
FaxSetPort equ <FaxSetPortA>

FaxSetPortW PROTO :DWORD,:DWORD
FaxSetRoutingInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxSetRoutingInfo equ <FaxSetRoutingInfoA>

FaxSetRoutingInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxStartPrintJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD
FaxStartPrintJob equ <FaxStartPrintJobA>

FaxStartPrintJobW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winfax.inc
echo -----------------------------------------
ENDIF
