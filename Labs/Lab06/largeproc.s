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
# Student name:
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
Result1:.word 0xDEADBEEF
Result2:.word 0xDEADBEEF

	.text

# The main() procedure calls largeProc, storing the results into
# Result1 and Result2 and also printing them out to the terminal.

main:

	# Prepare arguments to pass to largeProc
	lw	$a0, A
	lw	$a1, B
	lw	$a2, C
	lw	$a3, D

	# Call largeProc
	jal	largeProc

	# Print the results returned from largeProc
	add	$a0, $zero, $v0		# print value of first result
	li	$v0, 1
	syscall
	
	add	$a0, $zero, $v1		# print value of second result
	li	$v0, 1
	syscall

	# The program is finished. Terminate the execution.
	addi	$v0, $zero, 10		# system call for exit
	syscall

# This large complicated procedure takes 6 paramters and returns 2.
# Additionally this procedure calls another procedure.
# It is assumed that $fp has been set correctly

largeProc:

# your code goes here
	
	# Store registers which must be saved onto the stack
	
	# push $ra
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	
	# read instead of pop
	
	# pop last value aka p5
	lw	$t0, 0($sp)
	addi	$sp, $sp, 4
	
	# pop last value aka p4
	lw	$t1, 0($sp)
	addi	$sp, $sp, 4
	
	# Compute the first result
	add	$v0, $a1, $a2
	add	$v0, $v0, $t1

	# Compute the second result
	sub	$v1, $a0, $a3
	add	$v0, $v0, $t0

	# Saves the results just in case the other procedure changes them
	addi	$sp, $sp, -4
	sw	$v0, 0($sp)
	
	addi	$sp, $sp, -4
	sw	$v1, 0($sp)

	# Call smallProc
	jal smallProc

	# Restore registers using the stack
	lw	$v1, 0($sp)
	addi	$sp, $sp, 4
	
	lw	$v0, 0($sp)
	addi	$sp, $sp, 4
	
	# pop $ra

	jr	$ra

# This procedure computes nothing useful, it just returns

smallProc:

	jr	$ra
		
