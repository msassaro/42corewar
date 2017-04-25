/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_octets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:44:12 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/16 09:49:25 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_param_0_octet(t_vm *vm, t_player *plr,
		int octet, int index)
{
	vm->ff = 0;
	(void)plr;
	octet = 0;
	index = 0;
	return (0);
}

int							ft_param_1_octets(t_vm *vm, t_player *plr,
		int octet, int index)
{
	int						reg;

	reg = vm->array[index].code_hexa;
	if (reg < 1 || reg > 16)
	{
		plr->info.error = ERROR_REG;
		return (0);
	}
	plr->info.reg_f = plr->info.index_f_param == index ? reg : plr->info.reg_f;
	plr->info.reg_s = plr->info.index_s_param == index ? reg : plr->info.reg_s;
	plr->info.reg_t = plr->info.index_t_param == index ? reg : plr->info.reg_t;
	octet = 0;
	return (plr->reg[reg]);
}

void						ft_bin(char *str, char *tab, char *zero)
{
	if (ft_strlen(str) < 2)
	{
		ft_memset(zero, '0', sizeof(char) * 3);
		zero[1] = str[0];
		zero[2] = 0;
		ft_strcat(tab, zero);
	}
	else
		ft_strcat(tab, str);
}

int							ft_param_4_octets(t_vm *vm, t_player *plr,
		int octet, int index)
{
	char					*str;
	char					tab[9];
	char					zero[3];
	int						i;
	int						octet_save;

	i = 0;
	octet_save = octet;
	ft_bzero(tab, sizeof(char) * 9);
	while (octet-- > 0)
	{
		str = ft_itoa_base(vm->array[index].code_hexa, 16);
		ft_bin(str, tab, zero);
		index = (index + 1) % 4096;
		ft_strdel(&str);
	}
	ft_atoi_base(tab, 16, &i);
	(void)plr;
	return (octet_save == 2 ? (short)i : i);
}
