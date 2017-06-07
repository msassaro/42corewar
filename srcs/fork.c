#include "../incs/corewar.h"
#include "../incs/virtual_machine.h"

t_player					*copy_with_the_new_index(t_player *plr,
		t_player **lst, int i_grid, t_vm *vm)
{
	t_player				*new;

	if (lst == NULL || *lst == NULL || plr == NULL ||
			(new = ft_memalloc(sizeof(t_player))) == NULL)
		return (NULL);
	ft_memcpy(new, plr, sizeof(t_player));
	if ((new->name = ft_strdup(plr->name)) == NULL)
		return (NULL);
	if ((new->comment = ft_strdup(plr->comment)) == NULL)
		return (NULL);
	new->i_grid = (plr->instruction == FORK) ? get_new_index_with_mod(i_grid,
			plr->i_grid, vm) : get_new_index(i_grid, plr->i_grid, vm);
	new->next = *lst;
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
	vm->nb_proces++;
	new->do_instruction = 0;
	new->instruction = 0;
	plr->do_instruction = 0;
	wrefresh(vm->w_info);
	return (new);
}

int							ft_fork(t_vm *vm, t_player *plr)
{
	int						adr;

	if (vm == NULL || plr == NULL)
		return (-1);
	adr = (ft_param_4_octets(vm, plr, 2, (plr->i_grid + 1) % NB_CASE_TAB)
			% 512);
	if (copy_with_the_new_index(plr, &vm->plr, adr, vm) == NULL)
		return (-1);
	plr->i_grid = (plr->i_grid + 3) % NB_CASE_TAB;
	return (0);
}

int							ft_lfork(t_vm *vm, t_player *plr)
{
	int						adr;

	if (vm == NULL || plr == NULL)
		return (-1);
	adr = ft_param_4_octets(vm, plr, 2, (plr->i_grid + 1) % NB_CASE_TAB);
	if (copy_with_the_new_index(plr, &vm->plr, adr, vm) == NULL)
		return (-1);
	plr->i_grid = (plr->i_grid + 3) % NB_CASE_TAB;
	return (0);
}
