#include "../incs/corewar.h"
#include "../incs/virtual_machine.h"

t_player					*get_winner2(t_vm *vm)
{
	unsigned int			i;
	unsigned int			j;

	i = 0;
	j = 0;
	if (vm->nb_proces == 0)
		return (&vm->last_del);
	while (i < vm->nb_player)
		if (vm->cycle_last_live[j] < vm->cycle_last_live[i++])
			j = i - 1;
	return (&vm->base[j]);
}
