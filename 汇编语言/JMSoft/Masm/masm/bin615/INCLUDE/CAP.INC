  ; ===========================================
  ; cap.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF CAP_INC
CAP_INC equ <1>

DumpCAP PROTO 
StartCAP PROTO 
StopCAP PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file cap.inc
echo -----------------------------------------
ENDIF
