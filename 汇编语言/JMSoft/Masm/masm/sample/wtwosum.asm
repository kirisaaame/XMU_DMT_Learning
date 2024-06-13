;********************************************
;  *程序功能:Windows汇编计算3+5的和      *
;  *编译器：ML6.15汇编程序（WIN32）     *
;  ********************************************
.386 ;表示要用到386指令
.model Flat,stdcall ;32位程序，要用flat啦！;stadcall,标准调用
option casemap:none ;区别大小写

include windows.inc ;包括常量及结构定义
include kernel32.inc ;函数原型声明
include user32.inc

includelib kernel32.lib ;用到的引入库
includelib user32.lib

.data;数据区，定义2个字符串
szCaption db "5+3等于",0
szFive  db    5
szBuffer db 4 dup(0)
.code ;代码开始执行处
start: 
    MOV AL,szFive
    ADD AL,3
    ADD AL,30H
    MOV szBuffer,AL  ;将5+3的和放在szBuffer缓冲区中   
     ;调用MessageBox API函数显示szBuffer缓冲区中8
    invoke MessageBox,NULL,addr szBuffer,addr szCaption,MB_OK 
    invoke ExitProcess,NULL ;程序退出
end start;结束
 

    
   