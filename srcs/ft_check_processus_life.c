#include "../incs/corewar.h"

static void					ft_delete_processus(t_vm *vm, t_player **plr)
{
	t_player				*actuel;

	ft_memcpy(&vm->last_del, *plr, sizeof(t_player));
	if ((actuel = *plr) == vm->plr)
	{
		vm->plr = actuel->next;
		*plr = vm->plr;
		if (*plr)
			(*plr)->prev = NULL;
	}
	else if (actuel->next)
	{
		(*plr) = (*plr)->next;
		actuel->prev->next = (*plr);
		(*plr)->prev = actuel->prev;
	}
	else if (!actuel->next)
	{
		actuel->prev->next = NULL;
		ft_memdel((void**)plr);
		vm->nb_proces--;
		return ;
	}
	ft_memdel((void**)&actuel);
	vm->nb_proces--;
}

static void					ft_reset_live(t_player *plr, t_vm *vm)
{
	int						i;

	i = 0;
	while (i < vm->count_pos)
	{
		vm->nb_live_each_plr[i] = 0;
		i++;
	}
	while (plr)
	{
		if (plr->nb_live <= 0)
			ft_delete_processus(vm, &plr);
		else
		{
			plr->last_live = plr->nb_live;
			plr->nb_live = 0;
			plr = plr->next;
		}
		if (!vm->nb_proces)
			break ;
	}
}

static int					ft_count_all_processus_live(t_vm *vm)
{
	int						i;

	i = vm->nb_live_each_plr[0];
	i += vm->nb_live_each_plr[1];
	i += vm->nb_live_each_plr[2];
	i += vm->nb_live_each_plr[3];
	return (i);
}

void						ft_check_processus_life(t_vm *vm)
{
	int						count_live;

	count_live = ft_count_all_processus_live(vm) + vm->nb_live;
	if (count_live >= 21 && !(vm->check_max = 0))
		vm->cycle_to_die -= 50;
	else
	{
		vm->check_max++;
		if (vm->check_max == 10)
		{
			vm->cycle_to_die -= 50;
			vm->check_max = 0;
		}
	}
	ft_reset_live(vm->plr, vm);
	vm->nb_live = 0;
}
