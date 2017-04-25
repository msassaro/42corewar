/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:11:52 by jchen             #+#    #+#             */
/*   Updated: 2016/06/19 20:08:05 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

t_ocp g_ocp[] = {
	{0, ft_param_0_octet},
	{1, ft_param_1_octets},
	{2, ft_param_4_octets},
	{3, ft_param_4_octets},
	{4, ft_param_4_octets},
};

t_ocp_param g_ocp_param[] = {
	{0, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0},
	{LIVE, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1},
	{LD, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, 2},
	{ST, {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 0, 0, 0}, 2},
	{ADD, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, 3},
	{SUB, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, 3},
	{AND, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 0, 0}, 3},
	{OR, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 0, 0}, 3},
	{XOR, {0, 1, 1, 1}, {0, 1, 1, 1}, {0, 1, 0, 0}, 3},
	{ZJMP, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1},
	{LDI, {0, 1, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 0}, 3},
	{STI, {0, 1, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 0}, 3},
	{FORK, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1},
	{LLD, {0, 0, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}, 2},
	{LLDI, {0, 1, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 0}, 3},
	{LFORK, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1},
	{AFF, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1},
};

static void					ft_instruction_type(int tmp, int i, int *size,
								int *size_param)
{
	if (tmp == 3)
		tmp--;
	else if (i == 4 && tmp == 2)
		tmp = i;
	if (tmp > 0)
	{
		*size_param = tmp;
		*size += tmp;
	}
}

static int					ft_ocp_instruction(unsigned char str, int i,
		t_info *info)
{
	unsigned char			tmp;
	int						size;

	size = 0;
	tmp = str >> 6;
	info->t_f_param = tmp;
	if (g_ocp_param[info->instruction].nb_param >= 1)
		ft_instruction_type(tmp, i, &size, &info->s_f_param);
	tmp = (str & MASK_6_BITS) >> 4;
	info->t_s_param = tmp;
	if (g_ocp_param[info->instruction].nb_param >= 2)
		ft_instruction_type(tmp, i, &size, &info->s_s_param);
	tmp = (str & MASK_4_BITS) >> 2;
	info->t_t_param = tmp;
	if (g_ocp_param[info->instruction].nb_param == 3)
		ft_instruction_type(tmp, i, &size, &info->s_t_param);
	return (size);
}

void						ft_check_ocp(t_info *info, t_vm *vm)
{
	int						i;

	i = 0;
	if (g_ocp_param[info->instruction].f_p[info->t_f_param])
	{
		info->size_ocp_param2 += info->s_f_param;
		i++;
	}
	if (g_ocp_param[info->instruction].s_p[info->t_s_param])
	{
		info->size_ocp_param2 += info->s_s_param;
		i++;
	}
	if (g_ocp_param[info->instruction].t_p[info->t_t_param])
	{
		info->size_ocp_param2 += info->s_t_param;
		i++;
	}
	if (g_ocp_param[info->instruction].nb_param != i)
		info->error = ERROR_OCP;
	vm->ff = 0;
}

void						ft_parse_info_bin(t_vm *vm, t_player *plr,
								t_info *tmp)
{
	tmp->nb_f_param = tmp->t_f_param == T_IND ?
		ft_indirect_param(vm, plr, tmp->nb_f_param) : tmp->nb_f_param;
	tmp->nb_s_param = tmp->t_s_param == T_IND ?
		ft_indirect_param(vm, plr, tmp->nb_s_param) : tmp->nb_s_param;
	tmp->nb_t_param = tmp->t_t_param == T_IND ?
		ft_indirect_param(vm, plr, tmp->nb_t_param) : tmp->nb_t_param;
}

void						ft_parse_info(t_vm *vm, t_player *plr)
{
	t_info					*tmp;

	tmp = &plr->info;
	tmp->index_ocp = (plr->i_grid + 1) % NB_CASE_TAB;
	tmp->ocp = vm->array[tmp->index_ocp].code_hexa;
	tmp->size_ocp_param = ft_ocp_instruction(tmp->ocp, tmp->epd, tmp);
	tmp->index_f_param = (tmp->index_ocp + 1) % NB_CASE_TAB;
	tmp->index_s_param = (tmp->index_ocp + tmp->s_f_param + 1) % NB_CASE_TAB;
	tmp->index_t_param = (tmp->index_ocp + tmp->s_f_param +
			tmp->s_s_param + 1) % NB_CASE_TAB;
	ft_check_ocp(tmp, vm);
	if (tmp->error)
		return ;
	tmp->nb_f_param = g_ocp[tmp->t_f_param].p(vm, plr, tmp->s_f_param,
			tmp->index_f_param);
	tmp->nb_s_param = g_ocp[tmp->t_s_param].p(vm, plr, tmp->s_s_param,
			tmp->index_s_param);
	tmp->nb_t_param = g_ocp[tmp->t_t_param].p(vm, plr, tmp->s_t_param,
			tmp->index_t_param);
	if (plr->instruction != ST && plr->instruction != ZJMP)
		ft_parse_info_bin(vm, plr, tmp);
}
