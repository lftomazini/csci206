# CSCI 206 Computer Organization & Programming
# Date: 2011-09-19
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and
# supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Student name: Luis Felipe Tomazini
#               T 1pm
#               Lab 06 - largeproc.s
#
# This program demonstrates passing a large number of arguments to a
# procedure which is not a leaf procedure.

	.data
	.align 2
A:	.word 3
B:	.word 7
C:	.word 4
D:	.word 9
E:	.word 3
F:	.word 8
result_1:	.asciiz "Result 1: "
result_2:	.asciiz "Result 2: "
newline:	.asciiz "\n"

	.text

# The main() procedure calls largeProc, storing the results into
# Result1 and Result2 and also printing them out to the terminal.

main:

	# Prepare arguments to pass to largeProc
	lw	$a0, A
	lw	$a1, B
	lw	$a2, C
	lw	$a3, D
	lw	$t6, E
	lw	$t7, F

    	# push E
	addi	$sp, $sp, -4
	sw	$t6, 0($sp)

    	# push F
	addi	$sp, $sp, -4
	sw	$t7, 0($sp)

    	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)

	# Call largeProc
	jal	largeProc

	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4

	# pop F
	lw	$t7, 0($sp)
	addi	$sp, $sp, 4
	
	# pop E
	lw	$t6, 0($sp)
	addi	$sp, $sp, 4

	# move results
	move	$t6, $v0
	move	$t7, $v1

	# Print the results returned from largeProc
	la	$a0, result_1       # print string "Result 1: "
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $t6		# print value of first result
	li	$v0, 1
	syscall
	
	la	$a0, newline        # print new line character
	li	$v0, 4
	syscall
	
	la	$a0, result_2       # print string "Result 2: "
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $t7		# print value of second result
	li	$v0, 1
	syscall

	# The program is finished. Terminate the execution.
	addi	$v0, $zero, 10		# system call for exit
	syscall

# This large complicated procedure takes 6 paramters and returns 2.
# Additionally this procedure calls another procedure.
# It is assumed that $fp has been set correctly
largeProc:
	# Store registers which must be saved onto the stack
   	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# read value p5
	lw	$t0, 8($sp)
	
	# read value p4
	lw	$t1, 12($sp)
	
	# Compute the first result
	add	$v0, $a1, $a2
	add	$v0, $v0, $t1

	# Compute the second result
	sub	$v1, $a0, $a3
	add	$v1, $v1, $t0

	# Saves the results just in case the other procedure changes them

    	# push result 1
	addi	$sp, $sp, -4
	sw	$v0, 0($sp)

    	# push result 2
	addi	$sp, $sp, -4
	sw	$v1, 0($sp)

	# Call smallProc
	jal smallProc

	# Restore registers using the stack
    	# pop result 2
	lw	$v1, 0($sp)
	addi	$sp, $sp, 4

   	 # pop result 1
	lw	$v0, 0($sp)
	addi	$sp, $sp, 4

    	# pop $ra
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4

	jr	$ra

# This procedure computes nothing useful, it just returns
smallProc:

	jr	$ra

# If I had 3 values to be returned from the large procedure, two of them would go in the $v registers and the other would be pushed to the stack
		
