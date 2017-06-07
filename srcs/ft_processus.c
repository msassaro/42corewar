#include "../incs/corewar.h"

t_instruction g_instruction[] = {
	{0, NULL, 0},
	{1, ft_live, 4},
	{2, ft_ld, 4},
	{3, ft_st, 4},
	{4, ft_add, 4},
	{5, ft_sub, 4},
	{6, ft_and, 4},
	{7, ft_or, 4},
	{8, ft_xor, 4},
	{9, ft_zjmp, 2},
	{10, ft_ldi, 2},
	{11, ft_sti, 2},
	{12, ft_fork, 2},
	{13, ft_ld, 4},
	{14, ft_ldi, 2},
	{15, ft_lfork, 2},
	{16, ft_aff, 4},
	{-1, NULL, 0},
};

int							ft_processus_instruction(t_vm *vm, t_player *plr)
{
	int						i;

	i = 1;
	if (plr->instruction < 1 || plr->instruction > 16)
	{
		ft_nothing(vm, plr);
		plr->instruction = 0;
		return (0);
	}
	while (g_instruction[i].instruction > 0)
	{
		if (g_instruction[i].instruction == plr->instruction)
		{
			plr->info.instruction = plr->instruction;
			plr->info.epd = g_instruction[i].epd;
			g_instruction[i].p(vm, plr);
			plr->instruction = 0;
			break ;
		}
		i++;
	}
	return (0);
}

void						ft_check_processus(t_vm *vm)
{
	t_player				*tmp;

	tmp = vm->plr;
	while (tmp)
	{
		ft_check_delais(vm, tmp);
		if (tmp->delais == 0 && tmp->do_instruction == 1)
			ft_processus_instruction(vm, tmp);
		tmp = tmp->next;
	}
}

void						ft_processus(t_vm *vm)
{
	if (vm->cycle_tmp == vm->cycle_to_die)
	{
		ft_check_processus_life(vm);
		vm->cycle_tmp = 0;
	}
	ft_check_processus(vm);
}
