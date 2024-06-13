  ; ===========================================
  ; measure.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MEASURE_INC
MEASURE_INC equ <1>

Msr_Control PROTO :DWORD
Msr_Dump PROTO :DWORD
Msr_DumpStats PROTO :DWORD
Msr_Init PROTO 
Msr_Integer PROTO :DWORD,:DWORD
Msr_Note PROTO :DWORD
Msr_Register PROTO :DWORD
Msr_Reset PROTO :DWORD
Msr_Start PROTO :DWORD
Msr_Stop PROTO :DWORD
Msr_Terminate PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file measure.inc
echo -----------------------------------------
ENDIF
