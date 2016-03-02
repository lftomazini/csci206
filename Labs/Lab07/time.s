# Luis Felipe Tomazini
# T 1pm
# Lab 07 - time.s
    .text
    .global add_second
add_second:
	move	$t0, $a0
	addi	$t0, $t0, -36
loop:
	addi	$t0, $t0, 36
	lw	$t0, 0($t1)
	addi	$t1, $t1, 1
	li	$t2, 60
	div	$zero, $t1, $t2
	mfhi	$t1
	
	bne	$zero, $t1, loop
	addi	$t0, $t0, 4
	lw	$t0, 0($t1)
	addi	$t1, $t1, 1
	li	$t2, 60
	div	$zero, $t1, $t2
	mfhi	$t1
	addi	$t0, $t0, -4
	
	bne	$zero, $t1, loop
	addi	$t0, $t0, 8
	lw	$t0, 0($t1)
	addi	$t1, $t1, 1
	li	$t2, 24
	div	$zero, $t1, $t2
	mfhi	$t1
	addi	$t0, $t0, -8
	j	loop
	

