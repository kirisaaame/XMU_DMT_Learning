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

;ʹ�ñ�������
insert proc
	mov cx,lengthof array
	mov dl,target
	mov bx,offset array
	mov si,0
	.while si<cx
	mov al,[bx+si]
	.if al==dl 	;�ҵ���ӦԪ�أ�ֱ�Ӵ�ӡ'Y'����
	mov dl,'Y'
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
	ret
	.endif
	.if al>dl	;Ԫ�ش���target��ֱ�Ӳ���
	.while si<=cx
	xchg dl,[bx+si]
	inc si
	.endw
	ret
	.endif
	;��ǰԪ��С��target,�鿴��һ��Ԫ��
	inc si
	.endw
	.if si==cx	;��target�������������е���
	mov [bx+si],dl	;��target����ĩβ
	ret
	.endif
insert endp
	end