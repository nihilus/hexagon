#name: hexagonv5-specific insns, regs
#as: -march=hexagonv55
#objdump: -d

#...
00000000 <.text>:
 * 0:	[0-9a-f ]*	a820d000 *{ l2gclean }
 * 4:	[0-9a-f ]*	a820d800 *{ l2gcleaninv }
 * 8:	[0-9a-f ]*	a820c800 *{ l2gunlock }
 * c:	[0-9a-f ]*	eaa2c440 *{ r1:0, p2 = vacsh \(r3:2, r5:4\) }
 *10:	[0-9a-f ]*	78004000 *{ r0 = #0
 *14:	[0-9a-f ]*	78004021 *r1 = #1
 *18:	[0-9a-f ]*	78004042 *r2 = #2
 *1c:	[0-9a-f ]*	a0e7e002 *p2 = l2locka \(r7\) }
 *20:	[0-9a-f ]*	78004063 *{ r3 = #3
 *24:	[0-9a-f ]*	a667c000 *l2unlocka \(r7\) }
 *28:	[0-9a-f ]*	6eb34003 *{ r3 = pmucnt3
 *2c:	[0-9a-f ]*	f120c300 *r0 = or \(r0, r3\) }
 *30:	[0-9a-f ]*	6eacc004 *{ r4 = pmucnt4 }
 *34:	[0-9a-f ]*	6eadc005 *{ r5 = pmucnt5 }
 *38:	[0-9a-f ]*	6eaec006 *{ r6 = pmucnt6 }
 *3c:	[0-9a-f ]*	6eafc007 *{ r7 = pmucnt7 }
 *40:	[0-9a-f ]*	6704c02c *{ pmucnt4 = r4 }
 *44:	[0-9a-f ]*	6705c02d *{ pmucnt5 = r5 }
 *48:	[0-9a-f ]*	6706c02e *{ pmucnt6 = r6 }
 *4c:	[0-9a-f ]*	6707c02f *{ pmucnt7 = r7 }
