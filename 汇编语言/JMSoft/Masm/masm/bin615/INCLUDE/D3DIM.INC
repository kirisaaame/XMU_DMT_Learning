  ; ===========================================
  ; d3dim.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF D3DIM_INC
D3DIM_INC equ <1>

Direct3DCreate PROTO :DWORD,:DWORD,:DWORD
Direct3D_HALCleanUp PROTO :DWORD,:DWORD
FlushD3DDevices2 PROTO :DWORD
FlushD3DDevices PROTO :DWORD
PaletteAssociateNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD
PaletteUpdateNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SurfaceFlipNotify PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file d3dim.inc
echo -----------------------------------------
ENDIF
