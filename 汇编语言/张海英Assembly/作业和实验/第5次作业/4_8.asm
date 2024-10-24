;比较bufx,bufY和bufZ的大小
.MODEL SMALL
.DATA
     bufx dw 12
     bufy dw 12
     bufz dw 11
     endstr db 13,10,'$'
.STACK
.CODE
.STARTUP
	mov dl,0
	 mov ax,bufy
     cmp bufx,ax
     jnz secmp	;不相等，进行下一次比较
     inc dl	;相等，dl递增
   secmp:
   	 mov ax,bufz
   	 cmp bufy,ax
   	 jnz judge	;不相等，判断dl是否为1
   	 inc dl	;相等,dl递增
   	 cmp dl,2 ;判断是否三个数相等
   	 jz output
   	 judge:cmp dl,1
   	 jz output	;dl=1,说明只有两个数相等，直接输出
   	 mov ax,bufx
   	 cmp ax,bufz
   	 jnz output		;不相等，直接输出
   	 inc dl		;相等，dl递增
   	 ;输出
   	 output:add dl,30h
   	 mov ah,2
   	 int 21h
   	 lea dx,offset endstr
   	 mov ah,9
   	 int 21h
   	 
.EXIT
     END
