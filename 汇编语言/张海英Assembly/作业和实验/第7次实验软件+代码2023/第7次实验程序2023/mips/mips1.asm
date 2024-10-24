data                           				 #数据段开始标�?
	out_string: .asciiz "\nHello, World!\n"

.text                           				 #代码段开始标�?
main:
	 addiu $2,$0,0x00000004
	 adddi $4,$0,0x00002000
	 syscall
	 addiu $2,$0,ox0000000a
	 syscall
	 