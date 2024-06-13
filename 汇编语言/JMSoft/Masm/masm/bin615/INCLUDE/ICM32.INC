  ; ===========================================
  ; icm32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ICM32_INC
ICM32_INC equ <1>

CMCheckColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMCheckColorsInGamut PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMCheckRGBs PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMConvertColorNameToIndex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMConvertIndexToColorName PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMCreateDeviceLinkProfile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMCreateMultiProfileTransform PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMCreateProfile PROTO :DWORD,:DWORD
CMCreateProfileW PROTO :DWORD,:DWORD
CMCreateTransform PROTO :DWORD,:DWORD,:DWORD
CMCreateTransformExt PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMCreateTransformExtW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMCreateTransformW PROTO :DWORD,:DWORD,:DWORD
CMDeleteTransform PROTO :DWORD
CMGetInfo PROTO :DWORD
CMGetNamedProfileInfo PROTO :DWORD,:DWORD
CMIsProfileValid PROTO :DWORD,:DWORD
CMTranslateColors PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGB PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGBs PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CMTranslateRGBsExt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file icm32.inc
echo -----------------------------------------
ENDIF
