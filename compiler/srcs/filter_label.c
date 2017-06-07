#include "asm.h"

void	ft_remove_empty(t_env *e)
{
	t_item		*item;
	t_cmd		*cmd;
	int			count;

	count = 0;
	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		count = 0;
		while (item)
		{
			count++;
			item = item->next;
		}
		if (count == 0)
			ft_delete_e_cmd(e, cmd);
		cmd = cmd->next;
	}
}

void	ft_filter_remove_labels(t_env *e)
{
	t_item		*item;
	t_cmd		*cmd;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type & LAB)
				ft_delete_cmd_lab(cmd, item);
			item = item->next;
		}
		cmd = cmd->next;
	}
	ft_remove_empty(e);
}
