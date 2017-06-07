#include "asm.h"

/*
** On va chercher dans tous les items si on trouve le label correspondant.
** si c'est pas le cas error.
*/

int		ft_get_label_addr(t_env *e, char *label)
{
	t_item	*item;
	t_cmd	*tmp;

	tmp = e->cmd;
	while (tmp)
	{
		item = tmp->item;
		if ((item->type & LAB) && ft_strequ(item->word, label))
			return (tmp->addr);
		tmp = tmp->next;
	}
	return (-1);
}

t_label	*ft_create_label(t_item *item, t_cmd *cmd)
{
	t_label		*l;
	static int	nb;

	if (!(l = (t_label*)ft_memalloc(sizeof(t_label))))
		ft_strerror("malloc label in %s", "create_label");
	l->word = item->word;
	l->addr = cmd->addr;
	l->nb = cmd->nb;
	l->next = NULL;
	nb++;
	return (l);
}

void	ft_push_label(t_item *item, t_env *e, t_cmd *cmd)
{
	t_label		*l;
	t_label		*to_add;

	l = e->label;
	to_add = ft_create_label(item, cmd);
	if (to_add)
	{
		if (l)
		{
			while (l->next)
				l = l->next;
			l->next = to_add;
		}
		else
			e->label = to_add;
	}
}

/*
** on va set le code du label a l'addr du cmd correspondant.
** relativement au cmd en cours.
*/

void	ft_set_labels_addr(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;
	int		addr;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type & LAB)
				ft_push_label(item, e, cmd);
			if (item->type & T_LAB)
			{
				if ((addr = ft_get_label_addr(e, item->word)) == -1)
					ft_strerror("label %s doesnt exists", item->word);
				item->code = addr - cmd->addr;
			}
			item = item->next;
		}
		cmd = cmd->next;
	}
}
