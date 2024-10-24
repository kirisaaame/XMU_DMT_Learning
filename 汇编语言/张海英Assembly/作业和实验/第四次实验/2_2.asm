;循环将bx右移1位,直到bx等于0
.MODEL SMALL
.DATA
.STACK
.CODE
.STARTUP
    mov bx,1145h
    mov cl,16
    mov ax,0
  try:
  	shr bx,1
  	inc al
  	cmp bx,0
  	jz quit
  	jmp try
  quit:
  	mov dl,al
  	add dl,37h
  	mov ah,2
  	int 21h
  	
.EXIT
     END
