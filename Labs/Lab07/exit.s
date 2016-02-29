# Luis Felipe Tomazini
# T 1pm
# Lab 07 - exit.s
    .text
    .global __start
__start:
    li $a0, 42
    li $v0, 4001
    syscall
