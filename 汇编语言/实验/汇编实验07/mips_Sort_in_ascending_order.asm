.data
numbers:    .word 8, 1, 5, 2, 7, 9, 6, 4, 3, 10    
size:       .word 10                             

.text
main:
    la $t0, numbers         
    lw $t1, size           
    subi $t1, $t1, 1        

outer_loop:
    beq $t1, $zero, outer_end   

    li $t2, 0              
    move $t5, $t0           

    inner_loop:
        bge $t2, $t1, inner_end 
        lw $t3, 0($t5)          
        lw $t4, 4($t5)         
        ble $t3, $t4, no_swap   


        sw $t3, 4($t5)         
        sw $t4, 0($t5)          

no_swap:
        addi $t5, $t5, 4       
        addi $t2, $t2, 1        
        j inner_loop

    inner_end:
    subi $t1, $t1, 1       
    j outer_loop

outer_end:

    li $v0, 10              
    syscall

