;Ĭ�ϲ���ML6.11������
DATAS SEGMENT
    x dw 0101h
    y dw 0102h
    z dw 0103h
    v dw 0104h  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    MOV AX,WORD PTR x
    mov bx,word ptr y
    imul bx
    mov cx,ax
    mov bx,dx
    mov ax,word ptr z
    cwd
    add cx,ax
    add bx,dx
    sub cx,0540h
    sbb bx,0
    mov ax,word ptr v
    cwd 
    sub ax,cx
    sbb dx,bx
    mov bx,word ptr x
    idiv bx
    
    ;�˴��������δ���
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START