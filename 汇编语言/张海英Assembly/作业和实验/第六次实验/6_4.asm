.model small
.stack
.data
	sstr db "Hello$"
	dstr db ?
.code
movestr macro strN,dstr,sstr
.repeat
movsb dstr,sstr
dec strN
.until strN==0
endm
.startup
mov cx,6
mov bx,ds
mov es,bx
mov si,offset sstr
mov di,offset dstr
movestr cx,dstr,sstr
.exit 0

end