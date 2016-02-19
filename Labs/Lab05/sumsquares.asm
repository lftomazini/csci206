# Luis Felipe Tomazini
# T 1pm
# Lab 05 - sumsquares.asm
.data
.align 2

sum:		.word 	0
ivar:		.word	0
squares:	.space	100	
equals_string:	.asciiz "] = "
squares_string:	.asciiz "squares ["
newline:	.asciiz "\n"

# code segment --------------------------------------
.text
init:
	li 	$s3, 0 		# store 0 in i
	sw 	$s3, ivar
	li 	$s5, 0 		# store 0 in sum
	sw 	$s5, sum
	la 	$s4, squares	# put the address of save[0] in $s4
	
load_values:
	li	$t9 100				# sets branching stop condition to 100
	move	$t0, $zero			# sets offset as 0
	#lw	$t1, squares($t0)
	load_begin:
		ble	$t9, $s3, load_end	
		
		li	$t2, 0			# result of multiplication is initialized with 0
		move	$s6, $s3
	mult_begin:				# function to multiply
		beq	$s6, $zero, mult_end
		add	$t2, $t2, $s3
		addi	$s6, $s6, -1
		j	mult_begin
	mult_end:	
		sw	$t2, squares($t0)	# saves result in squares[i]
		add	$s5, $s5, $t2		# adds value in sum
		
		addi	$t0, $t0, 4		# adjust to the next element
		addi	$s3, $s3, 1		#increment i
		j	load_begin
	load_end:
	
print_values:
	li	$s3, 0				# sets i back to 0
	lw	$s7, 0($s4)			# loads first element of the array
	move	$t0, $zero
	print_begin:
		ble	$t9, $s3, print_end	
		la	$a0, squares_string	# print first part of string
		li	$v0, 4
		#syscall
	
		add	$a0, $zero, $s3		# print value of i
		li	$v0, 1
		#syscall
	
		la	$a0, equals_string	# print second part of the string
		li	$v0, 4
		#syscall
		
		add	$a0, $zero, $s7		# print value of squares[i]
		li	$v0, 1
		syscall
		addi	$t0, $t0, 4		# adjusting the base to “see” next element	
		lw	$s7, squares($t0)	# get next element
		
		la	$a0, newline		# print newline
		li	$v0, 4
		syscall
		
		addi	$s3, $s3, 1
		
		j print_begin
	print_end:
	
terminate:
	li 	$v0, 10 		# terminate program
	syscall
	
