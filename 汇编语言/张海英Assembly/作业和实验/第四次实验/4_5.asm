;˫ָ���㷨���ʵ��
;�����������������������������
.MODEL SMALL
.DATA
    array db 02h,07h,0bh,0fh,13h,1ch,24h,39h,40h,57h,68h
    target db 37h
.STACK
.CODE
.STARTUP
   lea bp,array		;bp��ָ��
   lea bx,array+sizeof array-1	;bx��ָ��
 try:mov al,[bp]
 	add al,[bx]
 	cmp al,target	;�Ƚ�bp+bx��target
 	jb bpp		;��С�ڣ���bp++
 	jz quit		;�����ڣ������
 	dec bx
 	cmp bx,bp
 	jb ending		;����targetʱ��bx--����bxС��bp��˵���Ҳ���
 	jmp try		;�����Ƚ�
bpp:inc bp
	cmp bp,bx
	jnbe ending	;��bp����bx,˵���Ҳ�����ֱ���˳�
 	jmp try		;�����Ƚ�
quit:
	mov dl,[bp]
	mov cl,4
	shr dl,cl
	add dl,30h
	mov ah,2
	int 21h
	mov dl,[bp]
	and dl,0fh
	add dl,30h
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
	mov dl,[bx]
	shr dl,cl
	add dl,30h
	mov ah,2
	int 21h
	mov dl,[bx]
	and dl,0fh
	add dl,30h
	mov ah,2
	int 21h
	mov dl,10
	mov ah,2
	int 21h
ending:
	mov ah,4ch
	int 21h
.EXIT
     END
