#name: avoid hexagon veneer reuse in overlay
#source: overlay1.s
#as: -march=hexagonv4
#ld: -Toverlay1.ld
#objdump: -d

#...
Disassembly.+\.text1:

00001000 <othermain>:
 +1000:[\s0-9a-f]+{ allocframe.*
 +1004:[\s0-9a-f]+{ call [0-9a-f]+ <\.L\.myfn\.0> }
#...
000[0-9a-f]+ <\.L\.myfn\.0>:

#...
Disassembly.+\.text2:

00001000 <main>:
 +1000:[\s0-9a-f]+{ allocframe.*
 +1004:[\s0-9a-f]+{ call [0-9a-f]+ <myfn> }
#...

008[0-9a-f]+ <myfn>:
#...
