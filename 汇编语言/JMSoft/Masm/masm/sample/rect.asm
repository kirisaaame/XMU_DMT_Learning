;********************************************
;  *程序功能:绘图程序!                                *
;  *编译器：Masm 5.0,ML6.11都可以          *
;  ********************************************
CODES SEGMENT
      ASSUME CS:CODES
START:
      mov ah,00
      mov al,06h
     int 10h ;设置640*480、16色彩色分辨率
     mov dx,50
back_1:
     mov cx,100
back_2:
     mov ah,0ch
     mov al,71h ;白底蓝色图 
     mov bh,0
     int 10h
     inc cx
     cmp cx,200
     jnz back_2
     inc dx
     cmp dx,150
     jnz back_1
CODES ENDS
    END START

