#include "asm.h"

int		ft_line_count(t_env *e)
{
	int		count;
	t_cmd	*cmd;

	cmd = e->cmd;
	count = 0;
	while (cmd)
	{
		if (cmd->line)
			count++;
		cmd = cmd->next;
	}
	return (count);
}
