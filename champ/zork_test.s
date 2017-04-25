.name "zork"
.comment ",I'M ALIIIIVE"


#lfork %1024
#begin:
#	fork %:link_2
#	live %78
#	fork %:link_3

#link_2:
#	live %-1
#	fork %:begin

#link_3:
#	live %-2
#	ld 0, r16
#	zjmp %:link_ld %119537654, r6

ld %187695104,r6
st r6, 100
