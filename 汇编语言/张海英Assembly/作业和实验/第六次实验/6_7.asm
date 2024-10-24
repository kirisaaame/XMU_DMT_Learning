Change      macro  buffer
            lea bx,buffer
again:      mov al,[bx]
            cmp al,'$'	;若到达字符串结尾，退出
            je done
            cmp al,'A'	;判断是否大于A
            jae next1
            jmp done1
next1:      cmp al,'Z'	;判断是否小于Z
            ja  done1
            add al,20h	;满足，大写转小写
            mov byte ptr [bx],al
done1:      inc bx	;进入下一个字符
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
