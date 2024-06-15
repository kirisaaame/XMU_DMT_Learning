.model small
.stack 100h

.data
    arr dw 10H, 11H, 12H, 13H, 14H, 15H, 16H, 17H
    sum dw ?

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov cx, 8 
        xor dx, dx 

        mov si, 0  
        add_loop:
            add dx, [arr + si]  
            inc si  
            loop add_loop 

        mov sum, dx 

        mov ax, 4C00h  
        int 21h
    main endp
end main
