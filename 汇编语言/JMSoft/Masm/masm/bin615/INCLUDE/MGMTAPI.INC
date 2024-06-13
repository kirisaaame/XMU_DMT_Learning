  ; ===========================================
  ; mgmtapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MGMTAPI_INC
MGMTAPI_INC equ <1>

SnmpMgrClose PROTO :DWORD
SnmpMgrCtl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrGetTrap PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrGetTrapEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrMIB2Disk PROTO :DWORD,:DWORD
SnmpMgrOidToStr PROTO :DWORD,:DWORD
SnmpMgrOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrRequest PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SnmpMgrStrToOid PROTO :DWORD,:DWORD
SnmpMgrTrapListen PROTO :DWORD
serverTrapThread PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mgmtapi.inc
echo -----------------------------------------
ENDIF
