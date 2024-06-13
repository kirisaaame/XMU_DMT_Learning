  ; ===========================================
  ; comctl32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF COMCTL32_INC
COMCTL32_INC equ <1>

CreateMappedBitmap PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreatePropertySheetPageA PROTO :DWORD
CreatePropertySheetPage equ <CreatePropertySheetPageA>

CreatePropertySheetPageW PROTO :DWORD
CreateStatusWindowA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateStatusWindow equ <CreateStatusWindowA>

CreateStatusWindowW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateToolbar PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateToolbarEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateUpDownControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DestroyPropertySheetPage PROTO :DWORD
DrawInsert PROTO :DWORD,:DWORD,:DWORD
DrawStatusTextA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DrawStatusText equ <DrawStatusTextA>

DrawStatusTextW PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlatSB_EnableScrollBar PROTO :DWORD,:DWORD,:DWORD
FlatSB_GetScrollInfo PROTO :DWORD,:DWORD,:DWORD
FlatSB_GetScrollPos PROTO :DWORD,:DWORD
FlatSB_GetScrollProp PROTO :DWORD,:DWORD,:DWORD
FlatSB_GetScrollRange PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlatSB_SetScrollInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlatSB_SetScrollPos PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlatSB_SetScrollProp PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlatSB_SetScrollRange PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FlatSB_ShowScrollBar PROTO :DWORD,:DWORD,:DWORD
GetEffectiveClientRect PROTO :DWORD,:DWORD,:DWORD
GetMUILanguage PROTO 
ImageList_Add PROTO :DWORD,:DWORD,:DWORD
ImageList_AddIcon PROTO :DWORD,:DWORD
ImageList_AddMasked PROTO :DWORD,:DWORD,:DWORD
ImageList_BeginDrag PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImageList_Copy PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_Create PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_Destroy PROTO :DWORD
ImageList_DragEnter PROTO :DWORD,:DWORD,:DWORD
ImageList_DragLeave PROTO :DWORD
ImageList_DragMove PROTO :DWORD,:DWORD
ImageList_DragShowNolock PROTO :DWORD
ImageList_Draw PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_DrawEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_DrawIndirect PROTO :DWORD
ImageList_Duplicate PROTO :DWORD
ImageList_EndDrag PROTO 
ImageList_GetBkColor PROTO :DWORD
ImageList_GetDragImage PROTO :DWORD,:DWORD
ImageList_GetIcon PROTO :DWORD,:DWORD,:DWORD
ImageList_GetIconSize PROTO :DWORD,:DWORD,:DWORD
ImageList_GetImageCount PROTO :DWORD
ImageList_GetImageInfo PROTO :DWORD,:DWORD,:DWORD
ImageList_GetImageRect PROTO :DWORD,:DWORD,:DWORD
ImageList_LoadImageA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_LoadImage equ <ImageList_LoadImageA>

ImageList_LoadImageW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_Merge PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImageList_Read PROTO :DWORD
ImageList_Remove PROTO :DWORD,:DWORD
ImageList_Replace PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImageList_ReplaceIcon PROTO :DWORD,:DWORD,:DWORD
ImageList_SetBkColor PROTO :DWORD,:DWORD
ImageList_SetDragCursorImage PROTO :DWORD,:DWORD,:DWORD,:DWORD
ImageList_SetFilter PROTO :DWORD,:DWORD,:DWORD
ImageList_SetFlags PROTO :DWORD,:DWORD
ImageList_SetIconSize PROTO :DWORD,:DWORD,:DWORD
ImageList_SetImageCount PROTO :DWORD,:DWORD
ImageList_SetOverlayImage PROTO :DWORD,:DWORD,:DWORD
ImageList_Write PROTO :DWORD,:DWORD
InitCommonControls PROTO 
InitCommonControlsEx PROTO :DWORD
InitMUILanguage PROTO :DWORD
InitializeFlatSB PROTO :DWORD
LBItemFromPt PROTO :DWORD,:DWORD,:DWORD,:DWORD
MakeDragList PROTO :DWORD
MenuHelp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PropertySheetA PROTO :DWORD
PropertySheet equ <PropertySheetA>

PropertySheetW PROTO :DWORD
ShowHideMenuCtl PROTO :DWORD,:DWORD,:DWORD
UninitializeFlatSB PROTO :DWORD
_TrackMouseEvent PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file comctl32.inc
echo -----------------------------------------
ENDIF
