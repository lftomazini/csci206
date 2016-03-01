# Luis Felipe Tomazini
# T 1pm
# Lab 07 - counte.s
	.data
estring:	.byte	'e'
null:		.byte	'\0'
	.text
	.global counte
counte:
	lb	$t0, estring
	addi	$a0, $a0, -1	# decrement loop variable
	lb	$t3, null
	move	$v0, $zero
loop:
	addi	$a0, $a0, 1	# increment loop variable
	lb	$t2, 0($a0)	# get char
	beq	$t2, $t3, end	# loop
	nop
	bne	$t2, $t0, loop	# if statement
	nop
	addi	$v0, $v0, 1	# increment count
	j	loop
	nop
end:
	jr	$ra
	nop
	
	
