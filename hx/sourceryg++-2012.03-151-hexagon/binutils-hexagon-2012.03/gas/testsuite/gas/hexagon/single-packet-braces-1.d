#name: Use of braces for single-instruction packets
#as: -march=hexagonv4
#objdump: -dr

.*:     file format .*


Disassembly of section \.text:

00000000 <\.text>:
   0:	c0 3f 20 50 	50203fc0     { r0 = r2 ; jumpr lr }
   4:	1e c0 1e 96 	961ec01e     { dealloc_return }
   8:	10 00 42 40 	40420010     { r2 = add \(r2, #4\) ; r0 = memw \(r1 \+ #0\) }
