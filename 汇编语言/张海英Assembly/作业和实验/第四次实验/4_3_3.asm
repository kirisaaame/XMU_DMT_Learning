.model small
.data
.stack
.code
.startup
mov ax,0b800h
mov ds,ax	;��DS���õ�Ŀ���
mov cx,100	;����ѭ������
mov bx,0	;�����±�
xor ax,ax	
xor dx,dx	;���dx.ax�Ĵ���
lp:add ax,word ptr [bx]
adc dx,0
add bx,2
loop lp	;ѭ�����

.exit 
end
