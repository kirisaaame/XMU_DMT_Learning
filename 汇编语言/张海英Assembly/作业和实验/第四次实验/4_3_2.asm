.model small
.data
	buffer dw 0009h,0008h,0007h,0006h
.stack
.code
.startup
mov ax,buffer
mov cl,12
shl ax,cl
mov si,2
mov dx,buffer[si]
mov cl,8
shl dx,cl
or ax,dx
add si,2
mov dx,buffer[si]
mov cl,4
shl dx,cl
or ax,dx
add si,2
mov dx,buffer[si]
or ax,dx
mov dx,ax
.exit
end