;Ĭ�ϲ���ML6.11������
DATAS SEGMENT
    DATA1  Db 7,5,3,2,6,9,1,8,4,0dh,0ah,'$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
     mov cx,lengthof DATA1
.repeat
	mov si,0
	mov bx,cx
	dec bx
	.repeat
		mov al,DATA1[si+1]
		.if al>DATA1[si]
			xchg DATA1[si],al	;DATA1[si+1]->DATA1[si]
			mov DATA1[si+1],al	;DATA1[si]->DATA1[si+1]
		.endif
		inc si
	.until si>=bx
.untilcxz
	mov cx,lengthof DATA1
	mov si,0
.repeat
	mov dl,DATA1[si]
	add dl,30h
	mov ah,2
	int 21h	;cout << DATA1[si]
	mov dl,32
	int 21h		;cout << ' ';
	inc si
.untilcxz
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START