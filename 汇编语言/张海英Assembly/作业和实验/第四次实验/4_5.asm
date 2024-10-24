;双指针算法汇编实现
;如果可以输出两个数，不可以输出空
.MODEL SMALL
.DATA
    array db 02h,07h,0bh,0fh,13h,1ch,24h,39h,40h,57h,68h
    target db 37h
.STACK
.CODE
.STARTUP
   lea bp,array		;bp左指针
   lea bx,array+sizeof array-1	;bx右指针
 try:mov al,[bp]
 	add al,[bx]
 	cmp al,target	;比较bp+bx和target
 	jb bpp		;若小于，则bp++
 	jz quit		;若等于，则输出
 	dec bx
 	cmp bx,bp
 	jb ending		;大于target时，bx--，当bx小于bp，说明找不到
 	jmp try		;继续比较
bpp:inc bp
	cmp bp,bx
	jnbe ending	;当bp大于bx,说明找不到，直接退出
 	jmp try		;继续比较
quit:
	mov dl,[bp]
	mov cl,4
	shr dl,cl
	add dl,30h
	mov ah,2
	int 21h
	mov dl,[bp]
	and dl,0fh
	add dl,30h
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
	mov dl,[bx]
	shr dl,cl
	add dl,30h
	mov ah,2
	int 21h
	mov dl,[bx]
	and dl,0fh
	add dl,30h
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
ending:
	mov ah,4ch
	int 21h
.EXIT
     END
