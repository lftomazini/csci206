.data
.align 2

sum:
.word 	0
ivar:
.word	0
squares:
.word	
equals_string:
.asciiz "] = "
squares_string:
.asciiz "squares ["

# code segment --------------------------------------
.text
init:
	li 	$s3, 0 		# store 0 in i
	sw 	$s3, ivar
	li 	$s5, 0 		# store 0 in sum
	sw 	$s5, sum
	la 	$s4, squares	# put the address of save[0] in $s4
	
load_values:
	li	$v0, 100
	load_begin:
		ble	$v0, $s3, load_end
		
		add	$t1, $zero, $s3 	# $t1 = i
		sll	$t1, $t1, 2 		# convert index to byte addres (multiply $t1 by 4)
		add	$t1, $t1, $s4		# $t1 = &squares[0] + $t1 (byte address of squares[i])
		mulou	$t2, $s3, $s3
		lw	$t2, 0($t1)		# $t2 = squares[i]
		
		add	$s5, $s5, $t2
		addi	$s3, $s3, 1
		j	load_begin
	load_end:
	
print_values:
	li	$s3, 0
	print_begin:
		ble	$v0, $s3, print_end	
		la	$a0, squares_string	# print first part of string
		li	$v0, 4
		syscall
	
		add	$a0, $zero, $s3		# print value of i
		li	$v0, 1
		syscall
	
		la	$a0, equals_string	# print second part of the string
		li	$v0, 4
		syscall
		
		add	$a0, $zero, $s3		# print value of squares[i]
		li	$v0, 1
		syscall
	print_end:
	
terminate:
	li 	$v0, 10 		# terminate program
	syscall
	