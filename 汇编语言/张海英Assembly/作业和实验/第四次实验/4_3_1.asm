;
.model small
.data
	string db 'debugging$'
.stack
.code
.startup
lea bx,string
mov dx,[bx]
mov ah,2
int 21h
mov dl,10
mov ah,2
int 21h
mov dx,[bx+5]
mov ah,2
int 21h
mov dl,10
mov ah,2
int 21h
.exit 
end
		