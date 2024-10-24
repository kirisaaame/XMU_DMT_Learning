.model small
.data
	bytex db 6
.code
myMacro MACRO byteX
    ifE BYTEX
    	rept 10
    	add ax,ax
    	endm
    endif
ENDM
.startup
mov bx,6
mymacro BYTEX





.exit 0
end
