# Luis Felipe Tomazini
# T 1pm
# Lab 07 - counte.s
	.data
estring:	.ascii	"e"
null:		.ascii	"\0"
	.text
	.global counte
counte:
	lw	$t0, estring
	move	$t1, $a0
	addi	$t1, $t1, -1	# decrement loop variable
	lw	$t3, null
	move	$a0, $zero
loop:
	addi	$t1, $t1, 1	# increment loop variable
	lb	$t2, 0($t1)	# get char
	beq	$t2, $t3, end	# loop
	nop
	bne	$t2, $t0, loop# if statement
	nop
	addi	$a0, $a0, 1	# increment count
end:
	jr	$ra
	
	