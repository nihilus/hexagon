	.text
	movhu (a2),d1
	movhu (8,a2),d1
	movhu (256,a2),d1
	movhu (131071,a2),d1
	movhu (8,sp),d1
	movhu (256,sp),d1
	movhu (131071,sp),d1
	movhu (d1,a1),d2
	movhu (32768),d1
	movhu (131071),d1
	movhu d1,(a2)
	movhu d1,(32,a2)
	movhu d1,(256,a2)
	movhu d1,(131071,a2)
	movhu d1,(32,sp)
	movhu d1,(32768,sp)
	movhu d1,(131071,sp)
	movhu d1,(d2,a2)
	movhu d1,(128)
	movhu d1,(131071)