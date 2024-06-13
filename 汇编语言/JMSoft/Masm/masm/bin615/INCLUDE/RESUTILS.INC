  ; ===========================================
  ; resutils.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RESUTILS_INC
RESUTILS_INC equ <1>

ClusWorkerCheckTerminate PROTO :DWORD
ClusWorkerCreate PROTO :DWORD,:DWORD,:DWORD
ClusWorkerStart PROTO :DWORD
ClusWorkerTerminate PROTO :DWORD
ResUtilAddUnknownProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilCreateDirectoryTree PROTO :DWORD
ResUtilDupParameterBlock PROTO :DWORD,:DWORD,:DWORD
ResUtilDupString PROTO :DWORD
ResUtilEnumPrivateProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilEnumProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilEnumResources PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilExpandEnvironmentStrings PROTO :DWORD
ResUtilFindBinaryProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindDependentDiskResourceDriveLetter PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindDwordProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindExpandSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindExpandedSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindLongProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindMultiSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilFindSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilFreeEnvironment PROTO :DWORD
ResUtilFreeParameterBlock PROTO :DWORD,:DWORD,:DWORD
ResUtilGetAllProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetBinaryProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetBinaryValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetDwordProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetDwordValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetEnvironmentWithNetName PROTO :DWORD
ResUtilGetMultiSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetPrivateProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetPropertiesToParameterBlock PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetPropertySize PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetResourceDependency PROTO :DWORD,:DWORD
ResUtilGetResourceDependencyByClass PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetResourceDependencyByName PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetResourceDependentIPAddressProps PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetResourceNameDependency PROTO :DWORD,:DWORD
ResUtilGetSzProperty PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilGetSzValue PROTO :DWORD,:DWORD
ResUtilIsPathValid PROTO :DWORD
ResUtilIsResourceClassEqual PROTO :DWORD,:DWORD
ResUtilPropertyListFromParameterBlock PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilResourceTypesEqual PROTO :DWORD,:DWORD
ResUtilResourcesEqual PROTO :DWORD,:DWORD
ResUtilSetBinaryValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetDwordValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetExpandSzValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetMultiSzValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetPrivatePropertyList PROTO :DWORD,:DWORD,:DWORD
ResUtilSetPropertyParameterBlock PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetPropertyParameterBlockEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetPropertyTable PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetPropertyTableEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetResourceServiceEnvironment PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetResourceServiceStartParameters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetSzValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilSetUnknownProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD
ResUtilStartResourceService PROTO :DWORD,:DWORD
ResUtilStopResourceService PROTO :DWORD
ResUtilStopService PROTO :DWORD
ResUtilVerifyPrivatePropertyList PROTO :DWORD,:DWORD
ResUtilVerifyPropertyTable PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ResUtilVerifyResourceService PROTO :DWORD
ResUtilVerifyService PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file resutils.inc
echo -----------------------------------------
ENDIF
