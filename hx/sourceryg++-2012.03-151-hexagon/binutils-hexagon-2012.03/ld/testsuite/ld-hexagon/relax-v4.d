#as: -mv4
#ld: --defsym foo=0x10000000
#objdump: -d

.*:     file format .*


Disassembly of section .text:

 *[0-9a-f]*0 <start>:
 *[0-9a-f]*0:	06 c0 00 58 	5800c006     { jump [0-9a-f]*c <\.L\.foo\.0> }
 *[0-9a-f]*4:	00 c0 00 7f 	7f00c000     { nop }

 *[0-9a-f]*8 <\.L[0-9]+\.__jump_around_trampolines>:
 *[0-9a-f]*8:	06 c0 00 58 	5800c006     { jump [0-9a-f]*14 <\.L\.foo\.0\+0x8> }

 *[0-9a-f]*c <\.L\.foo\.0>:
 *[0-9a-f]*c:	bf 7f ff 00 	00ff7fbf     { immext \(#.*\)
 *[0-9a-f]*10:	68 c0 00 58 	5800c068       jump 10000000 <foo> }
