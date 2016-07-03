        .file   "main.s"
	.section        .text1,"ax",@progbits
	.globl othermain
	.type   othermain, @function
othermain:
	allocframe(#16)
	call myfn
	deallocframe
	jumpr r31
	.size   othermain, .-othermain
	.section        .text2,"ax",@progbits
	.globl main
	.type   main, @function
main:
	allocframe(#16)
	call myfn
	deallocframe
	jumpr r31
	.size   main, .-main

	.org 0x00800000
	.globl myfn
	.type    myfn, @function
myfn:
	allocframe(#16)
	deallocframe
	jumpr r31
	.size   myfn, .-myfn
