	.text
	.p2align 2
	.p2align 4,,15
	.globl foo
	.type	foo, @function
foo:
	{
	    memw(r0) = r1
	    memw(r2) += #1
	}
