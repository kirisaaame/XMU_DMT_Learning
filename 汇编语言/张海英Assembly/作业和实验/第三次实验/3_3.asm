;默认采用ML6.11汇编程序
DATAS SEGMENT
    x dw 0101h
    y dw 0102h
    z dw 0103h
    v dw 0104h  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
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
    
    ;此处输入代码段代码
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START