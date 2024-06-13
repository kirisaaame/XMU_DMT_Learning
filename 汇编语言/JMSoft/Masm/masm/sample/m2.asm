；***********************************************
;  *程序功能:多模块连接，模块2:M1显示Word  *
;  *                                                               *
;  *注意：使用软件的多模块连接功能               * 
;  *编译器：Masm 5.0                                    *
;  ***********************************************
PUBLIC	OUTMSG
DATAS   SEGMENT      		
   MSG	DB 'World!',13,10,'$'
DATAS   ENDS

CODES	SEGMENT   			

OUTMSG	PROC FAR
	ASSUME	CS:CODES,DS:DATAS
START:	
	mov  	ax,DATAS
	mov  	ds,ax		     	
	mov  	dx,OFFSET MSG     	
	mov  	ah,09h		     	
	int	21h		     	; 显示MSG,结果为"World!"
	ret
OUTMSG	ENDP
CODES	ENDS
	END START