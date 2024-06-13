  ; ===========================================
  ; userenv.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF USERENV_INC
USERENV_INC equ <1>

AddDesktopItemA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddDesktopItem equ <AddDesktopItemA>

AddDesktopItemW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddItemA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddItem equ <AddItemA>

AddItemW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ApplyGroupPolicy PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ApplySystemPolicyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ApplySystemPolicy equ <ApplySystemPolicyA>

ApplySystemPolicyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopyProfileDirectoryA PROTO :DWORD,:DWORD,:DWORD
CopyProfileDirectory equ <CopyProfileDirectoryA>

CopyProfileDirectoryExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopyProfileDirectoryEx equ <CopyProfileDirectoryExA>

CopyProfileDirectoryExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CopyProfileDirectoryW PROTO :DWORD,:DWORD,:DWORD
CreateEnvironmentBlock PROTO :DWORD,:DWORD,:DWORD
CreateGroupA PROTO :DWORD,:DWORD
CreateGroup equ <CreateGroupA>

CreateGroupW PROTO :DWORD,:DWORD
CreateLinkFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateLinkFile equ <CreateLinkFileA>

CreateLinkFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateUserProfileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateUserProfile equ <CreateUserProfileA>

CreateUserProfileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeleteDesktopItemA PROTO :DWORD,:DWORD
DeleteDesktopItem equ <DeleteDesktopItemA>

DeleteDesktopItemW PROTO :DWORD,:DWORD
DeleteGroupA PROTO :DWORD,:DWORD
DeleteGroup equ <DeleteGroupA>

DeleteGroupW PROTO :DWORD,:DWORD
DeleteItemA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteItem equ <DeleteItemA>

DeleteItemW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteLinkFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteLinkFile equ <DeleteLinkFileA>

DeleteLinkFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteProfileA PROTO :DWORD,:DWORD,:DWORD
DeleteProfile equ <DeleteProfileA>

DeleteProfileW PROTO :DWORD,:DWORD,:DWORD
DestroyEnvironmentBlock PROTO :DWORD
DetermineProfilesLocation PROTO :DWORD
EnterCriticalPolicySection PROTO :DWORD
ExpandEnvironmentStringsForUserA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ExpandEnvironmentStringsForUser equ <ExpandEnvironmentStringsForUserA>

ExpandEnvironmentStringsForUserW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FreeGPOListA PROTO :DWORD
FreeGPOList equ <FreeGPOListA>

FreeGPOListW PROTO :DWORD
GetAllUsersProfileDirectoryA PROTO :DWORD,:DWORD
GetAllUsersProfileDirectory equ <GetAllUsersProfileDirectoryA>

GetAllUsersProfileDirectoryW PROTO :DWORD,:DWORD
GetAppliedGPOListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppliedGPOList equ <GetAppliedGPOListA>

GetAppliedGPOListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetDefaultUserProfileDirectoryA PROTO :DWORD,:DWORD
GetDefaultUserProfileDirectory equ <GetDefaultUserProfileDirectoryA>

GetDefaultUserProfileDirectoryW PROTO :DWORD,:DWORD
GetGPOListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetGPOList equ <GetGPOListA>

GetGPOListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetProfileType PROTO :DWORD
GetProfilesDirectoryA PROTO :DWORD,:DWORD
GetProfilesDirectory equ <GetProfilesDirectoryA>

GetProfilesDirectoryW PROTO :DWORD,:DWORD
GetSystemTempDirectoryA PROTO :DWORD,:DWORD
GetSystemTempDirectory equ <GetSystemTempDirectoryA>

GetSystemTempDirectoryW PROTO :DWORD,:DWORD
GetUserProfileDirectoryA PROTO :DWORD,:DWORD,:DWORD
GetUserProfileDirectory equ <GetUserProfileDirectoryA>

GetUserProfileDirectoryW PROTO :DWORD,:DWORD,:DWORD
InitializeProfiles PROTO :DWORD
LeaveCriticalPolicySection PROTO :DWORD
LoadUserProfileA PROTO :DWORD,:DWORD
LoadUserProfile equ <LoadUserProfileA>

LoadUserProfileW PROTO :DWORD,:DWORD
MigrateNT4ToNT5 PROTO 
ProcessGroupPolicyCompleted PROTO :DWORD,:DWORD,:DWORD
RefreshPolicy PROTO :DWORD
RegisterGPNotification PROTO :DWORD,:DWORD
ResetUserSpecialFolderPaths PROTO 
ShutdownGPOProcessing PROTO :DWORD
UnloadUserProfile PROTO :DWORD,:DWORD
UnregisterGPNotification PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file userenv.inc
echo -----------------------------------------
ENDIF
