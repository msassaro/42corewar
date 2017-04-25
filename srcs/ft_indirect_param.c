/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indirect_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:11:18 by jchen             #+#    #+#             */
/*   Updated: 2016/06/18 15:11:19 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int							ft_indirect_param(t_vm *vm, t_player *plr, int move)
{
	int						i;

	if (plr->instruction != LLD && plr->instruction != LLDI &&
			plr->instruction != LFORK)
		i = get_new_index_with_mod(move, plr->i_grid, vm);
	else
		i = get_new_index(move, plr->i_grid, vm);
	if (plr->instruction == STI || plr->instruction == LD ||
			plr->instruction == LDI || plr->instruction == LLDI)
		i = ft_param_4_octets(vm, plr, 4, i);
	else
		i = ft_param_4_octets(vm, plr, 2, i);
	return (i);
}
