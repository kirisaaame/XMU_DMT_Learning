;
.MODEL SMALL
.DATA
    PACKED dw 0123h,1234h,2345h,6789h,7890h
    unpacked dw 10 dup(?)
.STACK
.CODE
.STARTUP
     mov dx,10	;����ѭ������
     mov cl,4	;ѭ����λλ��Ϊ4
     mov si,0
     mov di,0	;��ʼƫ����Ϊ0
     convert:mov al,byte ptr[si+packed]
     mov ah,al
     and al,0fh		
     shr ah,cl	;����λҪ�Ƶ�����λ
     mov [di+unpacked],ax	;�����ִ���
     add di,2	;��Ӧ��ѹ��Ҫ�ƶ�2�ֽ�
     mov ax,0
     inc si	
     dec dx	;ѹ���ƶ�1�ֽ�
     jnz convert
     
.EXIT
     END
