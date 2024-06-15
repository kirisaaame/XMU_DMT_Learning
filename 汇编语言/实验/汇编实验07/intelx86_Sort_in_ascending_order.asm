    
    .486                                    			
    .model flat, stdcall                    		
    option casemap :none                    		
    include \masm32\macros\macros.asm       	
    includelib \masm32\lib\masm32.lib
    includelib \masm32\lib\gdi32.lib
    includelib \masm32\lib\user32.lib
    includelib \masm32\lib\kernel32.lib
    includelib \masm32\lib\wsock32.lib
    includelib \masm32\lib\msvcrt.lib
    include \masm32\include\msvcrt.inc
    include \masm32\include\masm32.inc
    include \masm32\include\gdi32.inc
    include \masm32\include\user32.inc
    include \masm32\include\kernel32.inc
 
.data								
	arr dd 8, 1, 5, 2, 7, 9, 6, 4, 3, 10 		 
	len1 byte ? 						
	len2 byte ? 						
	fmt byte '%d ',0
 
.code
main:        
	mov len1,lengthof arr                                                                                      
	mov ebx,offset arr                               
	xor ecx,ecx
	mov al,len1
prt1:	
	movsx ebx,al
	cmp ecx,ebx
	jnb fina1
	mov edx, arr[(type arr)*ecx]
	pushad
	invoke crt_printf,offset fmt,edx              
	popad
	inc ecx
	jmp prt1
fina1:
    	print chr$(" ",13,10)                                           
	print chr$(" ",13,10)                                 
 
	mov len1,lengthof arr                          
	mov ebx,offset arr                                
	mov al,0h                                              		 	
lp:	
	cmp al,len1
	jnb done                                          			
 
	mov ah, 1h	                       
inner:				
	mov cl,len1                                       
	mov len2,cl                                      
	sub len2,al                                          
	cmp ah,len2                                       
	jnb last                                                 
	movsx esi,ah 		           
	mov bl,ah                                    
	sub bl,1                                         
	movsx edi,bl                                     
	mov ecx, arr[(type arr)*esi]               
	mov edx, arr[(type arr)*edi]             
	cmp ecx,edx                                      
	ja follow 		          	           
	mov edx,arr[(type arr)*esi]                
	xchg edx,arr[(type arr)*edi]               
	xchg edx,arr[(type arr)*esi]               
follow:	
	inc ah 	                                          	
	jmp inner                                        
last:	
	inc al                                                 			
	jmp lp                                            
 
done:	
	xor ecx,ecx                                     
	mov al,len1
prt:	
	movsx ebx,al
	cmp ecx,ebx
	jnb fina
	mov edx, arr[(type arr)*ecx]
	pushad
	invoke crt_printf,offset fmt,edx
	popad
	inc ecx
	jmp prt
fina:	
	exit
 
end main 				