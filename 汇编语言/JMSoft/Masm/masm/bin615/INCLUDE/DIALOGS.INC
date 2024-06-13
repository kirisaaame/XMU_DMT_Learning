; ¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤
;
;                  Macros for in memory dialog templates
;
; ¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤=÷=¤

    ; ----------------------------------------
    ; 2 macros for aligning a 32 bit register
    ; ----------------------------------------
      align_4 MACRO reg
        add reg, 3
        shr reg, 2
        shl reg, 2
      ENDM

      align_2 MACRO reg
        add reg, 1
        shr reg, 1
        shl reg, 1
      ENDM

    ; ------------------------------------------------
    ; write unicode string at current location in EDI
    ; ------------------------------------------------
      ustring MACRO quoted_text
        LOCAL asc_txt
      .data
        asc_txt db quoted_text,0
      .code
        invoke MultiByteToWideChar,CP_ACP,MB_PRECOMPOSED,
               ADDR asc_txt,-1,edi,LENGTHOF asc_txt
        add edi, LENGTHOF asc_txt*2
      ENDM

    ; --------------
    ; dialog window
    ; --------------
      Dialog MACRO quoted_text_title,quoted_font,fsize,dstyle,ctlcnt,tx,ty,wd,ht,bsize
        push esi
        push edi
        invoke GlobalAlloc,GMEM_FIXED or GMEM_ZEROINIT,bsize
        mov esi, eax
        mov edi, esi
        mov DWORD PTR [edi+0],  DS_SETFONT or dstyle
        mov WORD  PTR [edi+8],  ctlcnt
        mov WORD  PTR [edi+10], tx
        mov WORD  PTR [edi+12], ty
        mov WORD  PTR [edi+14], wd
        mov WORD  PTR [edi+16], ht
        add edi, 22
        ustring quoted_text_title
        mov WORD PTR [edi], fsize
        add edi, 2
        ustring quoted_font
      ENDM

    ; DLGITEMTEMPLATE

    ; ------------
    ; push button
    ; ------------
      DlgButton MACRO quoted_caption,dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0080h   ;; button
        add edi, 22
        ustring quoted_caption
        align_2 edi
        add edi, 2
      ENDM

    ; -------------
    ; radio button
    ; -------------
      DlgRadio MACRO quoted_caption,dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or BS_AUTORADIOBUTTON or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0080h   ;; button
        add edi, 22
        ustring quoted_caption
        align_2 edi
        add edi, 2
      ENDM

    ; ----------
    ; check box
    ; ----------
      DlgCheck MACRO quoted_caption,dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or BS_AUTOCHECKBOX or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0080h   ;; button
        add edi, 22
        ustring quoted_caption
        align_2 edi
        add edi, 2
      ENDM

    ; ----------
    ; group box
    ; ----------
      DlgGroup MACRO quoted_caption,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or BS_GROUPBOX or WS_TABSTOP
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0080h   ;; button
        add edi, 22
        ustring quoted_caption
        align_2 edi
        add edi, 2
      ENDM

    ; ---------------
    ; static control
    ; ---------------
      DlgStatic MACRO quoted_caption,dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0082h   ;; static
        add edi, 22
        ustring quoted_caption
        align_2 edi
        add edi, 2
      ENDM

    ; ---------------
    ; icon control
    ; ---------------
      DlgIcon MACRO IconID,tx,ty,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or SS_ICON
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0082h   ;; static
        mov WORD  PTR [edi+22], 0FFFFh  ;; title array
        mov WORD  PTR [edi+24], IconID
        add edi, 26
      ENDM

    ; ---------------
    ; bitmap control
    ; ---------------
      DlgBitmap MACRO BmpID,tx,ty,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or SS_BITMAP
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh  ;; class array
        mov WORD  PTR [edi+20], 0082h   ;; static
        mov WORD  PTR [edi+22], 0FFFFh  ;; title array
        mov WORD  PTR [edi+24], BmpID
        add edi, 26
      ENDM


    ; -------------
    ; edit control
    ; -------------
      DlgEdit MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh
        mov WORD  PTR [edi+20], 0081h   ;; edit control
        add edi, 26
      ENDM

    ; ---------
    ; list box
    ; ---------
      DlgList MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh
        mov WORD  PTR [edi+20], 0083h   ;; edit control
        add edi, 26
      ENDM

    ; ----------
    ; combo box
    ; ----------
      DlgCombo MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh
        mov WORD  PTR [edi+20], 0085h   ;; edit control
        add edi, 26
      ENDM

    ; -----------
    ; scroll bar
    ; -----------
      DlgScroll MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        mov WORD  PTR [edi+18], 0FFFFh
        mov WORD  PTR [edi+20], 0084h   ;; edit control
        add edi, 26
      ENDM

        ; "SysHeader32"             ok
        ; "ToolbarWindow32"         ok
        ; "msctls_statusbar32"      ok
        ; "msctls_trackbar32"       ok
        ; "msctls_updown32"         ok
        ; "msctls_progress32"       ok
        ; "SysListView32"           ok
        ; "SysTreeView32"           ok
        ; "SysTabControl32"         ok
        ; "SysAnimate32"            ok
        ; "RichEdit"                ok
        ; "RichEdit20a"             ok
        ; "SysMonthCal32"           ok
        ; "SysDateTimePick32"       ok
        ; "SysIPAddress32"          ok
        ; "msctls_hotkey32"         ok
        ; "ReBarWindow32"           ok
        ; "SysPager"                ok

        ; "NativeFontCtl"
        ; "commctrl_DragListMsg"
        ; "ComboBoxEx32"
        ; "tooltips_class32"

    ; ---------------------------------------------
    ; controls below from the common control
    ; library require the API "InitCommonControls"
    ; to initialise the common control library.
    ; Later common controls require the API
    ; "InitCommonControlsEx".
    ; ---------------------------------------------
    ; These are the styles that activate the common control library
    ; for each type of control listed that must be placed in the "dwICC"
    ; member of the "INITCOMMONCONTROLSEX" structure used by the API
    ; function "InitCommonControlsEx".
    ; ---------------------------------------------

    ;   ICC_ANIMATE_CLASS       Load animate control class.  
    ;   ICC_BAR_CLASSES         Load toolbar, status bar,
    ;                           trackbar, and tooltip control classes.  
    ;   ICC_COOL_CLASSES        Load rebar control class.  
    ;   ICC_DATE_CLASSES        Load date and time picker control class.  
    ;   ICC_HOTKEY_CLASS        Load hot key control class.  
    ;   ICC_INTERNET_CLASSES    Load IP address class.  
    ;   ICC_LISTVIEW_CLASSES    Load list view and header control classes.  
    ;   ICC_PAGESCROLLER_CLASS  Load pager control class.  
    ;   ICC_PROGRESS_CLASS      Load progress bar control class.  
    ;   ICC_TAB_CLASSES         Load tab and tooltip control classes.  
    ;   ICC_TREEVIEW_CLASSES    Load tree view and tooltip control classes.  
    ;   ICC_UPDOWN_CLASS        Load up-down control class.  
    ;   ICC_USEREX_CLASSES      Load ComboBoxEx class.  
    ;   ICC_WIN95_CLASSES       Load animate control, header, hot key,
    ;                           list view, progress bar, status bar, tab,
    ;                           tooltip, toolbar, trackbar, tree view,
    ;                           and up-down control classes.  

    ; -------------------------------------
    ; general purpose common control macro
    ; -------------------------------------
      DlgComCtl MACRO quoted_class,dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring quoted_class
        align_2 edi
        add edi, 4
      ENDM

    ; --------------
    ; rebar control
    ; --------------
      DlgRebar MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "ReBarWindow32"
        align_2 edi
        add edi, 4
      ENDM

    ; ---------------
    ; hotkey control
    ; ---------------
      DlgHotkey MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "msctls_hotkey32"
        align_2 edi
        add edi, 4
      ENDM


    ; -------------------
    ; IP address control
    ; -------------------
      DlgIPAddress MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysIPAddress32"
        align_2 edi
        add edi, 4
      ENDM

    ; -----------------
    ; data time picker
    ; -----------------
      DlgDateTime MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysDateTimePick32"
        align_2 edi
        add edi, 4
      ENDM

    ; ---------------
    ; month calender
    ; ---------------
      DlgMonthCal MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysMonthCal32"
        align_2 edi
        add edi, 4
      ENDM

    ; -----------
    ; status bar
    ; -----------
      DlgStatus MACRO ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "msctls_statusbar32"
        align_2 edi
        add edi, 2
      ENDM

    ; -------------
    ; progress bar
    ; -------------
      DlgProgress MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "msctls_progress32"
        align_2 edi
        add edi, 2
      ENDM

    ; ------------------
    ; list view control
    ; ------------------
      DlgListView MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysListView32"
        align_2 edi
        add edi, 2
      ENDM

      DlgTreeView MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysTreeView32"
        align_2 edi
        add edi, 2
      ENDM

    ; ------------
    ; tab control
    ; ------------
      DlgTabControl MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysTabControl32"
        align_2 edi
        add edi, 2
      ENDM

    ; ------------------
    ; animation control
    ; ------------------
      DlgAnimate MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysAnimate32"
        align_2 edi
        add edi, 2
      ENDM

    ; ---------------
    ; header control
    ; ---------------
      DlgHeader MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "SysHeader32"
        align_2 edi
        add edi, 2
      ENDM

    ; -----------------
    ; richedit control
    ; -----------------
      DlgRichEdit MACRO dstyle,tx,ty,wd,ht,ctlID
        align_4 edi
        mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle
        mov WORD  PTR [edi+8],  tx
        mov WORD  PTR [edi+10], ty
        mov WORD  PTR [edi+12], wd
        mov WORD  PTR [edi+14], ht
        mov WORD  PTR [edi+16], ctlID
        add edi, 18
        ustring "RICHEDIT"
        align_2 edi
        add edi, 2
      ENDM

    ; ------------------------------------
    ; create a modal dialog from the data
    ; written to the memory template.
    ; ------------------------------------
      CallModalDialog MACRO Instance,Parent,DlgProc,lpExtra
        invoke DialogBoxIndirectParam,Instance,esi,Parent,
                                      ADDR DlgProc,lpExtra
        push eax                ;; preserve return value
        invoke GlobalFree,esi   ;; free memory
        pop eax                 ;; restore return value
        pop edi
        pop esi
      ENDM
