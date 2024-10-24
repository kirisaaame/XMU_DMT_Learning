
DATAS SEGMENT
   array db 12h,45h,0f3h,6ah,20h,0feh,90h,0c8h,57h,34h
   sum db ?
DATAS ENDS

STACKS SEGMENT
    
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    xor ax,ax
    mov bx,offset array
    xor si,si
    mov cx,10
    ;¿ªÊ¼Ñ­»·
  l:add al,byte ptr[bx+si]
  	inc si
  	loop l
    
    mov bx,offset sum
    mov [bx],al
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START