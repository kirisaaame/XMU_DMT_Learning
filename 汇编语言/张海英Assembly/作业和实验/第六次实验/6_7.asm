Change      macro  buffer
            lea bx,buffer
again:      mov al,[bx]
            cmp al,'$'	;�������ַ�����β���˳�
            je done
            cmp al,'A'	;�ж��Ƿ����A
            jae next1
            jmp done1
next1:      cmp al,'Z'	;�ж��Ƿ�С��Z
            ja  done1
            add al,20h	;���㣬��дתСд
            mov byte ptr [bx],al
done1:      inc bx	;������һ���ַ�
            jmp again
done:
            endm
            
 
stack     segment
	db 1024 dup(?)
stack     ends
 
data      segment
	string db 'Hello, Everybody!$'
data      ends
 
code      segment
	assume cs:code,ss:stack,ds:data
	
start:
          mov ax,data
          mov ds,ax
          Change string
          mov ah,09h
          mov dx,offset string
          int 21h
          mov ah,4ch
          int 21h
          
code      ends
end       start
