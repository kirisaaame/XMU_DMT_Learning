  ; ===========================================
  ; glaux.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF GLAUX_INC
GLAUX_INC equ <1>

AllocateMemory PROTO :DWORD
AllocateZeroedMemory PROTO :DWORD
CleanUp PROTO 
ComponentFromIndex PROTO :DWORD,:DWORD,:DWORD
CreateCIPalette PROTO :DWORD
CreateRGBPalette PROTO :DWORD
DefaultHandleExpose PROTO :DWORD,:DWORD
DefaultHandleReshape PROTO :DWORD,:DWORD
DelayPaletteRealization PROTO 
DestroyThisWindow PROTO :DWORD
DibNumColors PROTO :DWORD
FillRgbPaletteEntries PROTO :DWORD,:DWORD,:DWORD
FindBestPixelFormat PROTO :DWORD,:DWORD,:DWORD
FindExactPixelFormat PROTO :DWORD,:DWORD,:DWORD
FindPixelFormat PROTO :DWORD,:DWORD
FlushPalette PROTO :DWORD,:DWORD
ForceRedraw PROTO :DWORD
FreeMemory PROTO :DWORD
GetRegistrySysColors PROTO :DWORD,:DWORD
GrabStaticEntries PROTO :DWORD
IsPixelFormatValid PROTO :DWORD,:DWORD,:DWORD
KeyDown PROTO :DWORD,:DWORD
MouseDown PROTO :DWORD,:DWORD,:DWORD
MouseLoc PROTO :DWORD,:DWORD,:DWORD
MouseUp PROTO :DWORD,:DWORD,:DWORD
PixelFormatDescriptorFromDc PROTO :DWORD,:DWORD
RawImageClose PROTO :DWORD
RawImageGetData PROTO :DWORD,:DWORD
RawImageGetRow PROTO :DWORD,:DWORD,:DWORD,:DWORD
RawImageOpenAW PROTO :DWORD,:DWORD
RealizePaletteNow PROTO :DWORD,:DWORD,:DWORD
ReleaseStaticEntries PROTO :DWORD
UpdateStaticMapping PROTO :DWORD
add3 PROTO :DWORD,:DWORD,:DWORD
auxCloseWindow PROTO 
auxCreateFont PROTO 
auxDIBImageLoadA PROTO :DWORD
auxDIBImageLoad equ <auxDIBImageLoadA>

auxDIBImageLoadW PROTO :DWORD
auxDrawStrA PROTO :DWORD
auxDrawStr equ <auxDrawStrA>

auxDrawStrAW PROTO :DWORD,:DWORD
auxDrawStrW PROTO :DWORD
auxExposeFunc PROTO :DWORD
auxGetColorMapSize PROTO 
auxGetDisplayMode PROTO 
auxGetDisplayModeID PROTO 
auxGetDisplayModePolicy PROTO 
auxGetHDC PROTO 
auxGetHGLRC PROTO 
auxGetHWND PROTO 
auxGetMouseLoc PROTO :DWORD,:DWORD
auxIdleFunc PROTO :DWORD
auxInitDisplayMode PROTO :DWORD
auxInitDisplayModeID PROTO :DWORD
auxInitDisplayModePolicy PROTO :DWORD
auxInitPosition PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxInitWindowA PROTO :DWORD
auxInitWindow equ <auxInitWindowA>

auxInitWindowAW PROTO :DWORD,:DWORD
auxInitWindowW PROTO :DWORD
auxKeyFunc PROTO :DWORD,:DWORD
auxMainLoop PROTO :DWORD
auxMouseFunc PROTO :DWORD,:DWORD,:DWORD
auxQuit PROTO 
auxRGBImageLoadA PROTO :DWORD
auxRGBImageLoad equ <auxRGBImageLoadA>

auxRGBImageLoadW PROTO :DWORD
auxReshapeFunc PROTO :DWORD
auxSetFogRamp PROTO :DWORD,:DWORD
auxSetGreyRamp PROTO 
auxSetOneColor PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxSetRGBMap PROTO :DWORD,:DWORD
auxSolidBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
auxSolidCone PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxSolidCube PROTO :DWORD,:DWORD
auxSolidCylinder PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxSolidDodecahedron PROTO :DWORD,:DWORD
auxSolidIcosahedron PROTO :DWORD,:DWORD
auxSolidOctahedron PROTO :DWORD,:DWORD
auxSolidSphere PROTO :DWORD,:DWORD
auxSolidTeapot PROTO :DWORD,:DWORD
auxSolidTetrahedron PROTO :DWORD,:DWORD
auxSolidTorus PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxSwapBuffers PROTO 
auxWireBox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
auxWireCone PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxWireCube PROTO :DWORD,:DWORD
auxWireCylinder PROTO :DWORD,:DWORD,:DWORD,:DWORD
auxWireDodecahedron PROTO :DWORD,:DWORD
auxWireIcosahedron PROTO :DWORD,:DWORD
auxWireOctahedron PROTO :DWORD,:DWORD
auxWireSphere PROTO :DWORD,:DWORD
auxWireTeapot PROTO :DWORD,:DWORD
auxWireTetrahedron PROTO :DWORD,:DWORD
auxWireTorus PROTO :DWORD,:DWORD,:DWORD,:DWORD
compareParams PROTO :DWORD,:DWORD,:DWORD
copy3 PROTO :DWORD,:DWORD
copymat3 PROTO :DWORD,:DWORD
crossprod PROTO :DWORD,:DWORD,:DWORD
diff3 PROTO :DWORD,:DWORD,:DWORD
dist3 PROTO :DWORD,:DWORD
dodecahedron PROTO :DWORD,:DWORD,:DWORD,:DWORD
dot3 PROTO :DWORD,:DWORD
doughnut PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
drawbox PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
drawtriangle PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
error PROTO :DWORD
findList PROTO :DWORD,:DWORD,:DWORD
gluCylinder PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
gluNewQuadric PROTO 
gluQuadricDrawStyle PROTO :DWORD,:DWORD
gluQuadricNormals PROTO :DWORD,:DWORD
gluSphere PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
icosahedron PROTO :DWORD,:DWORD,:DWORD,:DWORD
identifymat3 PROTO :DWORD
initdodec PROTO 
length3 PROTO :DWORD
m_popmatrix PROTO 
m_pushmatrix PROTO 
m_scale PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
m_translate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
m_xformpt PROTO :DWORD,:DWORD,:DWORD,:DWORD
m_xformptonly PROTO :DWORD,:DWORD
makeModelPtr PROTO :DWORD,:DWORD,:DWORD
normalize PROTO :DWORD
octahedron PROTO :DWORD,:DWORD,:DWORD,:DWORD
pentagon PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
perpnorm PROTO :DWORD,:DWORD,:DWORD,:DWORD
recorditem PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
samepoint PROTO :DWORD,:DWORD
scalarmult PROTO :DWORD,:DWORD,:DWORD,:DWORD
seterrorfunc PROTO :DWORD
solidTeapot PROTO :DWORD,:DWORD,:DWORD
subdivide PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
tetrahedron PROTO :DWORD,:DWORD,:DWORD,:DWORD
tkCloseWindow PROTO 
tkCreateBitmapFont PROTO :DWORD
tkCreateFilledFont PROTO :DWORD
tkCreateOutlineFont PROTO :DWORD
tkCreateStrokeFont PROTO :DWORD
tkDIBImageLoad PROTO :DWORD
tkDIBImageLoadAW PROTO :DWORD,:DWORD
tkDisplayFunc PROTO :DWORD
tkDrawStr PROTO :DWORD,:DWORD
tkErrorPopups PROTO :DWORD
tkExec PROTO 
tkExposeFunc PROTO :DWORD
tkGetColorMapSize PROTO 
tkGetDisplayMode PROTO 
tkGetDisplayModeID PROTO 
tkGetDisplayModePolicy PROTO 
tkGetHDC PROTO 
tkGetHRC PROTO 
tkGetHWND PROTO 
tkGetMouseLoc PROTO :DWORD,:DWORD
tkIdleFunc PROTO :DWORD
tkInitDisplayMode PROTO :DWORD
tkInitDisplayModeID PROTO :DWORD
tkInitDisplayModePolicy PROTO :DWORD
tkInitPosition PROTO :DWORD,:DWORD,:DWORD,:DWORD
tkInitWindow PROTO :DWORD
tkInitWindowAW PROTO :DWORD,:DWORD
tkKeyDownFunc PROTO :DWORD
tkMouseDownFunc PROTO :DWORD
tkMouseMoveFunc PROTO :DWORD
tkMouseUpFunc PROTO :DWORD
tkQuit PROTO 
tkRGBImageLoad PROTO :DWORD
tkRGBImageLoadAW PROTO :DWORD,:DWORD
tkReshapeFunc PROTO :DWORD
tkSetFogRamp PROTO :DWORD,:DWORD
tkSetGreyRamp PROTO 
tkSetOneColor PROTO :DWORD,:DWORD,:DWORD,:DWORD
tkSetRGBMap PROTO :DWORD,:DWORD
tkSwapBuffers PROTO 
tkWndProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
wireTeapot PROTO :DWORD,:DWORD,:DWORD
xformvec3 PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file glaux.inc
echo -----------------------------------------
ENDIF
