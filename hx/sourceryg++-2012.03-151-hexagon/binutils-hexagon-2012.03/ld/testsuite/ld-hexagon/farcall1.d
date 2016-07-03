#name: hexagon farcall via trampoline
#source: farcall1.s
#as: -march=hexagonv4
#ld:
#objdump: -d

#...
000[0-9a-f]+ <\.L\.puts\.0>:
 +[0-9a-f]+:[\s0-9a-f]+{ immext .*
 +[0-9a-f]+:[\s0-9a-f]+ jump [0-9a-f]+ <puts> }

#...
008[0-9a-f]+ <FarFunction1>:
#...
 +[0-9a-f]+:[\s0-9a-f]+ { call [0-9a-f]+ <\.L\.puts\.1> }

#...
008[0-9a-f]+ <\.L\.puts\.1>:
 +[0-9a-f]+:[\s0-9a-f]+{ immext .*
 +[0-9a-f]+:[\s0-9a-f]+ jump [0-9a-f]+ <puts> }

#...
