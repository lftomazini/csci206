# Luis Felipe Tomazini
# T 1pm
# Lab 07 - is_prime.s
    .text
    .global is_prime
is_prime:
	li	$t0, 1		# set loop variable initial value
	addi	$t1,$a0, -1	# set break condition
loop:
	addi	$t0, $t0, 1	# increment loop variable
	bge	$t0, $t1, end	# loop
	nop
	div	$zero, $a0, $t0	# makes division
	mfhi	$t2		# move mod value
	bne	$zero, $t2, loop# if statement
	nop
	li	$v0, 0		# return 0
	
	jr	$ra
	nop

end:
	li	$v0, 1		# return 1
	
	jr	$ra
	nop
	
