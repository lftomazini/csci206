# Luis Felipe Tomazini
# T 1pm
# Lab 07 - time.s
    .text
    .global add_second
add_second:
	move	$t0, $a0
	lw	$t1, 0($t0)
	addi	$t1, $t1, 1
	li	$t2, 60
	div	$zero, $t1, $t2
	mfhi	$t1
	sw	$t1, 0($a0)
	
	bne	$zero, $t1, end
	nop
	addi	$t0, $t0, 4
	lw	$t1, 0($t0)
	addi	$t1, $t1, 1
	li	$t2, 60
	div	$zero, $t1, $t2
	mfhi	$t1
	sw	$t1, 4($a0)
	
	bne	$zero, $t1, end
	nop
	addi	$t0, $t0, 4
	lw	$t1, 0($t0)
	addi	$t1, $t1, 1
	li	$t2, 24
	div	$zero, $t1, $t2
	mfhi	$t1
	sw	$t1, 8($a0)
	
end:	move	$a0, $t1
	jr	$ra
	nop
