  ; ===========================================
  ; ntmsapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF NTMSAPI_INC
NTMSAPI_INC equ <1>

AccessNtmsLibraryDoor PROTO :DWORD,:DWORD,:DWORD
AddNtmsMediaType PROTO :DWORD,:DWORD,:DWORD
AllocateNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
BeginNtmsDeviceChangeDetection PROTO :DWORD,:DWORD
CancelNtmsLibraryRequest PROTO :DWORD,:DWORD
CancelNtmsOperatorRequest PROTO :DWORD,:DWORD
ChangeNtmsMediaType PROTO :DWORD,:DWORD,:DWORD
CleanNtmsDrive PROTO :DWORD,:DWORD
CloseNtmsNotification PROTO :DWORD
CloseNtmsSession PROTO :DWORD
CreateNtmsMediaA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateNtmsMedia equ <CreateNtmsMediaA>

CreateNtmsMediaPoolA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateNtmsMediaPool equ <CreateNtmsMediaPoolA>

CreateNtmsMediaPoolW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateNtmsMediaW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeallocateNtmsMedia PROTO :DWORD,:DWORD,:DWORD
DecommissionNtmsMedia PROTO :DWORD,:DWORD
DeleteNtmsDrive PROTO :DWORD,:DWORD
DeleteNtmsLibrary PROTO :DWORD,:DWORD
DeleteNtmsMedia PROTO :DWORD,:DWORD
DeleteNtmsMediaPool PROTO :DWORD,:DWORD
DeleteNtmsMediaType PROTO :DWORD,:DWORD,:DWORD
DeleteNtmsRequests PROTO :DWORD,:DWORD,:DWORD,:DWORD
DisableNtmsObject PROTO :DWORD,:DWORD,:DWORD
DismountNtmsDrive PROTO :DWORD,:DWORD
DismountNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
EjectDiskFromSADriveA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EjectDiskFromSADrive equ <EjectDiskFromSADriveA>

EjectDiskFromSADriveW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EjectNtmsCleaner PROTO :DWORD,:DWORD,:DWORD,:DWORD
EjectNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnableNtmsObject PROTO :DWORD,:DWORD,:DWORD
EndNtmsDeviceChangeDetection PROTO :DWORD,:DWORD
EnumerateNtmsObject PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExportNtmsDatabase PROTO :DWORD
GetNtmsMediaPoolNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetNtmsMediaPoolName equ <GetNtmsMediaPoolNameA>

GetNtmsMediaPoolNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetNtmsObjectAttributeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNtmsObjectAttribute equ <GetNtmsObjectAttributeA>

GetNtmsObjectAttributeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNtmsObjectInformationA PROTO :DWORD,:DWORD,:DWORD
GetNtmsObjectInformation equ <GetNtmsObjectInformationA>

GetNtmsObjectInformationW PROTO :DWORD,:DWORD,:DWORD
GetNtmsObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNtmsRequestOrder PROTO :DWORD,:DWORD,:DWORD
ImportNtmsDatabase PROTO :DWORD
InjectNtmsCleaner PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InjectNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD
InventoryNtmsLibrary PROTO :DWORD,:DWORD,:DWORD
MountNtmsMedia PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MoveToNtmsMediaPool PROTO :DWORD,:DWORD,:DWORD
OpenNtmsNotification PROTO :DWORD,:DWORD
OpenNtmsSessionA PROTO :DWORD,:DWORD,:DWORD
OpenNtmsSession equ <OpenNtmsSessionA>

OpenNtmsSessionW PROTO :DWORD,:DWORD,:DWORD
ReleaseNtmsCleanerSlot PROTO :DWORD,:DWORD
ReserveNtmsCleanerSlot PROTO :DWORD,:DWORD,:DWORD
SatisfyNtmsOperatorRequest PROTO :DWORD,:DWORD
SetNtmsDeviceChangeDetection PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsMediaComplete PROTO :DWORD,:DWORD
SetNtmsObjectAttributeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsObjectAttribute equ <SetNtmsObjectAttributeA>

SetNtmsObjectAttributeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsObjectInformationA PROTO :DWORD,:DWORD,:DWORD
SetNtmsObjectInformation equ <SetNtmsObjectInformationA>

SetNtmsObjectInformationW PROTO :DWORD,:DWORD,:DWORD
SetNtmsObjectSecurity PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetNtmsRequestOrder PROTO :DWORD,:DWORD,:DWORD
SubmitNtmsOperatorRequestA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SubmitNtmsOperatorRequest equ <SubmitNtmsOperatorRequestA>

SubmitNtmsOperatorRequestW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SwapNtmsMedia PROTO :DWORD,:DWORD,:DWORD
UpdateNtmsOmidInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WaitForNtmsNotification PROTO :DWORD,:DWORD,:DWORD
WaitForNtmsOperatorRequest PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file ntmsapi.inc
echo -----------------------------------------
ENDIF
