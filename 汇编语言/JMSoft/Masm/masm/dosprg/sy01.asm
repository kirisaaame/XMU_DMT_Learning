;**********************************************
;  *程序功能:               
;用*输出直角三角形
;  *
;  **
;  ***
;  ****
;  *****
;  *编译器：Masm 5.0,ML6.11都可以          
;  ********************************************
stack1 segment stack
       db 20h dup(?)
stack1 ends
code segment
       assume cs:code,ss:stack1
start:
      mov ds,ax
      mov bx,0
lop:
      push bx
      inc bx
      mov cx,bx
lop2:
      mov dl,'*'
      mov ah,02h
      int 21h
loop lop2
      call lop3
      pop bx
      inc bx
      cmp bx, 5
      jb lop
      jmp over
lop3 proc
      mov dl,0dh
      mov ah,02h
      int 21h
      mov dl,0ah
      int 21h
     ret
lop3 endp
over:
     pop bx
     pop cx
     pop ax
     mov ah,4ch
     int 21h
code ends
    end start


