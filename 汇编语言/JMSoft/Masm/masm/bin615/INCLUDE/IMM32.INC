  ; ===========================================
  ; imm32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF IMM32_INC
IMM32_INC equ <1>

ImmAssociateContext PROTO :DWORD,:DWORD
ImmAssociateContextEx PROTO :DWORD,:DWORD,:DWORD
ImmConfigureIMEA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmConfigureIME equ <ImmConfigureIMEA>

ImmConfigureIMEW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmCreateContext PROTO 
ImmCreateIMCC PROTO :DWORD
ImmCreateSoftKeyboard PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmDestroyContext PROTO :DWORD
ImmDestroyIMCC PROTO :DWORD
ImmDestroySoftKeyboard PROTO :DWORD
ImmDisableIME PROTO :DWORD
ImmEnumInputContext PROTO :DWORD,:DWORD,:DWORD
ImmEnumRegisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmEnumRegisterWord equ <ImmEnumRegisterWordA>

ImmEnumRegisterWordW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmEscapeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmEscape equ <ImmEscapeA>

ImmEscapeW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGenerateMessage PROTO :DWORD
ImmGetCandidateListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCandidateList equ <ImmGetCandidateListA>

ImmGetCandidateListCountA PROTO :DWORD,:DWORD
ImmGetCandidateListCount equ <ImmGetCandidateListCountA>

ImmGetCandidateListCountW PROTO :DWORD,:DWORD
ImmGetCandidateListW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCandidateWindow PROTO :DWORD,:DWORD,:DWORD
ImmGetCompositionFontA PROTO :DWORD,:DWORD
ImmGetCompositionFont equ <ImmGetCompositionFontA>

ImmGetCompositionFontW PROTO :DWORD,:DWORD
ImmGetCompositionStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCompositionString equ <ImmGetCompositionStringA>

ImmGetCompositionStringW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetCompositionWindow PROTO :DWORD,:DWORD
ImmGetContext PROTO :DWORD
ImmGetConversionListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetConversionList equ <ImmGetConversionListA>

ImmGetConversionListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetConversionStatus PROTO :DWORD,:DWORD,:DWORD
ImmGetDefaultIMEWnd PROTO :DWORD
ImmGetDescriptionA PROTO :DWORD,:DWORD,:DWORD
ImmGetDescription equ <ImmGetDescriptionA>

ImmGetDescriptionW PROTO :DWORD,:DWORD,:DWORD
ImmGetGuideLineA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetGuideLine equ <ImmGetGuideLineA>

ImmGetGuideLineW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetHotKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmGetIMCCLockCount PROTO :DWORD
ImmGetIMCCSize PROTO :DWORD
ImmGetIMCLockCount PROTO :DWORD
ImmGetIMEFileNameA PROTO :DWORD,:DWORD,:DWORD
ImmGetIMEFileName equ <ImmGetIMEFileNameA>

ImmGetIMEFileNameW PROTO :DWORD,:DWORD,:DWORD
ImmGetImeMenuItemsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetImeMenuItems equ <ImmGetImeMenuItemsA>

ImmGetImeMenuItemsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmGetOpenStatus PROTO :DWORD
ImmGetProperty PROTO :DWORD,:DWORD
ImmGetRegisterWordStyleA PROTO :DWORD,:DWORD,:DWORD
ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleA>

ImmGetRegisterWordStyleW PROTO :DWORD,:DWORD,:DWORD
ImmGetStatusWindowPos PROTO :DWORD,:DWORD
ImmGetVirtualKey PROTO :DWORD
ImmInstallIMEA PROTO :DWORD,:DWORD
ImmInstallIME equ <ImmInstallIMEA>

ImmInstallIMEW PROTO :DWORD,:DWORD
ImmIsIME PROTO :DWORD
ImmIsUIMessageA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmIsUIMessage equ <ImmIsUIMessageA>

ImmIsUIMessageW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmLockIMC PROTO :DWORD
ImmLockIMCC PROTO :DWORD
ImmNotifyIME PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmReSizeIMCC PROTO :DWORD,:DWORD
ImmRegisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmRegisterWord equ <ImmRegisterWordA>

ImmRegisterWordW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmReleaseContext PROTO :DWORD,:DWORD
ImmRequestMessageA PROTO :DWORD,:DWORD,:DWORD
ImmRequestMessage equ <ImmRequestMessageA>

ImmRequestMessageW PROTO :DWORD,:DWORD,:DWORD
ImmSetCandidateWindow PROTO :DWORD,:DWORD
ImmSetCompositionFontA PROTO :DWORD,:DWORD
ImmSetCompositionFont equ <ImmSetCompositionFontA>

ImmSetCompositionFontW PROTO :DWORD,:DWORD
ImmSetCompositionStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmSetCompositionString equ <ImmSetCompositionStringA>

ImmSetCompositionStringW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImmSetCompositionWindow PROTO :DWORD,:DWORD
ImmSetConversionStatus PROTO :DWORD,:DWORD,:DWORD
ImmSetHotKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmSetOpenStatus PROTO :DWORD,:DWORD
ImmSetStatusWindowPos PROTO :DWORD,:DWORD
ImmShowSoftKeyboard PROTO :DWORD,:DWORD
ImmSimulateHotKey PROTO :DWORD,:DWORD
ImmUnlockIMC PROTO :DWORD
ImmUnlockIMCC PROTO :DWORD
ImmUnregisterWordA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImmUnregisterWord equ <ImmUnregisterWordA>

ImmUnregisterWordW PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file imm32.inc
echo -----------------------------------------
ENDIF
