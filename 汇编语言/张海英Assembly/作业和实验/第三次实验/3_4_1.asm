;默认采用ML6.11汇编程序
DATAS SEGMENT
    a dw 0ffffh
    b dw 0101h
    e dw 0102h
    d dw 0103h
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
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
    ;第一个算式计算完成
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