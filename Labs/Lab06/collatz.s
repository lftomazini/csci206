.data
MAX_ITEMS:	.word	100
ivar:		.word	1	# int i
arrow_string:	.asciiz " ==> "
newline:	.asciiz "\n"

.text
main:
	# store 1 in i
	li 	$s0, 1
	sw 	$s0, ivar
	
	# store 100 in MAX_ITEMS
	li 	$s1, 100
	sw 	$s1, MAX_ITEMS
loop:	
	bge 	$s0, $s1, end
	
	move	$a0, $s0

	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# go to find_length
	jal	find_length
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4

	move	$s2, $a0
	
	# print value of collatz
	add	$a0, $zero, $s0
	li	$v0, 1
	syscall
	
	la	$a0, arrow_string
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s2
	li	$v0, 1
	syscall
	
	la	$a0, newline
	li	$v0, 4
	syscall
	
	addi	$s0, $s0, 1
	j	loop

collatz:
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# store comparison value
	li	$t0, 1
	# comparison branch
	bne	$a0, $t0, elseif
	# store value to return
	move	$v0, $t0
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# jump back to routine
	jr	$ra
	
elseif:
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# store division value
	li	$t2, 2
	# make division
	div	$a0, $t2
	# mod is stored in hi
	mfhi	$t1
	# comparison branch
	bne	$zero, $t1, else
	
	# push n
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
	
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# preparing arguments
	div	$a0, $t2
	mflo	$a0
	
	# call to colllatz
	jal	collatz
	
	# move values
	move	$v0, $a0
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# pop n
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4
	
	add	$a0, $v0, $t0
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# jump back to routine
	jr	$ra
	
else:	
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# push n
	addi	$sp, $sp, -4
	sw	$a0, 0($sp)
	
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# preparing argument
	li	$t1, 3
	mulo	$a0, $a0, $t1
	addi	$a0, $a0, 1
	
	# call to colllatz
	jal	collatz
	
	# move values
	move	$v0, $a0
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# pop n
	lw	$a0, 0($sp)
	addi	$sp, $sp, 4
	
	add	$a0, $v0, $t0
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# jump back to routine
	jr	$ra


find_length:
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)

	# store comparison value
	li	$t0, 1
	# comparison branch
	bgt	$a0, $t0, length_else
	# store value to return
	move	$a0, $t0
	
	# jump back to routine
	jr	$ra
	
	length_else:
	jal	collatz
	
	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	
	# jump back to routine
	jr	$ra
end:
	# terminate program
	li 	$v0, 10
	syscall
