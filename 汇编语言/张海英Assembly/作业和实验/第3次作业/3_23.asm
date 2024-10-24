DATAS SEGMENT
    a dd 12345678h
    b dd 87654321h  	;定义2个32位数，可以更改（不溢出前提下）
    sum dd ?
DATAS ENDS

STACKS SEGMENT
   
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    mov ax,word ptr a
    mov si,offset a
    add si,2
    mov dx,word ptr[si]
    mov bx,word ptr b
    mov si,offset b
    add si,2
    mov cx,word ptr[si]
    add ax,bx
    adc dx,cx
    mov word ptr sum,ax
    mov si,offset sum
    add si,2
    mov word ptr [si],dx
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START