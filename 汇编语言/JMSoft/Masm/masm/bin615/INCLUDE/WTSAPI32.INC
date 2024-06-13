  ; ===========================================
  ; wtsapi32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WTSAPI32_INC
WTSAPI32_INC equ <1>

WTSCloseServer PROTO :DWORD
WTSDisconnectSession PROTO :DWORD,:DWORD,:DWORD
WTSEnumerateProcessesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSEnumerateProcesses equ <WTSEnumerateProcessesA>

WTSEnumerateProcessesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSEnumerateServersA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSEnumerateServers equ <WTSEnumerateServersA>

WTSEnumerateServersW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSEnumerateSessionsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSEnumerateSessions equ <WTSEnumerateSessionsA>

WTSEnumerateSessionsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSFreeMemory PROTO :DWORD
WTSLogoffSession PROTO :DWORD,:DWORD,:DWORD
WTSOpenServerA PROTO :DWORD
WTSOpenServer equ <WTSOpenServerA>

WTSOpenServerW PROTO :DWORD
WTSQuerySessionInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSQuerySessionInformation equ <WTSQuerySessionInformationA>

WTSQuerySessionInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSQueryUserConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSQueryUserConfig equ <WTSQueryUserConfigA>

WTSQueryUserConfigW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSendMessageA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSendMessage equ <WTSSendMessageA>

WTSSendMessageW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSetSessionInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSetSessionInformation equ <WTSSetSessionInformationA>

WTSSetSessionInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSetUserConfigA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSSetUserConfig equ <WTSSetUserConfigA>

WTSSetUserConfigW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSShutdownSystem PROTO :DWORD,:DWORD
WTSTerminateProcess PROTO :DWORD,:DWORD,:DWORD
WTSVirtualChannelClose PROTO :DWORD
WTSVirtualChannelOpen PROTO :DWORD,:DWORD,:DWORD
WTSVirtualChannelPurgeInput PROTO :DWORD
WTSVirtualChannelPurgeOutput PROTO :DWORD
WTSVirtualChannelQuery PROTO :DWORD,:DWORD,:DWORD,:DWORD
WTSVirtualChannelRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WTSVirtualChannelWrite PROTO :DWORD,:DWORD,:DWORD,:DWORD
WTSWaitSystemEvent PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file wtsapi32.inc
echo -----------------------------------------
ENDIF
