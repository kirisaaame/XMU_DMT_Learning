.MODEL SMALL
.DATA
    NUM DW 5              ; ���峣��NUM��ֵΪ5
    DATALIST DW -1, 0, 2, 5, 4, ?  ; ����������DATALIST������ǰ5���ֵ�Ԫ��һ��δ��ʼ�����ֵ�Ԫ
.STACK
.CODE
.STARTUP
    MOV CX, NUM          ; ������NUM���ص�CX�Ĵ���
    LEA SI, DATALIST     ; ��DATALIST����ʼ��ַ���ص�SI�Ĵ���
    XOR AX, AX           ; �����ۼӺ� AX �Ĵ���

SUM_LOOP:
    ADD AX, [SI]         ; ��DATALIST�е�ǰԪ�ص�ֵ�ӵ��ۼӺ���
    ADD SI, 2            ; �ƶ�����һ���ֵ�Ԫ
    LOOP SUM_LOOP        ; ѭ��NUM��

    MOV [SI], AX         ; ���ۼӺʹ���DATALIST�����һ���ֵ�Ԫ
.EXIT
END
