;�����ַ���ƥ���㷨
;int brutal_search(char * str,char * pattern)
;{
;	for (int i=0;i<length;i++)
;	{
;		count=0;
; 		for (int j=0;j<5,j++)
;	{
;		
;		if(str[i+j]==pattern[j])
;		{	
;			count++;
;;		if(count >= 5)
;			return i;
;		}
;		else continue;
.model small
.data
	string db 'DEBUG'
.stack
.code
.startup
	mov ax,0070h
	mov es,ax	;��Ŀ��ε�ַ��ES
	mov cx,1000h
	mov bx,0000h
	mov si,0	;��ʼ��
	STARTc:mov si,0
		push cx
		mov cx,5
	comp:mov al,byte ptr string[si]
		mov dl,byte ptr es:[bx+si]
		cmp al,dl
		jnz conti	;��ƥ�䣬������һ��ѭ��
		inc si	;ƥ�䣬si++
		cmp si,5
		jz quit
		loop comp	;����õ�ƥ�������˳�
		conti: pop cx
		inc bx	;i++
		loop startc
	quit: cmp si,5
		jz next
		mov dl,30h
		jmp output
	next: mov dl,31h
	output:mov ah,2
		int 21h
.exit
 end