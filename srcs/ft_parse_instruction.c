/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:49:38 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/20 12:13:07 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

static void					ft_stock_hexa_to_array(t_array *array,
		unsigned char *str, int size)
{
	int						i;

	i = 0;
	while (i < size)
	{
		array[i].code_hexa = str[i];
		i++;
	}
}

static int					ft_name_instruction(char instruction,
		t_array *array)
{
	if (instruction == LD || instruction == AND || instruction == OR
			|| instruction == XOR || instruction == LLD)
	{
		array->code_hexa = instruction;
		return (4);
	}
	else if (instruction == ST || instruction == ADD || instruction == SUB
			|| instruction == LDI || instruction == STI || instruction == LLDI
				|| instruction == AFF)
	{
		array->code_hexa = instruction;
		return (2);
	}
	array->code_hexa = instruction;
	return (instruction);
}

static void					ft_instruction_type(int tmp, int i, int *size_param)
{
	if (tmp == 3)
		tmp--;
	else if (i == 4 && tmp == 2)
		tmp = i;
	if (tmp > 0)
		*size_param += tmp;
}

static int					ft_ocp_instruction(unsigned char *str, int i,
		t_array *array)
{
	unsigned char			tmp;
	int						size_param;

	size_param = 0;
	tmp = *str >> 6;
	ft_instruction_type(tmp, i, &size_param);
	tmp = (*str & MASK_6_BITS) >> 4;
	ft_instruction_type(tmp, i, &size_param);
	tmp = (*str & MASK_4_BITS) >> 2;
	ft_instruction_type(tmp, i, &size_param);
	array->code_hexa = *str;
	ft_stock_hexa_to_array(&array[1], &str[1], size_param);
	return (size_param);
}

/*
** Preminer byte contient le nom de l'instruction
** Dexieme byte contient les types de parametres
** si l'instruction est autre que zjmp & fork
*/

int							ft_parse_instruction(char *str, t_array *array)
{
	int						i;

	i = ft_name_instruction(str[0], array);
	if (i <= 4 && i != LIVE)
	{
		i = ft_ocp_instruction((unsigned char*)&str[1], i, &array[1]);
		return (i + 2);
	}
	else if (i == ZJMP || i == FORK || i == LFORK)
	{
		ft_stock_hexa_to_array(&array[1], (unsigned char*)&str[1], 2);
		return (3);
	}
	ft_stock_hexa_to_array(&array[1], (unsigned char *)&str[1], 4);
	return (5);
}
