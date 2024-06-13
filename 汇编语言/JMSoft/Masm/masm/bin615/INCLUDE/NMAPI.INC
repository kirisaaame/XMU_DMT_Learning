  ; ===========================================
  ; nmapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NMAPI_INC
NMAPI_INC equ <1>

AbortExpert PROTO :DWORD
AddAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddExpertToGroup PROTO :DWORD,:DWORD
AddGroup PROTO :DWORD,:DWORD
AddProperty PROTO :DWORD,:DWORD
AddressTypeToMacType PROTO :DWORD
AdjustSystemTime PROTO :DWORD,:DWORD,:DWORD
AttachPropertyInstance PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AttachPropertyInstanceEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BHGetLastError PROTO 
BHSetLastError PROTO :DWORD
CCHeapAlloc PROTO :DWORD,:DWORD
CCHeapFree PROTO :DWORD
CCHeapReAlloc PROTO :DWORD,:DWORD,:DWORD
CCHeapSize PROTO :DWORD
CompareAddresses PROTO :DWORD,:DWORD
CompareFrameDestAddress PROTO :DWORD,:DWORD
CompareFrameSourceAddress PROTO :DWORD,:DWORD
CompareRawAddresses PROTO :DWORD,:DWORD,:DWORD
CreateAddressDatabase PROTO 
CreateCapture PROTO :DWORD,:DWORD
CreateErrorLogEntry PROTO 
CreateFilter PROTO 
CreateFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateHandoffTable PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePropertyDatabase PROTO :DWORD,:DWORD
CreateProtocol PROTO :DWORD,:DWORD,:DWORD
DebugGetFrameLocks PROTO :DWORD,:DWORD,:DWORD
DebugShowLocks PROTO :DWORD
DecodeSNMPObjectIdentifier PROTO :DWORD,:DWORD,:DWORD
DeleteAddress PROTO :DWORD,:DWORD
DeleteExpertFromGroup PROTO :DWORD,:DWORD
DeleteFrame PROTO :DWORD,:DWORD
DeleteGroup PROTO :DWORD
DestroyAddressDatabase PROTO :DWORD
DestroyCapture PROTO :DWORD
DestroyFilter PROTO :DWORD
DestroyFrame PROTO :DWORD
DestroyHandoffTable PROTO :DWORD
DestroyPropertyDatabase PROTO :DWORD
DestroyProtocol PROTO :DWORD
DisableParserFilter PROTO :DWORD,:DWORD
DisableProtocol PROTO :DWORD,:DWORD
EmptyAddressDatabase PROTO :DWORD
EnableParserFilter PROTO :DWORD,:DWORD
EnableProtocol PROTO :DWORD,:DWORD
EncodeSNMPObjectIdentifier PROTO :DWORD,:DWORD,:DWORD
EnumAddresses PROTO :DWORD,:DWORD
EnumExpertHandles PROTO :DWORD,:DWORD,:DWORD
EnumExpertInfos PROTO :DWORD,:DWORD,:DWORD
EnumGroups PROTO :DWORD,:DWORD
EnumProtocols PROTO 
ExpertAllocMemory PROTO :DWORD,:DWORD,:DWORD
ExpertFreeMemory PROTO :DWORD,:DWORD
ExpertGetFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExpertGetStartupInfo PROTO :DWORD,:DWORD
ExpertIndicateStatus PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExpertMemorySize PROTO :DWORD,:DWORD
ExpertReallocMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD
ExpertSubmitEvent PROTO :DWORD,:DWORD
FilterAddObject PROTO :DWORD,:DWORD
FilterAttachesProperties PROTO :DWORD
FilterDuplicate PROTO :DWORD
FilterFindFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FilterFindPropertyInstance PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FilterFlushBits PROTO :DWORD
FilterFrame PROTO :DWORD,:DWORD,:DWORD
FindAddressInfoByAddress PROTO :DWORD,:DWORD
FindAddressInfoByName PROTO :DWORD,:DWORD,:DWORD
FindNextFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindPreviousFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindPropertyInstance PROTO :DWORD,:DWORD
FindPropertyInstanceRestart PROTO :DWORD,:DWORD,:DWORD,:DWORD
FrameRecognize PROTO :DWORD
GetASRThWnd PROTO 
GetAddressDatabaseInstanceData PROTO :DWORD
GetAddressInfo PROTO :DWORD,:DWORD
GetAddressInfoByName PROTO :DWORD,:DWORD
GetCCInstPtr PROTO 
GetCaptureAddressDB PROTO :DWORD
GetCaptureComment PROTO :DWORD
GetCaptureCommentFromFilename PROTO :DWORD,:DWORD,:DWORD
GetCaptureInstanceData PROTO :DWORD
GetCaptureMacType PROTO :DWORD
GetCaptureTimeStamp PROTO :DWORD
GetCaptureTotalFrames PROTO :DWORD
GetCurrentFilter PROTO 
GetEnabledProtocols PROTO :DWORD
GetExpertFromName PROTO :DWORD,:DWORD
GetExpertInfo PROTO :DWORD,:DWORD
GetExpertStatus PROTO :DWORD,:DWORD
GetFrame PROTO :DWORD,:DWORD
GetFrameCaptureHandle PROTO :DWORD
GetFrameDestAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFrameDstAddressOffset PROTO :DWORD,:DWORD,:DWORD
GetFrameFromFrameHandle PROTO :DWORD
GetFrameLength PROTO :DWORD
GetFrameMacHeaderLength PROTO :DWORD
GetFrameMacType PROTO :DWORD
GetFrameNumber PROTO :DWORD
GetFrameRecognizeData PROTO :DWORD
GetFrameRoutingInformation PROTO :DWORD,:DWORD
GetFrameSourceAddress PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetFrameSrcAddressOffset PROTO :DWORD,:DWORD,:DWORD
GetFrameStoredLength PROTO :DWORD
GetFrameTimeStamp PROTO :DWORD
GetGroupName PROTO :DWORD,:DWORD
GetMaxAmountOfProtocols PROTO 
GetPreviousProtocolOffsetByName PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetProperty PROTO :DWORD,:DWORD
GetPropertyInfo PROTO :DWORD
GetPropertyText PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetProtocolDLLName PROTO :DWORD
GetProtocolFromName PROTO :DWORD
GetProtocolFromProperty PROTO :DWORD
GetProtocolFromProtocolID PROTO :DWORD
GetProtocolFromTable PROTO :DWORD,:DWORD,:DWORD
GetProtocolInfo PROTO :DWORD
GetProtocolStartOffset PROTO :DWORD,:DWORD
GetProtocolStartOffsetHandle PROTO :DWORD,:DWORD
GetSystemPath PROTO :DWORD,:DWORD
HelperFormatUnicodeString PROTO :DWORD,:DWORD,:DWORD
InsertFrame PROTO :DWORD,:DWORD,:DWORD
IsRawIPXEnabled PROTO :DWORD,:DWORD,:DWORD
IsValidSNMPObjectIdentifier PROTO :DWORD
LoadCapture PROTO :DWORD,:DWORD
LoadCaptureW PROTO :DWORD,:DWORD
LoadExpertConfiguration PROTO :DWORD,:DWORD,:DWORD
LockFrame PROTO :DWORD
LockFramePropertyTable PROTO :DWORD
LockFrameText PROTO :DWORD
MacTypeToAddressType PROTO :DWORD
ModifyFrame PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ObjectIdentifierContains PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PanicMessage PROTO :DWORD,:DWORD,:DWORD
ParserTemporaryLockFrame PROTO :DWORD
PopupExpertConfigurationUI PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryProtocolState PROTO :DWORD,:DWORD
ReleaseFrame PROTO :DWORD
ResetPropertyInstanceLength PROTO :DWORD,:DWORD,:DWORD
RunExperts PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaveCapture PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaveCaptureW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaveDownLevelCapture PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaveExpertConfiguration PROTO :DWORD,:DWORD,:DWORD
SetAddressDatabaseInstanceData PROTO :DWORD,:DWORD
SetCCInstPtr PROTO :DWORD
SetCaptureAddressDB PROTO :DWORD,:DWORD
SetCaptureInstanceData PROTO :DWORD,:DWORD
SetCaptureMacType PROTO :DWORD,:DWORD
SetCaptureTimeStamp PROTO :DWORD,:DWORD
SetCurrentFilter PROTO :DWORD
SetGroupName PROTO :DWORD,:DWORD
UnlockFrame PROTO :DWORD
UnlockFramePropertyTable PROTO :DWORD
UnlockFrameText PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file nmapi.inc
echo -----------------------------------------
ENDIF
