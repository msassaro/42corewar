/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:58:03 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/16 10:44:25 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"
#include "../incs/virtual_machine.h"

int							ft_st(t_vm *vm, t_player *plr)
{
	int						i;

	ft_parse_info(vm, plr);
	if (plr->info.error == ERROR_REG)
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param);
	else if (plr->info.error == ERROR_OCP)
		plr->i_grid = (plr->i_grid + plr->info.size_ocp_param + 2) %
			NB_CASE_TAB;
	else if (plr->info.t_s_param == T_REG)
	{
		plr->reg[plr->info.reg_s] = plr->info.nb_f_param;
		plr->i_grid = (plr->i_grid + 2 + plr->info.size_ocp_param) %
			NB_CASE_TAB;
	}
	else
	{
		i = get_new_index_with_mod(plr->info.nb_s_param, plr->i_grid, vm);
		ft_print_param_to_array_4_octets(vm, plr, i, plr->reg[plr->info.reg_f]);
		plr->i_grid = get_new_index_with_mod(plr->info.size_ocp_param + 2,
				plr->i_grid, vm);
	}
	plr->do_instruction = 0;
	ft_bzero(&plr->info, sizeof(t_info));
	return (0);
}
