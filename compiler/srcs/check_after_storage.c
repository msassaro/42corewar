#include "asm.h"

/*
** here we will check if the collected items are correct. If they are not
** --> error.
*/

void	ft_check_item_after_storage(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type == LAB && !ft_islabel(item->word))
				ft_itmerr("error label", item);
			else if (item->type == OP && !ft_isop(item->word, e))
				ft_itmerr("error instruction", item);
			else if (item->type == PARAM && !ft_isparam(item))
				ft_itmerr("error param", item);
			else if (!(item->type & (OP | PARAM | LAB)))
				ft_itmerr("wrong word", item);
			item = item->next;
		}
		cmd = cmd->next;
	}
}

/*
** Here we check if the params correspond to the operations.
** If we have a param of wrong type for a certain operation --> error.
*/

void	ft_check_param_type_per_op2(t_item *item, int j, t_env *e)
{
	t_op	op;

	op = ft_getop_name(item->word, e);
	if (op.name == 0)
		ft_itmerr("wrong instruction", item);
	while (item)
	{
		if (item->type & PARAM && !(op.type_param[j++] & item->type))
			ft_itmerr("unexpected parameter", item);
		item = item->next;
	}
	if (j != op.nb_param)
		ft_strerror("wrong number of param", "");
}

void	ft_check_param_type_per_op(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;
	int		j;

	cmd = e->cmd;
	while (cmd)
	{
		j = 0;
		item = cmd->item;
		if (!(item->type & OP))
		{
			if (!(item = item->next))
			{
				cmd = cmd->next;
				continue ;
			}
		}
		ft_check_param_type_per_op2(item, j, e);
		cmd = cmd->next;
	}
}
