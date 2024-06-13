  ; ===========================================
  ; friendly.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF FRIENDLY_INC
FRIENDLY_INC equ <1>

Friendly_HookFileEBProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
Friendly_HookFileLBProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
Friendly_HookProc PROTO :DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file friendly.inc
echo -----------------------------------------
ENDIF
