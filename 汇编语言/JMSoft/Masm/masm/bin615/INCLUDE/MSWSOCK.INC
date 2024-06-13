  ; ===========================================
  ; mswsock.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF MSWSOCK_INC
MSWSOCK_INC equ <1>

AcceptEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumProtocolsA PROTO :DWORD,:DWORD,:DWORD
EnumProtocols equ <EnumProtocolsA>

EnumProtocolsW PROTO :DWORD,:DWORD,:DWORD
GetAcceptExSockaddrs PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAddressByNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetAddressByName equ <GetAddressByNameA>

GetAddressByNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetNameByTypeA PROTO :DWORD,:DWORD,:DWORD
GetNameByType equ <GetNameByTypeA>

GetNameByTypeW PROTO :DWORD,:DWORD,:DWORD
GetServiceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetService equ <GetServiceA>

GetServiceW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetTypeByNameA PROTO :DWORD,:DWORD
GetTypeByName equ <GetTypeByNameA>

GetTypeByNameW PROTO :DWORD,:DWORD
MigrateWinsockConfiguration PROTO :DWORD,:DWORD,:DWORD
NPLoadNameSpaces PROTO :DWORD,:DWORD,:DWORD
SetServiceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetService equ <SetServiceA>

SetServiceW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
TransmitFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WSARecvEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
dn_expand PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
getnetbyname PROTO :DWORD
inet_network PROTO :DWORD
rcmd PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rexec PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
rresvport PROTO :DWORD
s_perror PROTO :DWORD,:DWORD
sethostname PROTO :DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file mswsock.inc
echo -----------------------------------------
ENDIF
