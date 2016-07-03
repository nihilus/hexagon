	.text
	.globl start
	.type start, @function
start:
	.org 0x000040c0
	.type	strict_aliasing_workaround, @function
strict_aliasing_workaround:
	allocframe(#16)
	memw(r30+#-12) = r0
	r0 = memw(r30+#-12)
	memw(r30+#-4) = r0
	r0 = memw(r30+#-4)
	dealloc_return
	.size	strict_aliasing_workaround, .-strict_aliasing_workaround
	.section	.rodata
.LC0:
	.string	"\nNearFunction\n"
	.text
	.p2align 2
	.globl NearFunction
	.type	NearFunction, @function
NearFunction:
	allocframe(#0)
	r0 = ##.LC0
	call puts
	dealloc_return
	.size	NearFunction, .-NearFunction
	.p2align 2
	.globl main
	.type	main, @function
main:
	allocframe(#8)
	memw(r30+#-4) = r0
	memw(r30+#-8) = r1
	call NearFunction
	call FarFunction1
	call FarFunction2
	r0 = #0
	dealloc_return
	.size	main, .-main

	.section .rodata
.LC10:
	.string "FarFunction1"

	.section .text.far,"ax",@progbits
	.org 0x007fffd0
	.globl FarFunction1
	.type FarFunction1, @function
FarFunction1:
	allocframe(#0)
	r0 = ##.LC10
	// The trampoline initially assigned to the following call will move
	// out of range as other trampolines are created.  This call must
	// be re-assigned to a different trampoline.
	call puts
	dealloc_return
	.size FarFunction1, .-FarFunction1


	.section .rodata
.LC11:
	.string "FarFunction2"

	.section .text.farther,"ax",@progbits
	.org 0x00800000
	.globl FarFunction2
	.type FarFunction2, @function
FarFunction2:
	allocframe(#0)
	r0 = ##.LC11
	call puts
	dealloc_return
	.size FarFunction2, .-FarFunction2

	.org 0x00804000
	.globl puts
	.type puts, @function
puts:
	{ r0 = #0
	  jumpr r31 }
	{ nop
	  nop }
	.size puts, .-puts
