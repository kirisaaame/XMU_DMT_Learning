section .data
    numbers db 31H, 21H, 42H, 52H, 87H, 23H, 98H, 01H
    length equ $ - numbers

section .bss
    up resb 1
    equa resb 1
    down resb 1

section .text
    global _start

_start:
    mov ecx, length
    mov esi, numbers
    xor al, al
    xor bl, bl
    xor cl, cl

check_loop:
    cmp byte [esi], 42H
    ja greater
    je equal
    jb smaller

greater:
    inc al
    jmp next

equal:
    inc bl
    jmp next

smaller:
    inc cl
    jmp next

next:
    inc esi
    loop check_loop

    mov [up], al
    mov [equa], bl
    mov [down], cl

    ; 在这里可以添加打印结果的代码

    ; 退出程序
    mov eax, 1
    xor ebx, ebx
    int 0x80
