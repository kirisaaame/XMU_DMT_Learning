  ; ===========================================
  ; mscms.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSCMS_INC
MSCMS_INC equ <1>

AssociateColorProfileWithDeviceA PROTO :DWORD,:DWORD,:DWORD
AssociateColorProfileWithDevice equ <AssociateColorProfileWithDeviceA>

AssociateColorProfileWithDeviceW PROTO :DWORD,:DWORD,:DWORD
CheckBitmapBits PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CheckColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CloseColorProfile PROTO :DWORD
ConvertColorNameToIndex PROTO :DWORD,:DWORD,:DWORD,:DWORD
ConvertIndexToColorName PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateColorTransformA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateColorTransform equ <CreateColorTransformA>

CreateColorTransformW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateDeviceLinkProfile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateMultiProfileTransform PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateProfileFromLogColorSpaceA PROTO :DWORD,:DWORD
CreateProfileFromLogColorSpace equ <CreateProfileFromLogColorSpaceA>

CreateProfileFromLogColorSpaceW PROTO :DWORD,:DWORD
DeleteColorTransform PROTO :DWORD
DisassociateColorProfileFromDeviceA PROTO :DWORD,:DWORD,:DWORD
DisassociateColorProfileFromDevice equ <DisassociateColorProfileFromDeviceA>

DisassociateColorProfileFromDeviceW PROTO :DWORD,:DWORD,:DWORD
EnumColorProfilesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumColorProfiles equ <EnumColorProfilesA>

EnumColorProfilesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GenerateCopyFilePaths PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetCMMInfo PROTO :DWORD,:DWORD
GetColorDirectoryA PROTO :DWORD,:DWORD,:DWORD
GetColorDirectory equ <GetColorDirectoryA>

GetColorDirectoryW PROTO :DWORD,:DWORD,:DWORD
GetColorProfileElement PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetColorProfileElementTag PROTO :DWORD,:DWORD,:DWORD
GetColorProfileFromHandle PROTO :DWORD,:DWORD,:DWORD
GetColorProfileHeader PROTO :DWORD,:DWORD
GetCountColorProfileElements PROTO :DWORD,:DWORD
GetNamedProfileInfo PROTO :DWORD,:DWORD
GetPS2ColorRenderingDictionary PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorRenderingIntent PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetPS2ColorSpaceArray PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetStandardColorSpaceProfileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetStandardColorSpaceProfile equ <GetStandardColorSpaceProfileA>

GetStandardColorSpaceProfileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
InstallColorProfileA PROTO :DWORD,:DWORD
InstallColorProfile equ <InstallColorProfileA>

InstallColorProfileW PROTO :DWORD,:DWORD
InternalGetDeviceConfig PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2CSAFromLCS PROTO :DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2ColorRenderingDictionary PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2ColorSpaceArray PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalGetPS2PreviewCRD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InternalSetDeviceConfig PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IsColorProfileTagPresent PROTO :DWORD,:DWORD,:DWORD
IsColorProfileValid PROTO :DWORD,:DWORD
OpenColorProfileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
OpenColorProfile equ <OpenColorProfileA>

OpenColorProfileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegisterCMMA PROTO :DWORD,:DWORD,:DWORD
RegisterCMM equ <RegisterCMMA>

RegisterCMMW PROTO :DWORD,:DWORD,:DWORD
SelectCMM PROTO :DWORD
SetColorProfileElement PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetColorProfileElementReference PROTO :DWORD,:DWORD,:DWORD
SetColorProfileElementSize PROTO :DWORD,:DWORD,:DWORD
SetColorProfileHeader PROTO :DWORD,:DWORD
SetStandardColorSpaceProfileA PROTO :DWORD,:DWORD,:DWORD
SetStandardColorSpaceProfile equ <SetStandardColorSpaceProfileA>

SetStandardColorSpaceProfileW PROTO :DWORD,:DWORD,:DWORD
SpoolerCopyFileEvent PROTO :DWORD,:DWORD,:DWORD
TranslateBitmapBits PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TranslateColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UninstallColorProfileA PROTO :DWORD,:DWORD,:DWORD
UninstallColorProfile equ <UninstallColorProfileA>

UninstallColorProfileW PROTO :DWORD,:DWORD,:DWORD
UnregisterCMMA PROTO :DWORD,:DWORD
UnregisterCMM equ <UnregisterCMMA>

UnregisterCMMW PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mscms.inc
echo -----------------------------------------
ENDIF
