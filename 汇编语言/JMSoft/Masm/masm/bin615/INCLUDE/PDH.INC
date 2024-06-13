  ; ===========================================
  ; pdh.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF PDH_INC
PDH_INC equ <1>

PdhAddCounterA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhAddCounter equ <PdhAddCounterA>

PdhAddCounterW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhBrowseCountersA PROTO :DWORD
PdhBrowseCounters equ <PdhBrowseCountersA>

PdhBrowseCountersW PROTO :DWORD
PdhCalculateCounterFromRawValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhCloseLog PROTO :DWORD,:DWORD
PdhCloseQuery PROTO :DWORD
PdhCollectQueryData PROTO :DWORD
PdhCollectQueryDataEx PROTO :DWORD,:DWORD,:DWORD
PdhComputeCounterStatistics PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhConnectMachineA PROTO :DWORD
PdhConnectMachine equ <PdhConnectMachineA>

PdhConnectMachineW PROTO :DWORD
PdhEnumMachinesA PROTO :DWORD,:DWORD,:DWORD
PdhEnumMachines equ <PdhEnumMachinesA>

PdhEnumMachinesW PROTO :DWORD,:DWORD,:DWORD
PdhEnumObjectItemsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEnumObjectItems equ <PdhEnumObjectItemsA>

PdhEnumObjectItemsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEnumObjectsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhEnumObjects equ <PdhEnumObjectsA>

PdhEnumObjectsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhExpandCounterPathA PROTO :DWORD,:DWORD,:DWORD
PdhExpandCounterPath equ <PdhExpandCounterPathA>

PdhExpandCounterPathW PROTO :DWORD,:DWORD,:DWORD
PdhExpandWildCardPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhExpandWildCardPath equ <PdhExpandWildCardPathA>

PdhExpandWildCardPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhFormatFromRawValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetCounterInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetCounterInfo equ <PdhGetCounterInfoA>

PdhGetCounterInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetCounterTimeBase PROTO :DWORD,:DWORD
PdhGetDataSourceTimeRangeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDataSourceTimeRange equ <PdhGetDataSourceTimeRangeA>

PdhGetDataSourceTimeRangeW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfCounterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfCounter equ <PdhGetDefaultPerfCounterA>

PdhGetDefaultPerfCounterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfObjectA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDefaultPerfObject equ <PdhGetDefaultPerfObjectA>

PdhGetDefaultPerfObjectW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetDllVersion PROTO :DWORD
PdhGetFormattedCounterArrayA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetFormattedCounterArray equ <PdhGetFormattedCounterArrayA>

PdhGetFormattedCounterArrayW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhGetFormattedCounterValue PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetLogFileSize PROTO :DWORD,:DWORD
PdhGetRawCounterArrayA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetRawCounterArray equ <PdhGetRawCounterArrayA>

PdhGetRawCounterArrayW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhGetRawCounterValue PROTO :DWORD,:DWORD,:DWORD
PdhIsRealTimeQuery PROTO :DWORD
PdhLogServiceCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhLogServiceCommand equ <PdhLogServiceCommandA>

PdhLogServiceCommandW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhLogServiceControlA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhLogServiceControl equ <PdhLogServiceControlA>

PdhLogServiceControlW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhLookupPerfIndexByNameA PROTO :DWORD,:DWORD,:DWORD
PdhLookupPerfIndexByName equ <PdhLookupPerfIndexByNameA>

PdhLookupPerfIndexByNameW PROTO :DWORD,:DWORD,:DWORD
PdhLookupPerfNameByIndexA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhLookupPerfNameByIndex equ <PdhLookupPerfNameByIndexA>

PdhLookupPerfNameByIndexW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhMakeCounterPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhMakeCounterPath equ <PdhMakeCounterPathA>

PdhMakeCounterPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhOpenLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhOpenLog equ <PdhOpenLogA>

PdhOpenLogW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhOpenQueryA PROTO :DWORD,:DWORD,:DWORD
PdhOpenQuery equ <PdhOpenQueryA>

PdhOpenQueryW PROTO :DWORD,:DWORD,:DWORD
PdhParseCounterPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhParseCounterPath equ <PdhParseCounterPathA>

PdhParseCounterPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhParseInstanceNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhParseInstanceName equ <PdhParseInstanceNameA>

PdhParseInstanceNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhReadRawLogRecord PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhRemoveCounter PROTO :DWORD
PdhSelectDataSourceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhSelectDataSource equ <PdhSelectDataSourceA>

PdhSelectDataSourceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhSetCounterScaleFactor PROTO :DWORD,:DWORD
PdhSetDefaultRealTimeDataSource PROTO :DWORD
PdhSetQueryTimeRange PROTO :DWORD,:DWORD
PdhUpdateLogA PROTO :DWORD,:DWORD
PdhUpdateLog equ <PdhUpdateLogA>

PdhUpdateLogFileCatalog PROTO :DWORD
PdhUpdateLogW PROTO :DWORD,:DWORD
PdhValidatePathA PROTO :DWORD
PdhValidatePath equ <PdhValidatePathA>

PdhValidatePathW PROTO :DWORD
PdhVbAddCounter PROTO :DWORD,:DWORD,:DWORD
PdhVbCreateCounterPathList PROTO :DWORD,:DWORD
PdhVbGetCounterPathElements PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhVbGetCounterPathFromList PROTO :DWORD,:DWORD,:DWORD
PdhVbGetDoubleCounterValue PROTO :DWORD,:DWORD
PdhVbGetLogFileSize PROTO :DWORD,:DWORD
PdhVbGetOneCounterPath PROTO :DWORD,:DWORD,:DWORD,:DWORD
PdhVbIsGoodStatus PROTO :DWORD
PdhVbOpenLog PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PdhVbOpenQuery PROTO :DWORD
PdhVbUpdateLog PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file pdh.inc
echo -----------------------------------------
ENDIF
