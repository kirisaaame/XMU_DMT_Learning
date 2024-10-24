.model small
.data
    rows equ 25       ; 总行数
    cols equ 80       ; 总列数
    screen_size equ rows * cols ; 屏幕大小

.data
    buffer db screen_size dup(?) ; 用于存储屏幕内容的缓冲区

.code
    org 100h          ; 程序的起始地址

_start:
    mov ax, @data     ; 初始化数据段地址
    mov ds, ax
    mov es, ax        ; 将ES寄存器设置为数据段地址

    ; 读取光标位置
    mov ah, 2
    int 10h

    mov cx, screen_size  ; CX为屏幕大小

    ; 逐行向上滚动
    mov si, 2 * cols     ; SI指向第二行
    mov di, 0           ; DI指向第一行

scroll_up_loop:
    ; 逐个字符复制
    mov al, [si]
    mov [di], al
    inc si
    inc di

    loop scroll_up_loop  ; 循环

    ; 在最后一行填充字母'A'
    mov si, (rows - 1) * cols * 2 ; SI指向最后一行
    mov cx, cols
    mov al, 'A'

fill_last_row:
    mov [si], al
    inc si
    loop fill_last_row

    ; 设置光标位置至新的一行
    mov ah, 2
    mov dl, 0
    mov dh, rows - 1
    int 10h

    ; 退出程序
    mov ah, 4Ch
    int 21h
end _start
