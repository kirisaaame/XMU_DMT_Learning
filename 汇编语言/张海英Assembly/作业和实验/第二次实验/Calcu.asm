;默认采用ML6.11汇编程序
DATAS SEGMENT
    ;此处输入数据段代码  
    X DB 4
    Y DB 5
    Z DB ?
    Z1 DB ?
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
    DW 256 DUP(?)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;此处输入代码段代码
    MOV AL,X
    ADD AL,Y
    MOV BL,8H
    IMUL BL
    MOV BL,X
    MOV BH,0H
    SUB AX,BX
    MOV BL,2
    IDIV BL
    MOV Z,AL
    MOV Z1,AH
    
    MOV AL,Z
    MOV AH,0
    MOV BL,10
    DIV BL
    MOV DX,AX
    ADD DX,3030H
    MOV AH,2
    INT 21H
   
    
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START