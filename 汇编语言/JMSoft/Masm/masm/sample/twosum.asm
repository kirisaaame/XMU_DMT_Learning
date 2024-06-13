DATAS  SEGMENT
    FIVE  DB    5
DATAS  ENDS
;********************************************
;  *程序功能:计算3+5的和                           *
;  *编译器：Masm 5.0,ML6.11都可以          *
;  ********************************************
STACKS  SEGMENT
      DB  128 DUP (?)
STACKS  ENDS

CODES  SEGMENT
     ASSUME    CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    MOV AL,FIVE
    ADD AL,3
    ADD AL,30H
    MOV DL,AL
    MOV AH,2
    INT 21H
    
    MOV AH,4CH
    INT 21H
CODES  ENDS
    END  START
