;********************************************
;  *程序功能:显示Hello World!                    *
;  *编译器：Masm 5.0,ML6.11都可以          *
;  ********************************************
DATAS  SEGMENT
     STRING  DB  'Hello World!',13,10,'$'
DATAS  ENDS

CODES  SEGMENT
     ASSUME    CS:CODES,DS:DATAS
     
START:
     MOV  AX,DATAS
     MOV  DS,AX
     LEA  DX,STRING
     MOV  AH,9
     INT  21H
   
     MOV  AH,4CH
     INT  21H
CODES  ENDS
    END   START
