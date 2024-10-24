;暴力字符串匹配算法
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
	mov es,ax	;将目标段地址给ES
	mov cx,1000h
	mov bx,0000h
	mov si,0	;初始化
	STARTc:mov si,0
		push cx
		mov cx,5
	comp:mov al,byte ptr string[si]
		mov dl,byte ptr es:[bx+si]
		cmp al,dl
		jnz conti	;不匹配，进入下一个循环
		inc si	;匹配，si++
		cmp si,5
		jz quit
		loop comp	;如果得到匹配结果，退出
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