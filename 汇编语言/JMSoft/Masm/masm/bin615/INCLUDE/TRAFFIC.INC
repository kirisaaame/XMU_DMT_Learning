  ; ===========================================
  ; traffic.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF TRAFFIC_INC
TRAFFIC_INC equ <1>

TcAddClassMap PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcAddFilter PROTO :DWORD,:DWORD,:DWORD
TcAddFlow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcCloseInterface PROTO :DWORD
TcDeleteFilter PROTO :DWORD
TcDeleteFlow PROTO :DWORD
TcDeregisterClient PROTO :DWORD
TcEnumerateFlows PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcEnumerateInterfaces PROTO :DWORD,:DWORD,:DWORD
TcGetFlowNameA PROTO :DWORD,:DWORD,:DWORD
TcGetFlowName equ <TcGetFlowNameA>

TcGetFlowNameW PROTO :DWORD,:DWORD,:DWORD
TcModifyFlow PROTO :DWORD,:DWORD
TcOpenInterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcOpenInterface equ <TcOpenInterfaceA>

TcOpenInterfaceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcQueryFlowA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcQueryFlow equ <TcQueryFlowA>

TcQueryFlowW PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcQueryInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TcRegisterClient PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcSetFlowA PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcSetFlow equ <TcSetFlowA>

TcSetFlowW PROTO :DWORD,:DWORD,:DWORD,:DWORD
TcSetInterface PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file traffic.inc
echo -----------------------------------------
ENDIF
