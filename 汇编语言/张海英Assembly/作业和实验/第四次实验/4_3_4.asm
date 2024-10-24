;每个数组元素-1
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
    mov cx,100	;设置循环次数
    lp:
    dec array[si]	;元素-1
    inc si	;切换到下一个元素
    loop lp
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START