  ; ===========================================
  ; msi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSI_INC
MSI_INC equ <1>

DllGetVersion PROTO :DWORD
MsiApplyPatchA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiApplyPatch equ <MsiApplyPatchA>

MsiApplyPatchW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiCloseAllHandles PROTO 
MsiCloseHandle PROTO :DWORD
MsiCollectUserInfoA PROTO :DWORD
MsiCollectUserInfo equ <MsiCollectUserInfoA>

MsiCollectUserInfoW PROTO :DWORD
MsiConfigureFeatureA PROTO :DWORD,:DWORD,:DWORD
MsiConfigureFeature equ <MsiConfigureFeatureA>

MsiConfigureFeatureW PROTO :DWORD,:DWORD,:DWORD
MsiConfigureProductA PROTO :DWORD,:DWORD,:DWORD
MsiConfigureProduct equ <MsiConfigureProductA>

MsiConfigureProductExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiConfigureProductEx equ <MsiConfigureProductExA>

MsiConfigureProductExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiConfigureProductW PROTO :DWORD,:DWORD,:DWORD
MsiCreateRecord PROTO :DWORD
MsiCreateTransformSummaryInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiCreateTransformSummaryInfo equ <MsiCreateTransformSummaryInfoA>

MsiCreateTransformSummaryInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiDatabaseApplyTransformA PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseApplyTransform equ <MsiDatabaseApplyTransformA>

MsiDatabaseApplyTransformW PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseCommit PROTO :DWORD
MsiDatabaseExportA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiDatabaseExport equ <MsiDatabaseExportA>

MsiDatabaseExportW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiDatabaseGenerateTransformA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiDatabaseGenerateTransform equ <MsiDatabaseGenerateTransformA>

MsiDatabaseGenerateTransformW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiDatabaseGetPrimaryKeysA PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseGetPrimaryKeys equ <MsiDatabaseGetPrimaryKeysA>

MsiDatabaseGetPrimaryKeysW PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseImportA PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseImport equ <MsiDatabaseImportA>

MsiDatabaseImportW PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseIsTablePersistentA PROTO :DWORD,:DWORD
MsiDatabaseIsTablePersistent equ <MsiDatabaseIsTablePersistentA>

MsiDatabaseIsTablePersistentW PROTO :DWORD,:DWORD
MsiDatabaseMergeA PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseMerge equ <MsiDatabaseMergeA>

MsiDatabaseMergeW PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseOpenViewA PROTO :DWORD,:DWORD,:DWORD
MsiDatabaseOpenView equ <MsiDatabaseOpenViewA>

MsiDatabaseOpenViewW PROTO :DWORD,:DWORD,:DWORD
MsiDoActionA PROTO :DWORD,:DWORD
MsiDoAction equ <MsiDoActionA>

MsiDoActionW PROTO :DWORD,:DWORD
MsiEnableLogA PROTO :DWORD,:DWORD,:DWORD
MsiEnableLog equ <MsiEnableLogA>

MsiEnableLogW PROTO :DWORD,:DWORD,:DWORD
MsiEnableUIPreview PROTO :DWORD,:DWORD
MsiEnumClientsA PROTO :DWORD,:DWORD,:DWORD
MsiEnumClients equ <MsiEnumClientsA>

MsiEnumClientsW PROTO :DWORD,:DWORD,:DWORD
MsiEnumComponentQualifiersA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiEnumComponentQualifiers equ <MsiEnumComponentQualifiersA>

MsiEnumComponentQualifiersW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiEnumComponentsA PROTO :DWORD,:DWORD
MsiEnumComponents equ <MsiEnumComponentsA>

MsiEnumComponentsW PROTO :DWORD,:DWORD
MsiEnumFeaturesA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiEnumFeatures equ <MsiEnumFeaturesA>

MsiEnumFeaturesW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiEnumPatchesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiEnumPatches equ <MsiEnumPatchesA>

MsiEnumPatchesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiEnumProductsA PROTO :DWORD,:DWORD
MsiEnumProducts equ <MsiEnumProductsA>

MsiEnumProductsW PROTO :DWORD,:DWORD
MsiEnumRelatedProductsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiEnumRelatedProducts equ <MsiEnumRelatedProductsA>

MsiEnumRelatedProductsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiEvaluateConditionA PROTO :DWORD,:DWORD
MsiEvaluateCondition equ <MsiEvaluateConditionA>

MsiEvaluateConditionW PROTO :DWORD,:DWORD
MsiFormatRecordA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiFormatRecord equ <MsiFormatRecordA>

MsiFormatRecordW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetActiveDatabase PROTO :DWORD
MsiGetComponentPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetComponentPath equ <MsiGetComponentPathA>

MsiGetComponentPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetComponentStateA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetComponentState equ <MsiGetComponentStateA>

MsiGetComponentStateW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetDatabaseState PROTO :DWORD
MsiGetFeatureCostA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureCost equ <MsiGetFeatureCostA>

MsiGetFeatureCostW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureInfo equ <MsiGetFeatureInfoA>

MsiGetFeatureInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureStateA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureState equ <MsiGetFeatureStateA>

MsiGetFeatureStateW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureUsageA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureUsage equ <MsiGetFeatureUsageA>

MsiGetFeatureUsageW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetFeatureValidStatesA PROTO :DWORD,:DWORD,:DWORD
MsiGetFeatureValidStates equ <MsiGetFeatureValidStatesA>

MsiGetFeatureValidStatesW PROTO :DWORD,:DWORD,:DWORD
MsiGetFileVersionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetFileVersion equ <MsiGetFileVersionA>

MsiGetFileVersionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetLanguage PROTO :DWORD
MsiGetLastErrorRecord PROTO 
MsiGetMode PROTO :DWORD,:DWORD
MsiGetPatchInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetPatchInfo equ <MsiGetPatchInfoA>

MsiGetPatchInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetProductCodeA PROTO :DWORD,:DWORD
MsiGetProductCode equ <MsiGetProductCodeA>

MsiGetProductCodeW PROTO :DWORD,:DWORD
MsiGetProductInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetProductInfo equ <MsiGetProductInfoA>

MsiGetProductInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetProductPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetProductProperty equ <MsiGetProductPropertyA>

MsiGetProductPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetProperty equ <MsiGetPropertyA>

MsiGetPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetShortcutTargetA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetShortcutTarget equ <MsiGetShortcutTargetA>

MsiGetShortcutTargetW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetSourcePathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetSourcePath equ <MsiGetSourcePathA>

MsiGetSourcePathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetSummaryInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetSummaryInformation equ <MsiGetSummaryInformationA>

MsiGetSummaryInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetTargetPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetTargetPath equ <MsiGetTargetPathA>

MsiGetTargetPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiGetUserInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiGetUserInfo equ <MsiGetUserInfoA>

MsiGetUserInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiInstallMissingComponentA PROTO :DWORD,:DWORD,:DWORD
MsiInstallMissingComponent equ <MsiInstallMissingComponentA>

MsiInstallMissingComponentW PROTO :DWORD,:DWORD,:DWORD
MsiInstallMissingFileA PROTO :DWORD,:DWORD
MsiInstallMissingFile equ <MsiInstallMissingFileA>

MsiInstallMissingFileW PROTO :DWORD,:DWORD
MsiInstallProductA PROTO :DWORD,:DWORD
MsiInstallProduct equ <MsiInstallProductA>

MsiInstallProductW PROTO :DWORD,:DWORD
MsiLocateComponentA PROTO :DWORD,:DWORD,:DWORD
MsiLocateComponent equ <MsiLocateComponentA>

MsiLocateComponentW PROTO :DWORD,:DWORD,:DWORD
MsiOpenDatabaseA PROTO :DWORD,:DWORD,:DWORD
MsiOpenDatabase equ <MsiOpenDatabaseA>

MsiOpenDatabaseW PROTO :DWORD,:DWORD,:DWORD
MsiOpenPackageA PROTO :DWORD,:DWORD
MsiOpenPackage equ <MsiOpenPackageA>

MsiOpenPackageW PROTO :DWORD,:DWORD
MsiOpenProductA PROTO :DWORD,:DWORD
MsiOpenProduct equ <MsiOpenProductA>

MsiOpenProductW PROTO :DWORD,:DWORD
MsiPreviewBillboardA PROTO :DWORD,:DWORD,:DWORD
MsiPreviewBillboard equ <MsiPreviewBillboardA>

MsiPreviewBillboardW PROTO :DWORD,:DWORD,:DWORD
MsiPreviewDialogA PROTO :DWORD,:DWORD
MsiPreviewDialog equ <MsiPreviewDialogA>

MsiPreviewDialogW PROTO :DWORD,:DWORD
MsiProcessMessage PROTO :DWORD,:DWORD,:DWORD
MsiProvideComponentA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiProvideComponent equ <MsiProvideComponentA>

MsiProvideComponentW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiProvideQualifiedComponentA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiProvideQualifiedComponent equ <MsiProvideQualifiedComponentA>

MsiProvideQualifiedComponentExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiProvideQualifiedComponentEx equ <MsiProvideQualifiedComponentExA>

MsiProvideQualifiedComponentExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiProvideQualifiedComponentW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiQueryFeatureStateA PROTO :DWORD,:DWORD
MsiQueryFeatureState equ <MsiQueryFeatureStateA>

MsiQueryFeatureStateW PROTO :DWORD,:DWORD
MsiQueryProductStateA PROTO :DWORD
MsiQueryProductState equ <MsiQueryProductStateA>

MsiQueryProductStateW PROTO :DWORD
MsiRecordClearData PROTO :DWORD
MsiRecordDataSize PROTO :DWORD,:DWORD
MsiRecordGetFieldCount PROTO :DWORD
MsiRecordGetInteger PROTO :DWORD,:DWORD
MsiRecordGetStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiRecordGetString equ <MsiRecordGetStringA>

MsiRecordGetStringW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiRecordIsNull PROTO :DWORD,:DWORD
MsiRecordReadStream PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiRecordSetInteger PROTO :DWORD,:DWORD,:DWORD
MsiRecordSetStreamA PROTO :DWORD,:DWORD,:DWORD
MsiRecordSetStream equ <MsiRecordSetStreamA>

MsiRecordSetStreamW PROTO :DWORD,:DWORD,:DWORD
MsiRecordSetStringA PROTO :DWORD,:DWORD,:DWORD
MsiRecordSetString equ <MsiRecordSetStringA>

MsiRecordSetStringW PROTO :DWORD,:DWORD,:DWORD
MsiReinstallFeatureA PROTO :DWORD,:DWORD,:DWORD
MsiReinstallFeature equ <MsiReinstallFeatureA>

MsiReinstallFeatureW PROTO :DWORD,:DWORD,:DWORD
MsiReinstallProductA PROTO :DWORD,:DWORD
MsiReinstallProduct equ <MsiReinstallProductA>

MsiReinstallProductW PROTO :DWORD,:DWORD
MsiSequenceA PROTO :DWORD,:DWORD,:DWORD
MsiSequence equ <MsiSequenceA>

MsiSequenceW PROTO :DWORD,:DWORD,:DWORD
MsiSetComponentStateA PROTO :DWORD,:DWORD,:DWORD
MsiSetComponentState equ <MsiSetComponentStateA>

MsiSetComponentStateW PROTO :DWORD,:DWORD,:DWORD
MsiSetExternalUIA PROTO :DWORD,:DWORD,:DWORD
MsiSetExternalUI equ <MsiSetExternalUIA>

MsiSetExternalUIW PROTO :DWORD,:DWORD,:DWORD
MsiSetFeatureAttributesA PROTO :DWORD,:DWORD,:DWORD
MsiSetFeatureAttributes equ <MsiSetFeatureAttributesA>

MsiSetFeatureAttributesW PROTO :DWORD,:DWORD,:DWORD
MsiSetFeatureStateA PROTO :DWORD,:DWORD,:DWORD
MsiSetFeatureState equ <MsiSetFeatureStateA>

MsiSetFeatureStateW PROTO :DWORD,:DWORD,:DWORD
MsiSetInstallLevel PROTO :DWORD,:DWORD
MsiSetInternalUI PROTO :DWORD,:DWORD
MsiSetMode PROTO :DWORD,:DWORD,:DWORD
MsiSetPropertyA PROTO :DWORD,:DWORD,:DWORD
MsiSetProperty equ <MsiSetPropertyA>

MsiSetPropertyW PROTO :DWORD,:DWORD,:DWORD
MsiSetTargetPathA PROTO :DWORD,:DWORD,:DWORD
MsiSetTargetPath equ <MsiSetTargetPathA>

MsiSetTargetPathW PROTO :DWORD,:DWORD,:DWORD
MsiSourceListAddSourceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiSourceListAddSource equ <MsiSourceListAddSourceA>

MsiSourceListAddSourceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MsiSourceListClearAllA PROTO :DWORD,:DWORD,:DWORD
MsiSourceListClearAll equ <MsiSourceListClearAllA>

MsiSourceListClearAllW PROTO :DWORD,:DWORD,:DWORD
MsiSourceListForceResolutionA PROTO :DWORD,:DWORD,:DWORD
MsiSourceListForceResolution equ <MsiSourceListForceResolutionA>

MsiSourceListForceResolutionW PROTO :DWORD,:DWORD,:DWORD
MsiSummaryInfoGetPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiSummaryInfoGetProperty equ <MsiSummaryInfoGetPropertyA>

MsiSummaryInfoGetPropertyCount PROTO :DWORD,:DWORD
MsiSummaryInfoGetPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiSummaryInfoPersist PROTO :DWORD
MsiSummaryInfoSetPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiSummaryInfoSetProperty equ <MsiSummaryInfoSetPropertyA>

MsiSummaryInfoSetPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MsiUseFeatureA PROTO :DWORD,:DWORD
MsiUseFeature equ <MsiUseFeatureA>

MsiUseFeatureW PROTO :DWORD,:DWORD
MsiVerifyDiskSpace PROTO :DWORD
MsiVerifyPackageA PROTO :DWORD
MsiVerifyPackage equ <MsiVerifyPackageA>

MsiVerifyPackageW PROTO :DWORD
MsiViewClose PROTO :DWORD
MsiViewExecute PROTO :DWORD,:DWORD
MsiViewFetch PROTO :DWORD,:DWORD
MsiViewGetColumnInfo PROTO :DWORD,:DWORD,:DWORD
MsiViewGetErrorA PROTO :DWORD,:DWORD,:DWORD
MsiViewGetError equ <MsiViewGetErrorA>

MsiViewGetErrorW PROTO :DWORD,:DWORD,:DWORD
MsiViewModify PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file msi.inc
echo -----------------------------------------
ENDIF
