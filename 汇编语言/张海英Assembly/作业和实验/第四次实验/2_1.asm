;ѭ������16�Σ�ÿ�ν�bx����1λ
.MODEL SMALL
.DATA
.STACK
.CODE
.STARTUP
    mov bx,4637h
    mov cl,16
  try:
  	shr bx,1
  	loop try
.EXIT
     END
