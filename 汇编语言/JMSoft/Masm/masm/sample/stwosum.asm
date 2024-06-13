;********************************************
;  *程序功能:简化段的求3+5的和                 *
;  *编译器：ML6.11                                   *
;  ********************************************
;简化段的求3+5的和
.MODEL SMALL
.DATA
    FIVE  DB    5

.STACK
      DB  128 DUP (?)
.CODE

.STARTUP
    MOV AL,FIVE
    ADD AL,3
    ADD AL,30H
    MOV DL,AL
    MOV AH,2
    INT 21H
    
.EXIT 0
    END 

