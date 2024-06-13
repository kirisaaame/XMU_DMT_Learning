  ; ===========================================
  ; webpost.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WEBPOST_INC
WEBPOST_INC equ <1>

WpBindToSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpBindToSite equ <WpBindToSiteA>

WpBindToSiteW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpCreateSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpCreateSite equ <WpCreateSiteA>

WpCreateSiteW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpDeleteSiteA PROTO :DWORD
WpDeleteSite equ <WpDeleteSiteA>

WpDeleteSiteW PROTO :DWORD
WpDoesSiteExistA PROTO :DWORD,:DWORD
WpDoesSiteExist equ <WpDoesSiteExistA>

WpDoesSiteExistW PROTO :DWORD,:DWORD
WpEnumProvidersA PROTO :DWORD,:DWORD,:DWORD
WpEnumProviders equ <WpEnumProvidersA>

WpEnumProvidersW PROTO :DWORD,:DWORD,:DWORD
WpGetErrorStringA PROTO :DWORD,:DWORD,:DWORD
WpGetErrorString equ <WpGetErrorStringA>

WpGetErrorStringW PROTO :DWORD,:DWORD,:DWORD
WpListSitesA PROTO :DWORD,:DWORD,:DWORD
WpListSites equ <WpListSitesA>

WpListSitesW PROTO :DWORD,:DWORD,:DWORD
WpPostA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WpPost equ <WpPostA>

WpPostW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WpBindToSiteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WpBindToSite equ <_WpBindToSiteA>


ELSE
echo -----------------------------------------
echo WARNING Duplicate include file webpost.inc
echo -----------------------------------------
ENDIF
