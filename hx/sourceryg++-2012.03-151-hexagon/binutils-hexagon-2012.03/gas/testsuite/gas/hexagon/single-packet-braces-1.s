	.text
	{
		r0 = r2
		jumpr lr
	}
	dealloc_return
	{
		r0 = memw(r1)
		r2 = add(r2, #4)
	}
