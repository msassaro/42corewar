#include "../incs/virtual_machine.h"

void						ft_stock_n_player(t_vm *vm, t_player *plr)
{
	t_player				*tmp;
	int						i;

	i = 0;
	tmp = plr;
	while (plr)
	{
		vm->count_pos++;
		plr = plr->next;
	}
	vm->array_pos = (int*)malloc(sizeof(int) * vm->count_pos);
	plr = tmp;
	while (plr)
	{
		vm->array_pos[i] = plr->reg[1];
		plr = plr->next;
		i++;
	}
}

int							main(int argc, char **argv)
{
	t_vm				*vm;

	if (argc < 2)
		error("Champions ar missing");
	if ((vm = init_vm(argc, argv)) == NULL)
		error("Initiation error");
	ft_stock_n_player(vm, vm->plr);
	loop_virtual_machin(vm);
	del_vm(&vm);
	return (0);
}
