	.text
foo:
	{
		R2 = MEMUH(R4+#-2)
		R3 = MEMUH(R4++#2)
		IF !P0 JUMPR R31
		LOOP0(NextMBAddr_SEARCH_LOOP,R5)
	}
NextMBAddr_SEARCH_LOOP:
