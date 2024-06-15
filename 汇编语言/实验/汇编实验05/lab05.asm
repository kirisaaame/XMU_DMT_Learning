DATA  SEGMENT
    UPSTRING  DB        0AH,0DH,'$'
DATA  ENDS

CODE  SEGMENT
    ASSUME    CS:CODE,DS:DATA

START:
    mov ax, DATA
    mov ds, ax

    mov cx, 15  
    mov dx, 16  

    mov bl, 10H  

LINELOOP:
    mov si, 16  

CHANGELINE:
    mov ah, 2  
    mov dl, bl  
    int 21H

    mov ah, 2  
    mov dl, ' '  
    int 21H

    inc bl  

    dec si  
    jnz CHANGELINE  

    mov ah, 2  
    mov dl, 0AH  
    int 21H

    dec cx  
    jnz LINELOOP  

ENDPRO:
    mov ax, 4C00H
    int 21H

CODE  ENDS
END       START


