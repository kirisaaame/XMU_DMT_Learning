.model small
.data
.stack
.code
.startup
mov ax,0b800h
mov ds,ax	;将DS设置到目标段
mov cx,100	;设置循环次数
mov bx,0	;设置下标
xor ax,ax	
xor dx,dx	;清空dx.ax寄存器
lp:add ax,word ptr [bx]
adc dx,0
add bx,2
loop lp	;循环相加

.exit 
end
