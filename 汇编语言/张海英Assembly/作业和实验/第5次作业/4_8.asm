;�Ƚ�bufx,bufY��bufZ�Ĵ�С
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
     jnz secmp	;����ȣ�������һ�αȽ�
     inc dl	;��ȣ�dl����
   secmp:
   	 mov ax,bufz
   	 cmp bufy,ax
   	 jnz judge	;����ȣ��ж�dl�Ƿ�Ϊ1
   	 inc dl	;���,dl����
   	 cmp dl,2 ;�ж��Ƿ����������
   	 jz output
   	 judge:cmp dl,1
   	 jz output	;dl=1,˵��ֻ����������ȣ�ֱ�����
   	 mov ax,bufx
   	 cmp ax,bufz
   	 jnz output		;����ȣ�ֱ�����
   	 inc dl		;��ȣ�dl����
   	 ;���
   	 output:add dl,30h
   	 mov ah,2
   	 int 21h
   	 lea dx,offset endstr
   	 mov ah,9
   	 int 21h
   	 
.EXIT
     END
