;使用变量传参
;打印下标
.MODEL SMALL
.DATA
     STRING  DB '$'
     tar db 'WE'
     ascii db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h
     		db 41h,42h,43h,44h,45h,46h
     msg db 'NOT FOUND',13,10,'$'
.STACK
.CODE
.STARTUP
	push ax
	push si
	push dx
	push cx
	xor ax,ax	;清空AX
	xor si,si
	xor dx,dx
    mov bx,offset string
    call findtar
    pop cx
    pop dx
    pop si
    pop ax
.EXIT

findtar proc
	mov cx,lengthof string	;设置循环次数
	mov si,0	;设置目标串偏移
	;暴力搜索
try:mov al,byte ptr[bx+si]
	cmp al,tar[si]
	jne clr
	inc si	;若相等，递增si
	cmp si,2
	je break
	jmp try	;继续比较下一个字符
clr:xor si,si	;不相等，SI置0
	inc bx	;
	loop try	;下标递增，循环
	;循环完了未找到子串
	mov ax,offset string-1	;AX=-1
	jmp finally
break:mov ax,bx
finally:
    sub ax,offset string
    cmp ax,-1
    jne print
    mov dx,offset msg
    mov ah,9
    int 21h
    jmp endl
print:mov bx,offset ascii
    
    mov dl,al
    mov cl,4
    shr dl,cl
    mov si,dx
    mov dl,byte ptr[bx+si]
    push ax
    mov ah,2
    int 21h
    pop ax
    mov dl,al
    and dl,0fh
    mov si,dx
    mov dl,[bx+si]
    mov ah,2
    int 21h
endl:ret
findtar endp
END
