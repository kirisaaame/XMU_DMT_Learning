  ; ===========================================
  ; hlink.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF HLINK_INC
HLINK_INC equ <1>

HlinkClone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateBrowseContext PROTO :DWORD,:DWORD,:DWORD
HlinkCreateExtensionServices PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromMoniker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateFromString PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcut PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcutFromMoniker PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkCreateShortcutFromString PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkGetSpecialReference PROTO :DWORD,:DWORD
HlinkGetValueFromParams PROTO :DWORD,:DWORD,:DWORD
HlinkIsShortcut PROTO :DWORD
HlinkNavigate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkNavigateToStringReference PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkOnNavigate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkOnRenameDocument PROTO :DWORD,:DWORD,:DWORD,:DWORD
HlinkParseDisplayName PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkPreprocessMoniker PROTO :DWORD,:DWORD,:DWORD
HlinkQueryCreateFromData PROTO :DWORD
HlinkResolveMonikerForData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkResolveShortcut PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkResolveShortcutToMoniker PROTO :DWORD,:DWORD,:DWORD
HlinkResolveShortcutToString PROTO :DWORD,:DWORD,:DWORD
HlinkResolveStringForData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HlinkSetSpecialReference PROTO :DWORD,:DWORD
HlinkTranslateURL PROTO :DWORD,:DWORD,:DWORD
HlinkUpdateStackItem PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OleSaveToStreamEx PROTO :DWORD,:DWORD,:DWORD
_HlinkClone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file hlink.inc
echo -----------------------------------------
ENDIF
