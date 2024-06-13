.386 ;表示要用到386指令
.model Flat,stdcall ;32位程序，要用flat啦！;stadcall,标准调用
option casemap:none ;区别大小写
include windows.inc ;包括常量及结构定义

include kernel32.inc ;函数原型声明
include user32.inc

includelib kernel32.lib ;用到的引入库
includelib user32.lib

.data;数据区，定义2个字符串
szText db "Hello world!",0
szCaption db "Masm for Windows 集成实验环境",0

.code ;代码开始执行处
start: 
invoke MessageBox,NULL,addr szText,addr szCaption,MB_OK 

;调用MessageBoxAPI函数
invoke ExitProcess,NULL ;程序退出
end start;结束


