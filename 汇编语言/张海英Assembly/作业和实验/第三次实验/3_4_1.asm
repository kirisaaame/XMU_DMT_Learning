;Ĭ�ϲ���ML6.11������
DATAS SEGMENT
    a dw 0ffffh
    b dw 0101h
    e dw 0102h
    d dw 0103h
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;�˴��������δ���
    mov ax,word ptr b
    mov bx,word ptr e
    add ax,bx
    adc dx,0
    mov bx,word ptr d
    mul bx
    mov cx,dx
    mov bx,ax
    mov ax,word ptr a
    cwd
    sub ax,bx
    sbb dx,cx
    mov word ptr ds:[0100h],ax
    mov word ptr ds:[0102h],dx
    ;��һ����ʽ�������
   	mov ax,d
   	cwd 
   	sub ax,e
   	mov bx,ax
   	;bx<-d-c
   	mov ax,b
    cwd
    div bx
    mov bx,ax
    ;bx<-b/(d-c)
    mov ax,b
    cwd
    add ax,e
    adc dx,0
    sub ax,bx
    sbb dx,0
    mov word ptr ds:[0104h],ax
    mov word ptr ds:[0106h],dx
    
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START