; ******************************************************************************
;  * 程序功能:输出乘法口诀表                 
;  1*1=1
;  1*2=2 2*2=4
;  1*3=3 2*3=6 3*3=9
;  1*4=4 2*4=8 3*4=12 4*4=16
;  1*5=5 2*5=10 3*5=15 4*5=20 5*5=25
;  1*6=6 2*6=12 3*6=18 4*6=24 5*6=30 6*6=36
;  1*7=7 2*7=14 3*7=21 4*7=28 5*7=35 6*7=42 7*7=49
;  1*8=8 2*8=16 3*8=24 4*8=32 5*8=40 6*8=48 7*8=56 8*8=64
;  1*9=9 2*9=18 3*9=27 4*9=36 5*9=45 6*9=54 7*9=63 8*9=72 9*9=81
;  *编译器：Masm 5.0,ML6.11都可以          
;  ******************************************************************************
data segment
  a db ?
  b db ?
  c1 db ?              ;C是关健字不可以用作变量名
data ends
code segment
   assume cs:code,ds:data
start:
   mov ax,data
   mov ds,ax
   mov a,1
lp2:mov b,1
lp1:mov al,a   
    mul b        ;1X1结果保存在AL中
    mov c1,al    ;送入C1保存第一个结果
    call disp    ;
    add b,1
    mov al,b
    cmp al,a
    jbe lp1      ;是否相等
    call dad     ;否则换行
    add a,1      ;a+1
    cmp a,9      ;是否等于9
    jbe lp2      
    mov ah,4ch   ;大于九则结束
    int 21h
disp proc
     mov dl,b   
     or dl,30h   ;把DL的内容转成十进制
     mov ah,2    
     int 21h      ;输出DL内容
     mov dl, '*'   
     int 21h      ;输出一个*号
     mov dl,a     
     or dl,30h    ;把变量A转成十进制
     int 21h       ;输出
     mov dl,'='   ;输出=号
     int 21h
     mov dl,c1    ;把乘积的结果送入DL
     cmp dl,9     ; CF∨ZF = 0 ？
     ja aa1       
     or dl,30h     ;DL内容转成十进制
     mov ah,2        
     int 21h        ;输出
     mov dl, ' '    ;输出一个空字符
     int 21h
     jmp over       ;跳转到结束
aa1:mov bl,dl      ;  
     mov dl,0       
aa3:cmp bl,10      ;小于10吗?
     jb aa2         ;低于10则跳
     sub bl,10       ;主要是为了调整大于9的十进制数输出(例如25-10 DL=2 BL=5这样就可以输出结果)
     inc dl          ;用dl来保存进位
     jmp aa3         ;再次比较是否大于十
aa2:or dl,30h       ;先输出进位部分
     mov ah,2        ;
     int 21h         ;
     mov dl,bl       ;输出最后的差
     or dl,30h       ;调整为十进制
     mov ah,2        ;
     int 21h         ;
     mov dl,' '      ;
     int 21h         ;
over:ret
disp endp
dad proc
     mov dl,0ah   ;换行
     mov ah,2
     int 21h
     mov dl,0dh
     int 21h     
     ret
dad endp
code ends
    end start
