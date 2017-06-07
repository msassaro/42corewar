.name "my_champ"
.comment "tatatata"

entry:
		zjmp %-45
		sti r1, %:stay_alive, %1
		ld %0, r16
		fork %:attack

stay_alive:
		live %89
		zjmp %:stay_alive

attack:
		live %89
		zjmp %3
		fork %:attack

		live %89
