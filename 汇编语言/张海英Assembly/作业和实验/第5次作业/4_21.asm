.model small
.data
    rows equ 25       ; ������
    cols equ 80       ; ������
    screen_size equ rows * cols ; ��Ļ��С

.data
    buffer db screen_size dup(?) ; ���ڴ洢��Ļ���ݵĻ�����

.code
    org 100h          ; �������ʼ��ַ

_start:
    mov ax, @data     ; ��ʼ�����ݶε�ַ
    mov ds, ax
    mov es, ax        ; ��ES�Ĵ�������Ϊ���ݶε�ַ

    ; ��ȡ���λ��
    mov ah, 2
    int 10h

    mov cx, screen_size  ; CXΪ��Ļ��С

    ; �������Ϲ���
    mov si, 2 * cols     ; SIָ��ڶ���
    mov di, 0           ; DIָ���һ��

scroll_up_loop:
    ; ����ַ�����
    mov al, [si]
    mov [di], al
    inc si
    inc di

    loop scroll_up_loop  ; ѭ��

    ; �����һ�������ĸ'A'
    mov si, (rows - 1) * cols * 2 ; SIָ�����һ��
    mov cx, cols
    mov al, 'A'

fill_last_row:
    mov [si], al
    inc si
    loop fill_last_row

    ; ���ù��λ�����µ�һ��
    mov ah, 2
    mov dl, 0
    mov dh, rows - 1
    int 10h

    ; �˳�����
    mov ah, 4Ch
    int 21h
end _start
