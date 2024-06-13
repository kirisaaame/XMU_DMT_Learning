  ; ===========================================
  ; secur32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SECUR32_INC
SECUR32_INC equ <1>

AcceptSecurityContext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AcquireCredentialsHandleA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AcquireCredentialsHandle equ <AcquireCredentialsHandleA>

AcquireCredentialsHandleW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddCredentialsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddCredentials equ <AddCredentialsA>

AddCredentialsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddSecurityPackageA PROTO :DWORD,:DWORD
AddSecurityPackage equ <AddSecurityPackageA>

AddSecurityPackageW PROTO :DWORD,:DWORD
ApplyControlToken PROTO :DWORD,:DWORD
CompleteAuthToken PROTO :DWORD,:DWORD
DecryptMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteSecurityContext PROTO :DWORD
DeleteSecurityPackageA PROTO :DWORD
DeleteSecurityPackage equ <DeleteSecurityPackageA>

DeleteSecurityPackageW PROTO :DWORD
EncryptMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnumerateSecurityPackagesA PROTO :DWORD,:DWORD
EnumerateSecurityPackages equ <EnumerateSecurityPackagesA>

EnumerateSecurityPackagesW PROTO :DWORD,:DWORD
ExportSecurityContext PROTO :DWORD,:DWORD,:DWORD,:DWORD
FreeContextBuffer PROTO :DWORD
FreeCredentialsHandle PROTO :DWORD
GetComputerObjectNameA PROTO :DWORD,:DWORD,:DWORD
GetComputerObjectName equ <GetComputerObjectNameA>

GetComputerObjectNameW PROTO :DWORD,:DWORD,:DWORD
GetUserNameExA PROTO :DWORD,:DWORD,:DWORD
GetUserNameEx equ <GetUserNameExA>

GetUserNameExW PROTO :DWORD,:DWORD,:DWORD
ImpersonateSecurityContext PROTO :DWORD
ImportSecurityContextA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImportSecurityContext equ <ImportSecurityContextA>

ImportSecurityContextW PROTO :DWORD,:DWORD,:DWORD,:DWORD
InitSecurityInterfaceA PROTO 
InitSecurityInterface equ <InitSecurityInterfaceA>

InitSecurityInterfaceW PROTO 
InitializeSecurityContextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InitializeSecurityContext equ <InitializeSecurityContextA>

InitializeSecurityContextW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaCallAuthenticationPackage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaConnectUntrusted PROTO :DWORD
LsaDeregisterLogonProcess PROTO :DWORD
LsaFreeReturnBuffer PROTO :DWORD
LsaLogonUser PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LsaLookupAuthenticationPackage PROTO :DWORD,:DWORD,:DWORD
LsaRegisterLogonProcess PROTO :DWORD,:DWORD,:DWORD
LsaRegisterPolicyChangeNotification PROTO :DWORD,:DWORD
LsaUnregisterPolicyChangeNotification PROTO :DWORD,:DWORD
MakeSignature PROTO :DWORD,:DWORD,:DWORD,:DWORD
QueryContextAttributesA PROTO :DWORD,:DWORD,:DWORD
QueryContextAttributes equ <QueryContextAttributesA>

QueryContextAttributesW PROTO :DWORD,:DWORD,:DWORD
QueryCredentialsAttributesA PROTO :DWORD,:DWORD,:DWORD
QueryCredentialsAttributes equ <QueryCredentialsAttributesA>

QueryCredentialsAttributesW PROTO :DWORD,:DWORD,:DWORD
QuerySecurityContextToken PROTO :DWORD,:DWORD
QuerySecurityPackageInfoA PROTO :DWORD,:DWORD
QuerySecurityPackageInfo equ <QuerySecurityPackageInfoA>

QuerySecurityPackageInfoW PROTO :DWORD,:DWORD
RevertSecurityContext PROTO :DWORD
SaslAcceptSecurityContext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaslEnumerateProfilesA PROTO :DWORD,:DWORD
SaslEnumerateProfiles equ <SaslEnumerateProfilesA>

SaslEnumerateProfilesW PROTO :DWORD,:DWORD
SaslGetProfilePackageA PROTO :DWORD,:DWORD
SaslGetProfilePackage equ <SaslGetProfilePackageA>

SaslGetProfilePackageW PROTO :DWORD,:DWORD
SaslIdentifyPackageA PROTO :DWORD,:DWORD
SaslIdentifyPackage equ <SaslIdentifyPackageA>

SaslIdentifyPackageW PROTO :DWORD,:DWORD
SaslInitializeSecurityContextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SaslInitializeSecurityContext equ <SaslInitializeSecurityContextA>

SaslInitializeSecurityContextW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SealMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
TranslateNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TranslateName equ <TranslateNameA>

TranslateNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UnsealMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
VerifySignature PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file secur32.inc
echo -----------------------------------------
ENDIF
