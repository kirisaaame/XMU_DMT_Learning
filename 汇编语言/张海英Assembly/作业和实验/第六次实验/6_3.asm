.model small
.data
logical macro op,r1,r2
	op r1,r2
endm
.code
.startup
mov ax,1
mov bx,2
logical or,ax,bx
logical test,ax,bx
logical xor,ax,bx
logical and,ax,bx
.exit 0
end