  ; ===========================================
  ; rtutils.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF RTUTILS_INC
RTUTILS_INC equ <1>

CreateWaitEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateWaitEventBinding PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateWaitTimer PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeRegisterWaitEventBinding PROTO :DWORD
DeRegisterWaitEventBindingSelf PROTO :DWORD
DeRegisterWaitEventsTimers PROTO :DWORD,:DWORD
DeRegisterWaitEventsTimersSelf PROTO :DWORD,:DWORD
DebugPrintWaitWorkerThreads PROTO :DWORD
LogErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD
LogError equ <LogErrorA>

LogErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD
LogEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD
LogEvent equ <LogEventA>

LogEventW PROTO :DWORD,:DWORD,:DWORD,:DWORD
MprSetupProtocolEnum PROTO :DWORD,:DWORD,:DWORD
MprSetupProtocolFree PROTO :DWORD
QueueWorkItem PROTO :DWORD,:DWORD,:DWORD
RegisterWaitEventBinding PROTO :DWORD
RegisterWaitEventsTimers PROTO :DWORD,:DWORD
RouterAssert PROTO :DWORD,:DWORD,:DWORD,:DWORD
RouterGetErrorStringA PROTO :DWORD,:DWORD
RouterGetErrorString equ <RouterGetErrorStringA>

RouterGetErrorStringW PROTO :DWORD,:DWORD
RouterLogDeregisterA PROTO :DWORD
RouterLogDeregister equ <RouterLogDeregisterA>

RouterLogDeregisterW PROTO :DWORD
RouterLogEventA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEvent equ <RouterLogEventA>

RouterLogEventDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventData equ <RouterLogEventDataA>

RouterLogEventDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventStringA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventString equ <RouterLogEventStringA>

RouterLogEventStringW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventValistExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventValistEx equ <RouterLogEventValistExA>

RouterLogEventValistExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogEventW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RouterLogRegisterA PROTO :DWORD
RouterLogRegister equ <RouterLogRegisterA>

RouterLogRegisterW PROTO :DWORD
SetIoCompletionProc PROTO :DWORD,:DWORD
TraceDeregisterA PROTO :DWORD
TraceDeregister equ <TraceDeregisterA>

TraceDeregisterExA PROTO :DWORD,:DWORD
TraceDeregisterEx equ <TraceDeregisterExA>

TraceDeregisterExW PROTO :DWORD,:DWORD
TraceDeregisterW PROTO :DWORD
TraceDumpExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TraceDumpEx equ <TraceDumpExA>

TraceDumpExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TraceGetConsoleA PROTO :DWORD,:DWORD
TraceGetConsole equ <TraceGetConsoleA>

TraceGetConsoleW PROTO :DWORD,:DWORD
TracePutsExA PROTO :DWORD,:DWORD,:DWORD
TracePutsEx equ <TracePutsExA>

TracePutsExW PROTO :DWORD,:DWORD,:DWORD
TraceRegisterExA PROTO :DWORD,:DWORD
TraceRegisterEx equ <TraceRegisterExA>

TraceRegisterExW PROTO :DWORD,:DWORD
TraceVprintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TraceVprintfEx equ <TraceVprintfExA>

TraceVprintfExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
UpdateWaitTimer PROTO :DWORD,:DWORD
WTFreeEvent PROTO :DWORD
WTFreeTimer PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file rtutils.inc
echo -----------------------------------------
ENDIF
