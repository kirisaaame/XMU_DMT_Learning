;-----------------------------------------------------------------------------
;
;              Include file for VKDEBUG v1.1, September 2002.
;
;-----------------------------------------------------------------------------
;PrintString, PrintStringByAddr, PrintDec, PrintHex, PrintDouble, PrintText,
;PrintLine, Spy, StopSpy, PrintError, ASSERT, PrintException, TrapException,
;FillString, FillMem, GetSize macros are written by vkim.
;-----------------------------------------------------------------------------
;SFileName is written by vkim and based on Four-F's idea.
;-----------------------------------------------------------------------------
;DbgDump is written by Thomas.
;-----------------------------------------------------------------------------
;DumpMem, DumpFPU are written by NaN.
;-----------------------------------------------------------------------------
;CTEXT is written by huh.
;-----------------------------------------------------------------------------
;m2m is written by hutch.
;-----------------------------------------------------------------------------
;Fix is written by Four-F.
;-----------------------------------------------------------------------------
;FillStirng and FillMem are optimized by bitRAKE.
;-----------------------------------------------------------------------------
;Some bugs of PrintDec and PrintHex are fixed by NaN and Four-F.
;-----------------------------------------------------------------------------

externdef stdcall DebugPrint            :proto stdcall :dword
externdef stdcall HexDump2              :proto stdcall :dword, :dword
externdef stdcall FPUDump               :proto stdcall 
externdef C       TrapEx_seh            :proto C       :dword, :dword, :dword, :dword
externdef stdcall GetExName             :proto stdcall :dword
externdef stdcall FormatFlags           :proto stdcall :dword, :dword, :dword
externdef C       debug_except_handler  :proto C       :dword, :dword, :dword, :dword

externdef __fTrap:      dword
externdef __pVar:       dword
externdef __esp:        dword
externdef __hLib:       dword
externdef __hInst:      dword
externdef __pSymOpt:    dword
externdef __pSymInit:   dword
externdef __pGetLine:   dword
externdef __eh:         dword

DBGWIN_DEBUG_ON = 1 
DBGWIN_EXT_INFO = 1

;===================================HELPER MACROS=============================

CTEXT macro Text
    local szText
    .data
    szText byte Text, 0
    .code
    exitm <offset szText>   
endm

m2m macro M1, M2
    push M2
    pop  M1
endm

FillString macro Arr, Text
    local i,j
    i = 0
    j = 0
    forc var, <&Text>
        j = ('&var' shl ((i and 3)*8)) + j
        if (i and 3) eq 3
            mov dword ptr Arr[(i and -4)], j
            j=0
        endif
        i = i + 1
    endm

    if (i and 3) eq 0
        mov byte ptr Arr[i], 0
    elseif (i and 3) eq 1
        mov word ptr Arr[i-1], j
    elseif (i and 3) eq 2
        mov word ptr Arr[i-2], j
        mov byte ptr Arr[i], 0
    elseif (i and 3) eq 3
        mov dword ptr Arr[(i-3)], j
    endif
endm

FillMem macro pString, Text
    ifdifi <&pString>, <eax>
        push eax
        mov eax, pString
        FillString [eax], <&Text>
        pop eax
    else
        FillString [eax], <&Text>
    endif
endm

GetSize macro var: REQ
    local char
    if (OPATTR(var)) and 00010000y              ;var is register
        if @SizeStr(var) eq 3                   ;eax, ebx, ecx, edx, esi, esi, esp, esp
            exitm <4>
        elseif @SizeStr(var) eq 2
            char textequ @SubStr(var, 2, 1)
            ifidni char, <l>                    ;al, bl, cl, dl
                exitm <1>
            else
                ifidni char, <h>                ;ah, bh, ch, dh
                    exitm <1>
                else
                    exitm <2>                   ;ax, bx, cx, dx, si, di, sp, bp
                endif
            endif
        endif
    elseif (OPATTR(var)) and 00000100y 
        exitm <4>                               ;return size of dword if var is constant
    else
        exitm <sizeof &var>
    endif
endm

SFileName macro
    local i, pos
    i = 0
    pos = 0

    % forc chr, @FileCur
        i = i + 1
        if "&chr" eq 5Ch
             pos = i
        endif
    endm
    
    exitm @SubStr(%@FileCur, pos+1,)
endm

;============================================================================

PrintString macro Var: REQ
    local info
    if DBGWIN_DEBUG_ON eq 1
        pushad
        invoke lstrlen, addr Var
        if DBGWIN_EXT_INFO eq 1
            info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
            push eax
            add eax, @SizeStr(&Var)+4+@SizeStr(%info)
        else
            add eax, @SizeStr(&Var)+4
        endif
        invoke GlobalAlloc, GPTR, eax
        mov ebx, eax
        FillMem ebx, &Var
        mov dword ptr [eax+@SizeStr(&Var)], 203D20h
        invoke lstrcat, ebx, addr Var
        if DBGWIN_EXT_INFO eq 1
            pop edx
            push ebx
            add ebx, @SizeStr(&Var)+3
            add ebx, edx
            FillMem ebx, %info
            pop ebx 
        endif
        invoke DebugPrint, ebx
        invoke GlobalFree, ebx
        popad
    endif
endm

;----------------------------------------------------------------------------

PrintStringByAddr macro Var: REQ
    local info
    if DBGWIN_DEBUG_ON eq 1
        info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
        pushad
        push Var
        invoke lstrlen, Var
        push eax
        if DBGWIN_EXT_INFO eq 1
            add eax, @SizeStr(&Var)+4+@SizeStr(%info)
        else
            add eax, @SizeStr(&Var)+4
        endif
        invoke GlobalAlloc, GPTR, eax
        mov ebx, eax
        FillMem ebx, &Var
        mov dword ptr [eax+@SizeStr(&Var)], 203D20h
        pop edx
        pop eax
        invoke lstrcat, ebx, eax
        if DBGWIN_EXT_INFO eq 1
            push ebx
            add ebx, @SizeStr(&Var)+3
            add ebx, edx
            FillMem ebx, %info
            pop ebx
        endif
        invoke DebugPrint, ebx
        invoke GlobalFree, ebx
        popad
    endif
endm

;---------------------------------------------------------------------------

PrintText macro Var: REQ
    local info
    local szText
    local szBuff
    if DBGWIN_DEBUG_ON eq 1
        info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
        .data
        szText byte Var, 0
        if DBGWIN_EXT_INFO eq 1
            szBuff byte @SizeStr(%info)+@SizeStr(&Var)+1 dup(0)
        endif
        .code
        pushad
        if DBGWIN_EXT_INFO eq 1
            invoke lstrcpy, addr szBuff, addr szText ;returns address of a buffer in eax
            add eax, @SizeStr(&Var)-2
            FillMem eax, <%info>
            invoke DebugPrint, addr szBuff 
        else
            invoke DebugPrint, addr szText 
        endif
        popad
    endif
endm

;--------------------------------------------------------------------------

DumpMem macro lpData:REQ, lnLen:REQ, txt:VARARG
    if DBGWIN_DEBUG_ON eq 1                                 ; If Debug is on
        ifnb <txt>                                          ; If text is given
            PrintText txt                                   ; Print Text
        endif
        pushad
        invoke HexDump2, lpData, lnLen                      ; Call the Dump proc
        popad
   endif
endm

;--------------------------------------------------------------------------

DumpFPU macro txt:VARARG
    if DBGWIN_DEBUG_ON eq 1                                 ; If Debug is on
        ifnb <txt>                                          ; If text is given
            PrintText txt                                   ; Print Text
            PrintLine                                       ; Print Line
        endif
        pushad
        invoke FPUDump                                      ; Call the Dump proc
        popad
   endif
endm

;--------------------------------------------------------------------------

PrintDec macro Var: REQ, Text
    local szDebugNum
    local info
    local txt
    local sz
    local dwNum
    local wNum
    local bNum
    if DBGWIN_DEBUG_ON eq 1
        .data
        szDebugNum byte 20 dup(0)
        dwNum dword 0
        .code
        pushad
        sz = GetSize(Var)
        if sz eq 1
            mov al, Var
            cbw
            cwde
            mov dwNum, eax
        elseif sz eq 2
            mov ax, Var
            cwde
            mov dwNum, eax
        elseif sz eq 4
            m2m dwNum, Var
        endif
        invoke wsprintf, addr szDebugNum, CTEXT("%li"), dwNum

        invoke lstrlen, addr szDebugNum 
        if DBGWIN_EXT_INFO eq 1
            info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
            push eax
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+1
            endif
        else    
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+1
            endif
        endif
        invoke GlobalAlloc, GPTR, eax
        mov ebx, eax
        FillMem eax, &Var
        mov dword ptr [eax+@SizeStr(&Var)], 203D20h
        invoke lstrcat, eax, addr szDebugNum
        ifnb <&Text>
            invoke lstrlen, eax
            mov byte ptr [ebx+eax], ","
            mov byte ptr [ebx+eax+1], " "
            mov byte ptr [ebx+eax+2], 0
            .data
            txt byte &Text, 0
            .code
            invoke lstrcat, ebx, addr txt
        endif
        if DBGWIN_EXT_INFO eq 1
            pop edx
            push ebx
            ifnb <&Text>
                add ebx, @SizeStr(&Var)+3+@SizeStr(&Text)
            else
                add ebx, @SizeStr(&Var)+3
            endif
            add ebx, edx
            FillMem ebx, %info
            pop ebx
        endif
        invoke DebugPrint, ebx 
        invoke GlobalFree, ebx
        popad
    endif
endm

PrintDword equ <PrintDec>

;---------------------------------------------------------------------------

PrintDouble macro Var: REQ, Text
    local szDebugNum
    local info
    local txt
    if DBGWIN_DEBUG_ON eq 1
        .data
        szDebugNum byte 20 dup(0)
        .code
        pushad
        invoke FloatToStr, Var, addr szDebugNum
        invoke lstrlen, addr szDebugNum
        if DBGWIN_EXT_INFO eq 1
            info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
            push eax
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+1
            endif
        else
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+1
            endif
        endif
        invoke GlobalAlloc, GPTR, eax
        mov ebx, eax
        FillMem eax, &Var
        mov dword ptr [eax+@SizeStr(&Var)], 203D20h
        invoke lstrcat, eax, addr szDebugNum
        ifnb <&Text>
            invoke lstrlen, eax
            mov byte ptr [ebx+eax], ","
            mov byte ptr [ebx+eax+1], " "
            mov byte ptr [ebx+eax+2], 0
            .data
            txt byte &Text, 0
            .code
            invoke lstrcat, ebx, addr txt
        endif
        if DBGWIN_EXT_INFO eq 1
            pop edx
            push ebx
            ifnb <&Text>
                add ebx, @SizeStr(&Var)+3+@SizeStr(&Text)
            else
                add ebx, @SizeStr(&Var)+3
            endif
            add ebx, edx
            FillMem ebx, %info
            pop ebx
        endif
        invoke DebugPrint, ebx
        invoke GlobalFree, ebx
        popad
    endif
endm

;---------------------------------------------------------------------------

PrintLine macro
    local szLine
    if DBGWIN_DEBUG_ON eq 1
        .data
        szLine byte "----------------------------------------", 0
        .code
        pushad
        invoke DebugPrint, addr szLine 
        popad
    endif
endm

;---------------------------------------------------------------------------

PrintHex macro Var: REQ, Text
    local szDebugNum
    local info
    local txt
    local sz
    local wNum
    local bNum
    local dwNum
    if DBGWIN_DEBUG_ON eq 1
        .data
        szDebugNum byte 9 dup(0)
        wNum label word
        bNum label byte
        dwNum dword 0
        .code
        pushad
        sz = GetSize(Var)
        if sz eq 1
            if (OPATTR(Var)) and 00010000y
                mov bNum, Var
            else
                mov al, Var
                mov bNum, al
            endif
            shl dwNum, 24
        elseif sz eq 2
            m2m wNum, Var
            shl dwNum, 16
        elseif sz eq 4
            m2m dwNum, Var
        endif
        invoke dw2hex, dwNum, addr szDebugNum
        if sz eq 1
            mov byte ptr szDebugNum[2], 0
        elseif sz eq 2
            mov byte ptr szDebugNum[4], 0
        endif

        invoke lstrlen, addr szDebugNum
        if DBGWIN_EXT_INFO eq 1
            info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
            push eax
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+@SizeStr(%info)+1
            endif
        else
            ifnb <&Text>
                add eax, @SizeStr(&Var)+3+@SizeStr(&Text)+1
            else
                add eax, @SizeStr(&Var)+3+1
            endif
        endif
        invoke GlobalAlloc, GPTR, eax
        mov ebx, eax
        FillMem ebx, &Var
        mov dword ptr [eax+@SizeStr(&Var)], 203D20h
        invoke lstrcat, ebx, addr szDebugNum
        ifnb <&Text>
            invoke lstrlen, eax
            mov byte ptr [ebx+eax], ","
            mov byte ptr [ebx+eax+1], " "
            mov byte ptr [ebx+eax+2], 0
            .data
            txt byte &Text, 0
            .code
            invoke lstrcat, ebx, addr txt
        endif
        if DBGWIN_EXT_INFO eq 1
            pop edx
            push ebx
            ifnb <&Text>
                add ebx, @SizeStr(&Var)+@SizeStr(&Text)+3
            else
                add ebx, @SizeStr(&Var)+3
            endif
            add ebx, edx
            FillMem ebx, %info
            pop ebx
        endif
        invoke DebugPrint, ebx 
        invoke GlobalFree, ebx
        popad
    endif
endm

;---------------------------------------------------------------------------

PrintError macro
    local pDesc
    local info
    if DBGWIN_DEBUG_ON eq 1
        pushad
        .data
        pDesc dword 0
        .code
        invoke GetLastError
        invoke FormatMessage, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, 0, eax, 0, addr pDesc, 0, 0
        ;FormatMessage returns length of err description in eax
        if DBGWIN_EXT_INFO eq 1
            info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
            push eax 
            add eax, @SizeStr(%info)+1
            invoke GlobalAlloc, GPTR, eax
            push eax
            invoke lstrcpy, eax, pDesc
            pop eax
            pop edx
            push eax
            add eax, edx
            sub eax, 2
            FillMem eax, %info
            pop eax
            invoke DebugPrint, eax             
        else
            invoke DebugPrint, pDesc 
        endif
        invoke LocalFree, pDesc
        popad
    endif
endm

;------------------------------------------------------------------------------

PrintException macro pExcept: REQ
    local InfoText
    local info
    if DBGWIN_DEBUG_ON eq 1
        info textequ @CatStr(< !(>, SFileName(), <!, >, %@Line, <!)>)
        .data
        InfoText byte 35+@SizeStr(%info) dup(0)
        .code
        pushad
        mov eax, pExcept
        mov eax, (EXCEPTION_RECORD ptr [eax]).ExceptionCode
        invoke GetExName, eax
        invoke lstrcpy, addr InfoText, eax
        if DBGWIN_EXT_INFO eq 1
            invoke lstrlen, addr InfoText
            add eax, offset InfoText
            FillMem eax, %info
        endif
        invoke DebugPrint, addr InfoText 
        popad
    endif
endm

;-----------------------------------------------------------------------------

ASSERT macro Val: REQ, Message
    local Msg, Text, Mwq
    if DBGWIN_DEBUG_ON eq 1
        if DBGWIN_EXT_INFO eq 1
            ifnb <&Message>
                if @InStr(1, Message, <!">)                    
                    Mwq equ @SubStr(Message, 2, @SizeStr(Message)-2)
                endif
                if @InStr(1, Message, <!'>)
                    Mwq equ @SubStr(Message, 2, @SizeStr(Message)-2)
                endif
                Text equ @CatStr(<ASSERT >, Val, <, >, Mwq, < !(>, SFileName(), <!, >, %@Line, <!)>)
            else
                Text equ @CatStr(<ASSERT >, Val, < !(>, SFileName(), <!, >, %@Line, <!)>)
            endif
        else
            ifnb <&Message>
                Text equ @CatStr(<ASSERT >, Val, <, >, Mwq)
            else
                Text equ @CatStr(<ASSERT >, Val)
            endif
        endif
        .data
        Msg byte @SizeStr(%Text)+1 dup(0)
        .code
        pushad
        FillString &Msg, %Text
        .if !Val
            invoke DebugPrint, addr Msg 
        .endif
        popad
    endif
endm

assert equ <ASSERT>

;----------------------------------------------------------------------------

Spy macro Var: REQ
    if DBGWIN_DEBUG_ON eq 1
        .if __fTrap == 0 
            push eax
            assume fs: nothing
            mov __pVar, offset Var
            push offset debug_except_handler
            push fs:[0]
            mov fs:[0], esp
            mov __fTrap, 1
            pushf
            pop ax
            or ax, 100h
            push ax
            popf
            nop
        .endif
    endif
endm
    
StopSpy macro
    if DBGWIN_DEBUG_ON eq 1
        mov __fTrap, 0 
        mov eax, [esp] ;restore previous SEH
        mov fs:[0], eax
        add esp, 8
        pop eax ;restore eax
    endif
endm    

;---------------------------------------------------------------------------

TrapException macro eh: REQ
    if DBGWIN_DEBUG_ON eq 1
        pushad
        invoke LoadLibrary, CTEXT("dbghelp.dll")
        mov __hLib, eax
        invoke GetCurrentProcess
        mov __hInst, eax
        invoke GetProcAddress, __hLib, CTEXT("SymInitialize")
        mov __pSymInit, eax
        invoke GetProcAddress, __hLib, CTEXT("SymSetOptions")
        mov __pSymOpt, eax
        invoke GetProcAddress, __hLib, CTEXT("SymGetLineFromAddr")
        mov __pGetLine, eax
        .if __hLib
            push SYMOPT_LOAD_LINES
            call __pSymOpt
            push TRUE
            push NULL
            push __hInst
            call __pSymInit
            popad
            mov __esp, esp
            assume fs: nothing
            push offset TrapEx_seh
            push fs:[0]
            push esp
            pop fs:[0]
            push eh
            pop __eh
            pushf
            pop ax
            or ax, 100h ;set TF
            push ax
            popf
        .else
            popad
            PrintText "Can't load dbghelp.dll. Please copy it to the system directory."
        .endif
    endif
endm

;---------------------------------------------------------------------------

Fix macro txt:=<Fix this later!!!!>
    local pos, spos

    pos = 0
    spos = 0

    % forc chr, @FileCur            ;; Don't display full path. Easier to read.
        pos = pos + 1
        if "&chr" eq 5Ch            ;; "\"
            spos = pos
        endif
    endm

    % echo @CatStr(<Fix: >, @SubStr(%@FileCur, spos+1,), <(%@Line) - txt>)

endm

;---------------------------------------------------------------------------

DbgDump macro lpStart: REQ, lnData: REQ
local @pmem
    if DBGWIN_DEBUG_ON eq 1
        .data?
        @pmem dd ?
        .code
    
        pushad
        push lpStart
        push lnData
        invoke GlobalAlloc, GMEM_FIXED, 80
        mov @pmem, eax
    
        pop ebx ;lnData
        pop esi ;lpStart
        
        .while ebx
            mov edi, @pmem
            invoke dw2hex, esi, edi
            mov word ptr [edi+8],  " :"
            mov byte ptr [edi+10], " "
            add edi, 11
            
            push esi
            push ebx
            ; dump hex values:
            xor ecx, ecx
            .while ecx < 16
                .if !ebx
                    mov dword ptr [edi], "    "
                    add edi, 3             
                .else
                    dec ebx
                    xor eax, eax
                    
                    mov al, [esi]
                    inc esi
    
                    ror ax, 4
                    shr ah, 4
                    add ax, 3030h
                    cmp ah, 39h
                    jbe @F
                    add ah, "A"-3Ah
                    @@:
                    cmp al, 39h
                    jbe @F
                    add al, "A"-3Ah
                    @@:
                    mov word ptr [edi], ax
                    mov byte ptr [edi+2], " "
                    add edi, 3
                .endif
                inc ecx
            .endw
            pop ebx
            pop esi
            mov word ptr [edi], "  "
            add edi, 2
            
            ; dump text output:
            xor ecx, ecx
            .while ecx < 16
                mov al, [esi]
                .if !ebx
                    mov al, "."
                .else
                    dec ebx
                    inc esi
                    cmp al, 20h
                    jae @F
                    mov al, "."
                    @@:
                .endif
                mov [edi], al
                inc edi
                inc ecx
            .endw
            mov byte ptr [edi],0
            mov edi, @pmem
            
            ; write dashes:
            mov byte ptr [edi+22], "-"
            mov byte ptr [edi+34], "-"
            mov byte ptr [edi+46], "-"
            
            invoke DebugPrint, edi
            
        .endw   
        invoke  GlobalFree, @pmem
        
        popad
    endif
endm
