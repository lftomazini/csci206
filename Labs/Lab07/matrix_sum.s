# Luis Felipe Tomazini
# T 1pm
# Lab 07 - matrix_sum.s
	.data

	.text
	.global matrix_sum
matrix_sum:
	li	$t4, 6
	li	$t5, 0
	move	$t3, $a0
	move	$t7, $a1
	bge	$t5, $t4, end
	nop
	lw	$t0, 0($t3)
	lw	$t1, 0($t7)
	add	$t2, $t0, $t1
	
	sw	$t5, 0($a2)
	
	addi	$t3, $t3, 4
	addi	$t7, $t7, 4
	addi	$a2, $a2, 4
	addi	$t5, $t5, 1
end:
	jr	$ra
	nop