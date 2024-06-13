  ; ===========================================
  ; dplayx.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DPLAYX_INC
DPLAYX_INC equ <1>

DirectPlayCreate PROTO :DWORD,:DWORD,:DWORD
DirectPlayEnumerateA PROTO :DWORD,:DWORD
DirectPlayEnumerate equ <DirectPlayEnumerateA>

DirectPlayEnumerateW PROTO :DWORD,:DWORD
DirectPlayLobbyCreateA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DirectPlayLobbyCreate equ <DirectPlayLobbyCreateA>

DirectPlayLobbyCreateW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dplayx.inc
echo -----------------------------------------
ENDIF
