  ; ===========================================
  ; sensapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SENSAPI_INC
SENSAPI_INC equ <1>

IsDestinationReachableA PROTO :DWORD,:DWORD
IsDestinationReachable equ <IsDestinationReachableA>

IsDestinationReachableW PROTO :DWORD,:DWORD
IsNetworkAlive PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file sensapi.inc
echo -----------------------------------------
ENDIF
