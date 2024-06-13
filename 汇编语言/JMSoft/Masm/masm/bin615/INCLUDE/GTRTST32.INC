  ; ===========================================
  ; gtrtst32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF GTRTST32_INC
GTRTST32_INC equ <1>

AbortRun PROTO :DWORD,:DWORD
CElapsed PROTO :DWORD,:DWORD,:DWORD
CenterDialog PROTO :DWORD
CreateTestList PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DrawBitmap PROTO :DWORD,:DWORD,:DWORD,:DWORD
FAbortCheck PROTO 
FindFileDir PROTO :DWORD,:DWORD
GetAutoTests PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetIniNameUsage PROTO :DWORD
GetLogFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetRCString PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetSetLastRunInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTestCases PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetTestGroups PROTO :DWORD,:DWORD,:DWORD,:DWORD
IsChicago PROTO 
ManageGroups PROTO :DWORD,:DWORD
ManageSources PROTO :DWORD,:DWORD
ManageTests PROTO :DWORD,:DWORD
RefreshInstalledTestList PROTO :DWORD,:DWORD,:DWORD
ResetForRunList PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RunAutoTest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetGatorIniPath PROTO :DWORD
SetupFileInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VerifyTestCaseCount PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file gtrtst32.inc
echo -----------------------------------------
ENDIF
