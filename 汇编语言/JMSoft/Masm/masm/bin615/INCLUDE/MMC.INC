  ; ===========================================
  ; mmc.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MMC_INC
MMC_INC equ <1>

MMCFreeNotifyHandle PROTO :DWORD
MMCIsMTNodeValid PROTO :DWORD,:DWORD
MMCPropPageCallback PROTO :DWORD
MMCPropertyChangeNotify PROTO :DWORD,:DWORD
MMCPropertyHelp PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mmc.inc
echo -----------------------------------------
ENDIF
