  ; ===========================================
  ; bhmon.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF BHMON_INC
BHMON_INC equ <1>

BhClosePerformanceData PROTO 
BhCollectPerformanceData PROTO :DWORD,:DWORD,:DWORD,:DWORD
BhOpenPerformanceData PROTO :DWORD
_BhClosePerformanceData PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file bhmon.inc
echo -----------------------------------------
ENDIF
