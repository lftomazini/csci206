
# CSCI 206 Computer Organization & Programming
# Date: 2011-08-29
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


	.data
	
unused:	.word 0xDEADBEEF			
						
x:	.word 89				
						
	.text	
main:						# This tells the simulator
						# where start your program

	
	add		$t0, $zero, $zero	# sets the value of $t0 to zero	
	add		$t1, $zero, $zero	# sets the value of $t1 to zero

loop:
	add		$t1, $t1, $t0		# variable that inceases by the number of the loop variable, +1, +2, +3, ...
	addi		$t0, $t0, 1		# loop variable, increases by 1 each time
	ble		$t0, 10, loop		# creates the loop, by branching with 'less then or equal to' 10 and goes back to 'loop' (line 40)

	la		$t2, x			# copy RAM address from variable 'x' to $t2 
	sw		$t1, 0($t2)		# store word in register $t1 into RAM at address contained in1 $t2
	
	li		$v0, 10			# system call for exit
	syscall					# Exit!

