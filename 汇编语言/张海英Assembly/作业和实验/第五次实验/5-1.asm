;ʹ�ñ�������
;��ӡ�±�
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
	xor ax,ax	;���AX
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
	mov cx,lengthof string	;����ѭ������
	mov si,0	;����Ŀ�괮ƫ��
	;��������
try:mov al,byte ptr[bx+si]
	cmp al,tar[si]
	jne clr
	inc si	;����ȣ�����si
	cmp si,2
	je break
	jmp try	;�����Ƚ���һ���ַ�
clr:xor si,si	;����ȣ�SI��0
	inc bx	;
	loop try	;�±������ѭ��
	;ѭ������δ�ҵ��Ӵ�
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
