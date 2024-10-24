.MODEL SMALL
.DATA
    NUM DW 5              ; 定义常量NUM，值为5
    DATALIST DW -1, 0, 2, 5, 4, ?  ; 定义字数组DATALIST，包括前5个字单元和一个未初始化的字单元
.STACK
.CODE
.STARTUP
    MOV CX, NUM          ; 将常量NUM加载到CX寄存器
    LEA SI, DATALIST     ; 将DATALIST的起始地址加载到SI寄存器
    XOR AX, AX           ; 清零累加和 AX 寄存器

SUM_LOOP:
    ADD AX, [SI]         ; 将DATALIST中当前元素的值加到累加和中
    ADD SI, 2            ; 移动到下一个字单元
    LOOP SUM_LOOP        ; 循环NUM次

    MOV [SI], AX         ; 将累加和存入DATALIST的最后一个字单元
.EXIT
END
