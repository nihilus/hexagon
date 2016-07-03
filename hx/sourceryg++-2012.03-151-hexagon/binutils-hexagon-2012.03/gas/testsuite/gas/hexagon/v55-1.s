	.text
	l2gclean
	l2gcleaninv
	l2gunlock
	r1:0, p2 = vacsh (r3:2, r5:4)
	{ r0 = #0
	p2 = l2locka (r7)
  	r1 = #1
	r2 = #2 }
	{ r3 = #3
	l2unlocka (r7) }

	{ r3 = pmucnt3
	r0 = or(r0,r3) }
	r4 = pmucnt4
	r5 = pmucnt5
	r6 = pmucnt6
	r7 = pmucnt7

	pmucnt4 = r4
	pmucnt5 = r5
	pmucnt6 = r6
	pmucnt7 = r7
