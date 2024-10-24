.model small
.data
    target dw 12345       ; 16位无符号二进制数，示例值为12345
    array db 5 dup(?)     ; 用于存储BCD码的数组，初始化为空

.code
    org 100h
.startup
    ; 初始化数组
    mov cx, 5
    mov di, 0
    mov al, 0
init_array:
    mov [array + di], al
    inc di
    loop init_array

    ; 将16位无符号二进制数转换为BCD码
    mov ax, target
    mov cx, 5
    mov di, 4

convert_loop:
    ; 将二进制数的低4位转换为BCD码
    mov dx, 0
    mov bx, 10
    div bx
    add dl, '0'
    mov [array + di], dl

    ; 将二进制数右移4位
    mov cl,4
    shr ax,cl

    dec di
    loop convert_loop

    ; 输出BCD码数组
    mov ah, 9
    lea dx, array
    int 21h

    ; 退出程序
.exit 0
end 
