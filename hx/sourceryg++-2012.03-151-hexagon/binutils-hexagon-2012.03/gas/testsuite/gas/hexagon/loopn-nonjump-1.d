#name: loopN instructions are not jumps on Hexagon V5
#as: -march=hexagonv5
#objdump: -dr

.*:     file format .*


Disassembly of section .*:

00000000 <foo>:
[^:]*:	00 41 05 60 	60054100     { loop0 \(10 <NextMBAddr_SEARCH_LOOP>, r5\)
[^:]*:	00 40 7f 53 	537f4000       if !p0 jumpr r31
[^:]*:	e2 7f 64 97 	97647fe2       r2 = memuh \(r4 \+ #-2\)
[^:]*:	23 c0 64 9b 	9b64c023       r3 = memuh \(r4 \+\+ #2\) }
