/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operand_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:11:37 by jchen             #+#    #+#             */
/*   Updated: 2016/06/18 15:11:38 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_add(t_vm *vm, t_player *plr)
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
		plr->reg[plr->info.reg_t] = plr->info.nb_f_param + plr->info.nb_s_param;
		plr->carry = plr->reg[plr->info.reg_t] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_sub(t_vm *vm, t_player *plr)
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
		plr->reg[plr->info.reg_t] = plr->info.nb_f_param - plr->info.nb_s_param;
		plr->carry = plr->reg[plr->info.reg_t] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_and(t_vm *vm, t_player *plr)
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
		plr->reg[plr->info.reg_t] = plr->info.nb_f_param & plr->info.nb_s_param;
		plr->carry = plr->reg[plr->info.reg_t] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_or(t_vm *vm, t_player *plr)
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
		plr->reg[plr->info.reg_t] = plr->info.nb_f_param | plr->info.nb_s_param;
		plr->carry = plr->reg[plr->info.reg_t] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}

int							ft_xor(t_vm *vm, t_player *plr)
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
		plr->reg[plr->info.reg_t] = plr->info.nb_f_param ^ plr->info.nb_s_param;
		plr->carry = plr->reg[plr->info.reg_t] ? 0 : 1;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}
