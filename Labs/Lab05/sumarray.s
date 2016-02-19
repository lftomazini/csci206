# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
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
#               Lab 05 - sumarray.s
#
# This program calculates the sum of the values in array A and counts
# the number of values in the array.
#
# Similarly to a C-string, the array is terminated by sentinel value
# equal to zero.
#
# The sum is stored in $s0 and the count in $s1

	.data
A:	.word 5 4 3 2 4 1 0	# declare array int A[]={5,4,3,2,4,1,0};
count:
.asciiz "Number of elements = "
sum:
.asciiz " and the summation =  "	
	.text
main:				# This symbols marks the first instruction of your program

	move	$t0, $zero	
	lw	$t1, A($t0)	# assembler uses address of A as offset, $t0 as base - adding them together yields address of the first element in array
search:	
	beq	$t1, $zero, end	# verifies if element is sentinel
	addi	$t0, $t0, 4	# adjusting the base to “see” next element
	add	$s0, $s0, $t1 	# add current element to sum
	addi	$s1, $s1, 1	# increase count	
	lw	$t1, A($t0)	# get next element
	j	search

end:
	la	$a0, count
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s1	# print value of count
	li	$v0, 1
	syscall
	
	la	$a0, sum
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s0	# print value of sum
	li	$v0, 1
	syscall

	li	$v0, 10		# system call for exit
	syscall			# Exit!

