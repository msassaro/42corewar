/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:11:27 by jchen             #+#    #+#             */
/*   Updated: 2016/06/18 15:11:29 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_aff(t_vm *vm, t_player *plr)
{
	ft_parse_info(vm, plr);
	plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) % 4096;
	ft_bzero(&plr->info, sizeof(t_info));
	plr->do_instruction = 0;
	return (0);
}

int							ft_ld(t_vm *vm, t_player *plr)
{
	ft_parse_info(vm, plr);
	if (plr->info.error == ERROR_REG)
		plr->i_grid = get_new_index_with_mod(2 + plr->info.size_ocp_param,
				plr->i_grid, vm);
	else if (plr->info.error == ERROR_OCP)
		plr->i_grid = (plr->i_grid + plr->info.size_ocp_param + 2) %
			NB_CASE_TAB;
	else
	{
		plr->reg[plr->info.reg_s] = plr->info.nb_f_param;
		plr->carry = plr->reg[plr->info.reg_s] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_sti(t_vm *vm, t_player *plr)
{
	int						i;

	ft_parse_info(vm, plr);
	if (plr->info.error == ERROR_REG)
		plr->i_grid = get_new_index_with_mod(2 + plr->info.size_ocp_param,
				plr->i_grid, vm);
	else if (plr->info.error == ERROR_OCP)
		plr->i_grid = (plr->i_grid + plr->info.size_ocp_param + 2) %
			NB_CASE_TAB;
	else
	{
		i = plr->info.nb_s_param + plr->info.nb_t_param;
		i = get_new_index_with_mod(i, plr->i_grid, vm);
		ft_print_param_to_array_4_octets(vm, plr, i, plr->reg[plr->info.reg_f]);
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_ldi(t_vm *vm, t_player *plr)
{
	int						i;

	ft_parse_info(vm, plr);
	if (plr->info.error == ERROR_REG)
		plr->i_grid = get_new_index_with_mod(2 + plr->info.size_ocp_param,
				plr->i_grid, vm);
	else if (plr->info.error == ERROR_OCP)
		plr->i_grid = (plr->i_grid + plr->info.size_ocp_param + 2) %
			NB_CASE_TAB;
	else
	{
		i = plr->info.nb_f_param + plr->info.nb_s_param;
		i = ft_indirect_param(vm, plr, i);
		plr->reg[plr->info.reg_t] = i;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	if (plr->instruction == LLDI)
		plr->carry = (plr->reg[plr->info.reg_t]) ? 0 : 1;
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_nothing(t_vm *vm, t_player *plr)
{
	plr->i_grid = (plr->i_grid + 1) % NB_CASE_TAB;
	vm->ff = 0;
	return (0);
}
