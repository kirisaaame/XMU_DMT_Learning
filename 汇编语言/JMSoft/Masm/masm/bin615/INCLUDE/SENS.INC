  ; ===========================================
  ; sens.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SENS_INC
SENS_INC equ <1>

SensNotifyNetconEvent PROTO :DWORD
SensNotifyRasEvent PROTO :DWORD
SensNotifyWinlogonEvent PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sens.inc
echo -----------------------------------------
ENDIF
