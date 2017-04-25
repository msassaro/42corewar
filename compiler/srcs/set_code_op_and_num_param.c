/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_code_op_and_num_param.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:25:12 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/25 13:33:51 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Here we will set the code that correspond to each item.
** .
** For the operations, we will look into the e->op to check which is the
** corresponding opcode.
** For params, if its a register or a direct --> we take the value for code.
*/

void	ft_set_code_to_op_and_num_param(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;
	t_op	op;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type == OP)
			{
				op = ft_getop_name(item->word, e);
				if (ft_strequ(item->word, op.name))
					item->code = op.opcode;
			}
			else if ((item->type & PARAM) == PARAM)
				if ((item->type & T_REG) == T_REG || !(item->type & T_LAB))
					item->code = ft_atoi(item->word);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
