/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_without_ocp.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:41:48 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/17 18:09:42 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_live(t_vm *vm, t_player *plr)
{
	int						i;
	int						count;
	int						found;

	found = 0;
	count = 0;
	i = ft_param_4_octets(vm, plr, 4, (plr->i_grid + 1) % 4096);
	plr->nb_live++;
	if (plr->reg[1] == (unsigned int)i)
		plr->cycle_last_live = vm->cycle;
	while (count < vm->count_pos)
	{
		if (i == vm->array_pos[count])
		{
			found = 1;
			vm->cycle_last_live[count] = vm->cycle;
			vm->nb_live_each_plr[count]++;
			break ;
		}
		count++;
	}
	if (!found)
		vm->nb_live++;
	plr->i_grid = (5 + plr->i_grid) % NB_CASE_TAB;
	return (0);
}

int							ft_zjmp(t_vm *vm, t_player *plr)
{
	short					i;

	i = ft_param_4_octets(vm, plr, 2, plr->i_grid + 1);
	if (plr->carry)
		plr->i_grid = get_new_index_with_mod(i, plr->i_grid, vm);
	else
		plr->i_grid = get_new_index_with_mod(3, plr->i_grid, vm);
	return (0);
}
