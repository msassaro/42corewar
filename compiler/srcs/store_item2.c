#include "asm.h"

t_item	*ft_create_item(char *word, int type, t_cmd *cmd, int col)
{
	t_item	*item;

	if (!(item = (t_item*)ft_memalloc(sizeof(t_item))))
		ft_strerror("[create_item] malloc item", "");
	item->type = type;
	item->word = ft_strtrim(word);
	item->code = 0;
	item->next = NULL;
	item->line = ft_strdup(cmd->line);
	item->line_nb = cmd->nb;
	item->col = col;
	return (item);
}

void	ft_push_item(t_cmd *cmd, char *word, int type, int col)
{
	t_item	*it;
	t_item	*to_add;

	to_add = ft_create_item(word, type, cmd, col);
	it = cmd->item;
	if (to_add)
	{
		if (it)
		{
			while (it->next)
				it = it->next;
			it->next = to_add;
		}
		else
			cmd->item = to_add;
	}
}
