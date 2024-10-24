.model small
.stack
.data
	array db 2,4,6,8,10,12,14,16,18,20
	target db 21
.code
.startup

pop ax
pop bx
pop cx
pop dx
pop si
call insert
pop si
pop dx
pop cx
pop bx
pop ax
.exit 0

;使用变量传参
insert proc
	mov cx,lengthof array
	mov dl,target
	mov bx,offset array
	mov si,0
	.while si<cx
	mov al,[bx+si]
	.if al==dl 	;找到对应元素，直接打印'Y'返回
	mov dl,'Y'
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
	ret
	.endif
	.if al>dl	;元素大于target，直接插入
	.while si<=cx
	xchg dl,[bx+si]
	inc si
	.endw
	ret
	.endif
	;当前元素小于target,查看下一个元素
	inc si
	.endw
	.if si==cx	;若target大于所有数组中的数
	mov [bx+si],dl	;将target放在末尾
	ret
	.endif
insert endp
	end