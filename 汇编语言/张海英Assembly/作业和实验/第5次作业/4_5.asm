;假定输入的数据为lednum,数据存储在al中
.MODEL SMALL
.DATA
     ledtable db 0c0h,0f9h,0a4h,0b0h,99h,92h,82h,0f8h
     		  db 80h,90h,88h,83h,0c6h,0c1h,86h,8eh
     lednum db 9
.STACK
.CODE
.STARTUP
     LEA bx,ledtable
     MOV  si,9
     xlat
     mov ah,4ch
     int 21h
.EXIT
     END
