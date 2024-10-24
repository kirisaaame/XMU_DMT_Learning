.model small
.stack
.data
	x db 5
.code 
.startup
mov ax,0
mov bx,1
.if x==5
.if ax!=bx
inc ax
.endif
.endif


.exit 0
end