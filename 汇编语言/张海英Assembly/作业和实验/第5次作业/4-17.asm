.model small
.data
    target dw 12345       ; 16λ�޷��Ŷ���������ʾ��ֵΪ12345
    array db 5 dup(?)     ; ���ڴ洢BCD������飬��ʼ��Ϊ��

.code
    org 100h
.startup
    ; ��ʼ������
    mov cx, 5
    mov di, 0
    mov al, 0
init_array:
    mov [array + di], al
    inc di
    loop init_array

    ; ��16λ�޷��Ŷ�������ת��ΪBCD��
    mov ax, target
    mov cx, 5
    mov di, 4

convert_loop:
    ; �����������ĵ�4λת��ΪBCD��
    mov dx, 0
    mov bx, 10
    div bx
    add dl, '0'
    mov [array + di], dl

    ; ��������������4λ
    mov cl,4
    shr ax,cl

    dec di
    loop convert_loop

    ; ���BCD������
    mov ah, 9
    lea dx, array
    int 21h

    ; �˳�����
.exit 0
end 
