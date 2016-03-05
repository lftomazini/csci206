# Luis Felipe Tomazini
# T 1pm
# Lab 07 - time.s
    .text
    .global add_second
add_second:
	move	$t0, $a0	# save the address from the parameter
	lw	$t1, 0($t0)	# load the value of the first field
	addi	$t1, $t1, 1	# increment seconds
	li	$t2, 60		# load immediate value for division
	div	$zero, $t1, $t2	# divide the result by the number of seconds
	mfhi	$t1		# get mod malue
	sw	$t1, 0($a0)	# saves result
	
	bne	$zero, $t1, end	# checks if result is 0 to increment minutes
	nop
	addi	$t0, $t0, 4	# increment base to see next element
	lw	$t1, 0($t0)	# load the value of the second field
	addi	$t1, $t1, 1	# increment minutes
	li	$t2, 60		# load immediate value for division
	div	$zero, $t1, $t2	# divide the result by the number of minutes
	mfhi	$t1		# get mod value
	sw	$t1, 4($a0)	# saves result
	
	bne	$zero, $t1, end	# checks if the result is 0 to increment hours
	nop
	addi	$t0, $t0, 4	# increment base to see next element
	lw	$t1, 0($t0)	# load the value of the third field
	addi	$t1, $t1, 1	# increment hours
	li	$t2, 24		# load immediate value for division
	div	$zero, $t1, $t2	# divide the result by the number of hours
	mfhi	$t1		# get mod value
	sw	$t1, 8($a0)	# saves result
	
end:
    	move	$a0, $t1	# moves result back to inital parameter
	jr	$ra		# return to function
	nop
