;Ĭ�ϲ���ML6.11������
DATAS SEGMENT
    a DB 00,06
    b DB 09,01
    e DB 08,01
    d DB 03,01
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
	;˼·������ʽ��˼·������Ϊ��������2λ�����ԱȽϼ򵥣��洢��DX.AX�Ĵ�����
	MOV AL,B
	ADD AL,E
	AAA
	PUSH FLAGS
	MUL AL,D
	AAA
	MOV BX,AX ;BX<-21 = 7*3 
   	MOV DX,OFFSET D   
   	MOV AH,4CH
   	INT 21H
CODES ENDS
    END START