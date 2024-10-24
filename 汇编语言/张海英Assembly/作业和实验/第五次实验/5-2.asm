.model small
.data
	number dw 0001,0002,0003,0004,0005
	score db 17,36,52,53,78
.stack
.code
;排序方法：冒泡排序
;传出参数：DX
.startup
mov dx,lengthof number
call bubblesort
mov dx,number
add dl,30h
mov ah,2
int 21h
mov dl,10
mov ah,2
int 21h
.exit 0

bubblesort proc
	mov cx,dx
.repeat
	mov si,0
	mov bx,cx
	dec bx
	.repeat
		mov al,score[si+1]
		.if al>score[si]
			xchg score[si],al	;score[si+1]->score[si]
			mov score[si+1],al	;score[si]->score[si+1]
			;shl si,1
			;mov dx,number[si]
			;xchg number[si+2],dx
			;mov number[si],dx	;交换number
			;shr si,1
		.endif
		inc si
	.until si>=bx
.untilcxz
ret
bubblesort endp
end