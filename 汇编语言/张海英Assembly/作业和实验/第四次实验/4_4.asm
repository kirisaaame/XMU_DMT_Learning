;
.MODEL SMALL
.DATA
    PACKED dw 0123h,1234h,2345h,6789h,7890h
    unpacked dw 10 dup(?)
.STACK
.CODE
.STARTUP
     mov dx,10	;设置循环次数
     mov cl,4	;循环移位位数为4
     mov si,0
     mov di,0	;起始偏移量为0
     convert:mov al,byte ptr[si+packed]
     mov ah,al
     and al,0fh		
     shr ah,cl	;高四位要移到低四位
     mov [di+unpacked],ax	;整个字传送
     add di,2	;对应非压缩要移动2字节
     mov ax,0
     inc si	
     dec dx	;压缩移动1字节
     jnz convert
     
.EXIT
     END
