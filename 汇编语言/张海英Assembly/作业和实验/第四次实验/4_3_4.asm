;ÿ������Ԫ��-1
DATAS SEGMENT
    array db 100 dup(?)
DATAS ENDS

STACKS SEGMENT
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    mov si,0
    mov cx,100	;����ѭ������
    lp:
    dec array[si]	;Ԫ��-1
    inc si	;�л�����һ��Ԫ��
    loop lp
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START