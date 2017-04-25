/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:39:38 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/31 13:52:04 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Here we will set the size of the cmd.
** If the params are encoded (encode), we ass the size to it.
*/

void	ft_set_size_cmd2(t_item *item, t_cmd *cmd, t_env *e)
{
	t_op		op;

	if (item->type == OP)
	{
		op = ft_getop_name(item->word, e);
		cmd->size += CODESIZE_OP;
		if (op.encode)
			cmd->size += CODESIZE_ENCODE;
	}
	else if (item->type & T_REG)
		cmd->size += CODESIZE_REG;
	else if (item->type & T_IND || ((item->type & T_DIR) && op.idx))
		cmd->size += CODESIZE_IND;
	else if (item->type & T_DIR)
		cmd->size += CODESIZE_DIR;
}

void	ft_set_size_cmd(t_env *e)
{
	t_item		*item;
	t_cmd		*cmd;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			ft_set_size_cmd2(item, cmd, e);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
