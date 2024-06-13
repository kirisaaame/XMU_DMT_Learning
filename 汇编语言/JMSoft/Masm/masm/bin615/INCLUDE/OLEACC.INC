  ; ===========================================
  ; oleacc.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF OLEACC_INC
OLEACC_INC equ <1>

AccessibleChildren PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromPoint PROTO :DWORD,:DWORD,:DWORD,:DWORD
AccessibleObjectFromWindow PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateStdAccessibleObject PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateStdAccessibleProxyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateStdAccessibleProxy equ <CreateStdAccessibleProxyA>

CreateStdAccessibleProxyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetOleaccVersionInfo PROTO :DWORD,:DWORD
GetRoleTextA PROTO :DWORD,:DWORD,:DWORD
GetRoleText equ <GetRoleTextA>

GetRoleTextW PROTO :DWORD,:DWORD,:DWORD
GetStateTextA PROTO :DWORD,:DWORD,:DWORD
GetStateText equ <GetStateTextA>

GetStateTextW PROTO :DWORD,:DWORD,:DWORD
LresultFromObject PROTO :DWORD,:DWORD,:DWORD
ObjectFromLresult PROTO :DWORD,:DWORD,:DWORD,:DWORD
WindowFromAccessibleObject PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file oleacc.inc
echo -----------------------------------------
ENDIF
