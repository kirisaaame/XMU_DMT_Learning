.model small
.data
.code
.startup
main:mov ax,3	;��n=3
	 call fact
xi:	 mov bx,dx
.exit 0
;�׳��ӳ���
;��ڲ�����AL�д��n
;���ڲ�����DX�д��n!
;���üĴ����� CX

fact proc
	cmp al,0
	jnz iia		;AL!=0,iia
	mov dl,1	;AL==0,DL=1
	ret		;(1)
iia:push ax		
dec al		;
	call fact
x2:pop cx
	call mult
x3: mov dx,ax
	ret		;
fact endp
;�޷����ֽ����˷��ӳ���
;��ڲ�����CL��DL�и�Ϊһ����
;���ڲ�����AX��Ϊ�˻�

mult proc
	mov al,dl
	mul cl
	ret	;(3)
mult endp
	end