  ; ===========================================
  ; wsnmp32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WSNMP32_INC
WSNMP32_INC equ <1>

SnmpCancelMsg PROTO :DWORD,:DWORD
SnmpCleanup PROTO 
SnmpClose PROTO :DWORD
SnmpContextToStr PROTO :DWORD,:DWORD
SnmpConveyAgentAddress PROTO :DWORD
SnmpCountVbl PROTO :DWORD
SnmpCreatePdu PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpCreateSession PROTO :DWORD,:DWORD,:DWORD,:DWORD
SnmpCreateVbl PROTO :DWORD,:DWORD,:DWORD
SnmpDecodeMsg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpDeleteVb PROTO :DWORD,:DWORD
SnmpDuplicatePdu PROTO :DWORD,:DWORD
SnmpDuplicateVbl PROTO :DWORD,:DWORD
SnmpEncodeMsg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpEntityToStr PROTO :DWORD,:DWORD,:DWORD
SnmpFreeContext PROTO :DWORD
SnmpFreeDescriptor PROTO :DWORD,:DWORD
SnmpFreeEntity PROTO :DWORD
SnmpFreePdu PROTO :DWORD
SnmpFreeVbl PROTO :DWORD
SnmpGetLastError PROTO :DWORD
SnmpGetPduData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpGetRetransmitMode PROTO :DWORD
SnmpGetRetry PROTO :DWORD,:DWORD,:DWORD
SnmpGetTimeout PROTO :DWORD,:DWORD,:DWORD
SnmpGetTranslateMode PROTO :DWORD
SnmpGetVb PROTO :DWORD,:DWORD,:DWORD,:DWORD
SnmpGetVendorInfo PROTO :DWORD
SnmpListen PROTO :DWORD,:DWORD
SnmpOidCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD
SnmpOidCopy PROTO :DWORD,:DWORD
SnmpOidToStr PROTO :DWORD,:DWORD,:DWORD
SnmpOpen PROTO :DWORD,:DWORD
SnmpRecvMsg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpRegister PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpSendMsg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpSetAgentAddress PROTO :DWORD
SnmpSetPduData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpSetPort PROTO :DWORD,:DWORD
SnmpSetRetransmitMode PROTO :DWORD
SnmpSetRetry PROTO :DWORD,:DWORD
SnmpSetTimeout PROTO :DWORD,:DWORD
SnmpSetTranslateMode PROTO :DWORD
SnmpSetVb PROTO :DWORD,:DWORD,:DWORD,:DWORD
SnmpStartup PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpStrToContext PROTO :DWORD,:DWORD
SnmpStrToEntity PROTO :DWORD,:DWORD
SnmpStrToOid PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file wsnmp32.inc
echo -----------------------------------------
ENDIF
