;********************************************
;  *程序功能:调用宏库显示Hello World!                  *
;  *编译器：Masm 5.0,ML6.11都可以        *
;  *******************************************
INCLUDE MACROOUT.LIB
DATAS SEGMENT
    STRING  DB 'Hello World',13,10,'$'
DATAS ENDS
CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    OUTPUT STRING
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START

