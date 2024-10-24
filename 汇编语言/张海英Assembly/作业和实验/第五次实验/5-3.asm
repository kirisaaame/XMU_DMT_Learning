.model small
.data
.code
.startup
main:mov ax,3	;设n=3
	 call fact
xi:	 mov bx,dx
.exit 0
;阶乘子程序
;入口参数：AL中存放n
;出口参数：DX中存放n!
;所用寄存器： CX

fact proc
	cmp al,0
	jnz iia		;AL!=0,iia
	mov dl,1	;AL==0,DL=1
	ret		;(1)
iia:push ax		
dec al		;
	call fact
x2:pop cx
	call mult
x3: mov dx,ax
	ret		;
fact endp
;无符号字节数乘法子程序
;入口参数：CL、DL中各为一乘数
;出口参数：AX中为乘积

mult proc
	mov al,dl
	mul cl
	ret	;(3)
mult endp
	end