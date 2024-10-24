.model small
.stack
.data
	n=2
	rept 100
		dd n
		n=n+2
		n=n<<8
	endm
.code
.startup
	mov ax,bx
.exit 0
end
