  ; ===========================================
  ; mspbase.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSPBASE_INC
MSPBASE_INC equ <1>

TraceDeregisterW PROTO :DWORD
TraceRegisterExW PROTO :DWORD,:DWORD
TraceVprintfExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TraceVprintfEx equ <TraceVprintfExA>

gfThreadProc PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mspbase.inc
echo -----------------------------------------
ENDIF
