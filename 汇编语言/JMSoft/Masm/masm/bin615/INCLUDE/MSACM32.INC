  ; ===========================================
  ; msacm32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSACM32_INC
MSACM32_INC equ <1>

XRegThunkEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmDriverAddA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmDriverAdd equ <acmDriverAddA>

acmDriverAddW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmDriverClose PROTO :DWORD,:DWORD
acmDriverDetailsA PROTO :DWORD,:DWORD,:DWORD
acmDriverDetails equ <acmDriverDetailsA>

acmDriverDetailsW PROTO :DWORD,:DWORD,:DWORD
acmDriverEnum PROTO :DWORD,:DWORD,:DWORD
acmDriverID PROTO :DWORD,:DWORD,:DWORD
acmDriverMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmDriverOpen PROTO :DWORD,:DWORD,:DWORD
acmDriverPriority PROTO :DWORD,:DWORD,:DWORD
acmDriverRemove PROTO :DWORD,:DWORD
acmFilterChooseA PROTO :DWORD
acmFilterChoose equ <acmFilterChooseA>

acmFilterChooseW PROTO :DWORD
acmFilterDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFilterDetails equ <acmFilterDetailsA>

acmFilterDetailsW PROTO :DWORD,:DWORD,:DWORD
acmFilterEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFilterEnum equ <acmFilterEnumA>

acmFilterEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFilterTagDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFilterTagDetails equ <acmFilterTagDetailsA>

acmFilterTagDetailsW PROTO :DWORD,:DWORD,:DWORD
acmFilterTagEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFilterTagEnum equ <acmFilterTagEnumA>

acmFilterTagEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatChooseA PROTO :DWORD
acmFormatChoose equ <acmFormatChooseA>

acmFormatChooseW PROTO :DWORD
acmFormatDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFormatDetails equ <acmFormatDetailsA>

acmFormatDetailsW PROTO :DWORD,:DWORD,:DWORD
acmFormatEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatEnum equ <acmFormatEnumA>

acmFormatEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatSuggest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatTagDetailsA PROTO :DWORD,:DWORD,:DWORD
acmFormatTagDetails equ <acmFormatTagDetailsA>

acmFormatTagDetailsW PROTO :DWORD,:DWORD,:DWORD
acmFormatTagEnumA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmFormatTagEnum equ <acmFormatTagEnumA>

acmFormatTagEnumW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmGetVersion PROTO 
acmMessage32 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmMetrics PROTO :DWORD,:DWORD,:DWORD
acmStreamClose PROTO :DWORD,:DWORD
acmStreamConvert PROTO :DWORD,:DWORD,:DWORD
acmStreamMessage PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmStreamOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
acmStreamPrepareHeader PROTO :DWORD,:DWORD,:DWORD
acmStreamReset PROTO :DWORD,:DWORD
acmStreamSize PROTO :DWORD,:DWORD,:DWORD,:DWORD
acmStreamUnprepareHeader PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file msacm32.inc
echo -----------------------------------------
ENDIF
