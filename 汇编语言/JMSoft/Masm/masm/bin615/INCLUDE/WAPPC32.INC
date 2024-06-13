  ; ===========================================
  ; wappc32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WAPPC32_INC
WAPPC32_INC equ <1>

APPC PROTO :DWORD
APPC_C PROTO :DWORD
APPC_C_ext PROTO :DWORD
APPC_P PROTO :DWORD
APPC_P_ext PROTO :DWORD
APPC_ext PROTO :DWORD
GetAppcConfig PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppcConfigCb PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetAppcConfigCb_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetAppcConfigEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppcConfigEx_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppcConfig_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppcReturnCode PROTO :DWORD,:DWORD,:DWORD
GetAppcReturnCode_ext PROTO :DWORD,:DWORD,:DWORD
GetAppcSignatureFields PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAppcSignatureFields_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinAPPCCancelAsyncRequest PROTO :DWORD
WinAPPCCancelAsyncRequest_ext PROTO :DWORD
WinAPPCCancelBlockingCall PROTO 
WinAPPCCancelBlockingCall_ext PROTO 
WinAPPCCancelConversation PROTO :DWORD
WinAPPCCancelConversation_ext PROTO :DWORD
WinAPPCCleanup PROTO 
WinAPPCCleanup_ext PROTO 
WinAPPCDeregisterApp PROTO 
WinAPPCGetRunSemCounters PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WinAPPCIsBlocking PROTO 
WinAPPCIsBlocking_ext PROTO 
WinAPPCQueryBlockingHook PROTO :DWORD
WinAPPCQueryBlockingHook_ext PROTO :DWORD
WinAPPCRegisterApp PROTO :DWORD,:DWORD
WinAPPCSetBlockingHook PROTO :DWORD
WinAPPCSetBlockingHook_ext PROTO :DWORD
WinAPPCStartup PROTO :DWORD,:DWORD
WinAPPCStartup_ext PROTO :DWORD,:DWORD
WinAPPCUnhookBlockingHook PROTO 
WinAPPCUnhookBlockingHook_ext PROTO 
WinAsyncAPPC PROTO :DWORD,:DWORD
WinAsyncAPPCEx PROTO :DWORD,:DWORD
WinAsyncAPPCEx_ext PROTO :DWORD,:DWORD
WinAsyncAPPCIOCP PROTO :DWORD,:DWORD
WinAsyncAPPCIOCP_ext PROTO :DWORD,:DWORD
WinAsyncAPPC_ext PROTO :DWORD,:DWORD
WinCallbackAPPC PROTO :DWORD,:DWORD
WinCallbackAPPC_ext PROTO :DWORD,:DWORD
dflt_lu_names_callback PROTO :DWORD,:DWORD,:DWORD,:DWORD
dflt_lu_names_callback_ext PROTO :DWORD,:DWORD,:DWORD,:DWORD
get_default_lus PROTO :DWORD
receive_allocate_callback PROTO :DWORD,:DWORD,:DWORD
receive_allocate_callback_ext PROTO :DWORD,:DWORD,:DWORD
signal_async_verb_complete PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file wappc32.inc
echo -----------------------------------------
ENDIF
