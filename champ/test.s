.name "_1"
.comment "qs"
l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %11231
		zjmp %:live
