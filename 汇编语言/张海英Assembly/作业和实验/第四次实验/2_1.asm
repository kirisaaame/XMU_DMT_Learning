;循环次数16次，每次将bx右移1位
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
