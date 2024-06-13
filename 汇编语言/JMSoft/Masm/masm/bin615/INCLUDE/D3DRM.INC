  ; ===========================================
  ; d3drm.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF D3DRM_INC
D3DRM_INC equ <1>

D3DRMColorGetAlpha PROTO :DWORD
D3DRMColorGetBlue PROTO :DWORD
D3DRMColorGetGreen PROTO :DWORD
D3DRMColorGetRed PROTO :DWORD
D3DRMCreateColorRGBA PROTO :DWORD,:DWORD,:DWORD,:DWORD
D3DRMCreateColorRGB equ <D3DRMCreateColorRGBA>

D3DRMMatrixFromQuaternion PROTO :DWORD,:DWORD
D3DRMQuaternionFromRotation PROTO :DWORD,:DWORD,:DWORD
D3DRMQuaternionMultiply PROTO :DWORD,:DWORD,:DWORD
D3DRMQuaternionSlerp PROTO :DWORD,:DWORD,:DWORD,:DWORD
D3DRMVectorAdd PROTO :DWORD,:DWORD,:DWORD
D3DRMVectorCrossProduct PROTO :DWORD,:DWORD,:DWORD
D3DRMVectorDotProduct PROTO :DWORD,:DWORD
D3DRMVectorModulus PROTO :DWORD
D3DRMVectorNormalize PROTO :DWORD
D3DRMVectorRandom PROTO :DWORD
D3DRMVectorReflect PROTO :DWORD,:DWORD,:DWORD
D3DRMVectorRotate PROTO :DWORD,:DWORD,:DWORD,:DWORD
D3DRMVectorScale PROTO :DWORD,:DWORD,:DWORD
D3DRMVectorSubtract PROTO :DWORD,:DWORD,:DWORD
Direct3DRMCreate PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file d3drm.inc
echo -----------------------------------------
ENDIF
