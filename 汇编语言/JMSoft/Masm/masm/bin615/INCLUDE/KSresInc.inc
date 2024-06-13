; #########################################################################

	; ---------------------------------------------------------------
	; KSresInc Ver 1.01
	; 
	; KSresInc.Inc - Global Include File
	;
	; Copyright © Kirsoft Inc., 2003
	; Written by Kirill Scherba
	; ---------------------------------------------------------------

; #########################################################################

;----------------------------------------------------------------
; Prototype
;----------------------------------------------------------------

;KS_resize			PROTO hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM,\
;						  swRec:PTR RECT,\
;						  KSresizerRszN:PTR BYTE,resStrategy:DWORD,\
;						  szINIFName:PTR BYTE
KS_resize			PROTO hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM,\
						  lpKSres:PTR KSres,\
						  szINIFName:PTR BYTE

KS_tab				PROTO hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM,\
						  lpKStab:PTR KStabCntS,\
						  szINIFName:PTR BYTE

;----------------------------------------------------------------
; Structures
;----------------------------------------------------------------

; KSresizer


; KSresizer Header
KSres	struct
	lpSwRec  	dd  ? 		; swRec:PTR RECT
	lpRszN		dd	?		; KSresizerRszN:PTR BYTE
	lpresStra	dd  ?		; resStrategy:DWORD
KSres	ends

; .rsz file Header
RszHead	struct
	numRec			dd	?	; Number of Records
	WindowWidth		dd	?	; Limit Window Width
	WindowHeight	dd  ?	; Limit Window Height
	SaveRestore		db  ?   ; Save and Restore (TRUE/FALSE)
RszHead ends

; .rsz file Record
RszRec	struct
	id				dd	?	; Control ID
	x				db	?	; X: Horizontal Position Strategies* 
	y				db  ?	; Y: Vertical Position Strategies*
	w 				db	?	; Width: Horizontal Resize Strategies**	
	h				db 	?	; Height: Vertical Resize Strategies**
RszRec	ends

; *  X/Y: 		   0 - Lock, 1 - Fix Rigt/Bottom
; ** Width/Height: 0 - Lock, 1 - Constant Rigt/Bottom Border

;----------------------------------------------------------------

; KStab

; KStab Tab Control Header
KStabCntS	struct
	control		dd ?	; Identifier Of Tab Control
	lpWinN		dd ?	; Window Name (for Save/Restore from INI)
	lpCntN  	dd ?    ; Tab Control Name (for Save/Restore from INI)
	SaveRestore db ?	; Save/Restore from INI
	hTab		dd ?	; Handle of Tab Control
	numTab		db ?	; Number of Tabs
	lpCnts		dd ?	; (PTR BYTE) Number of Controls in this Tab Control (and Controls)
	lpNext		dd ?	; (PTR KStabCntS)Offset of Next Tab Control in this Dialog
KStabCntS ends

;----------------------------------------------------------------

; #########################################################################

