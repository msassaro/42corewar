/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:53:29 by msassaro          #+#    #+#             */
/*   Updated: 2016/06/20 11:40:43 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Here we will look at each line we have stored into the linked-list.
** If line == NULL or is useless, then we delete the line from the list.
*/

void	ft_remove_useless_lines(t_env *e)
{
	t_cmd			*tmp;
	t_cmd			*keep;

	tmp = e->cmd;
	while (tmp)
	{
		keep = tmp->next;
		if ((tmp->line == NULL || ft_isuselessstr(tmp->line)))
			ft_delete_e_cmd(e, tmp);
		tmp = tmp->next;
	}
}

/*
** Here we are gonna format the str as we want it to be, before storage into
** line->str.
** .
** If the line is too long --> error.
** Then we just remove the comments by replacing COMMENT_CHAR by '\0'
*/

char	*ft_format_str(char *str, int line_nb)
{
	int		i;

	i = 0;
	if (str != NULL)
	{
		if ((int)ft_strlen(str) > LINE_LENGHT)
			ft_interror("(Norme) the line %d is too long", line_nb);
		while (str[i])
		{
			if (str[i] == COMMENT_CHAR || str[i] == COMMENT_CHAR_2)
			{
				str[i] = '\0';
				break ;
			}
			i++;
		}
	}
	return (str);
}

/*
** Here we will malloc a t_line structure and we will init its values.
** If there is an issue --> error.
** .
** We will return the freshly created t_line.
*/

t_cmd	*ft_create_cmd(char *line, int i)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)ft_memalloc(sizeof(t_cmd))))
		ft_strerror("[ft_create_line] malloc cmd", "");
	cmd->line = ft_strdup(ft_format_str(line, i));
	cmd->nb = i;
	cmd->size = 0;
	cmd->encode = 0;
	cmd->bin = NULL;
	cmd->next = NULL;
	return (cmd);
}

/*
** Here we will see if the linked list e->line is empty or not.
** .
** Then we create a t_line structure and we push it at the end of
** the e->line linked-list.
*/

void	ft_push_line(t_env *e, char *line, int i)
{
	t_cmd	*to_add;
	t_cmd	*l;

	to_add = ft_create_cmd(line, i);
	if (to_add)
	{
		l = e->cmd;
		if (l)
		{
			while (l->next)
				l = l->next;
			l->next = to_add;
		}
		else
			e->cmd = to_add;
	}
}

/*
** Here we will check if the file exists and if there is an issue when reading
** it. Otherwise, we just simply push the content into e->line linked list.
** We will have:
** e->line:
** e->line->str = "bla bla bla"
** e->line->nb = nb of the line.
** e->line->next = addr of the next line.
*/

void	ft_read_file(char *av, t_env *e)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 1;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_strerror("file \"%s\" does not exists", av);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_push_line(e, line, i);
		i++;
		free(line);
	}
	if (ret == -1)
		ft_strerror("an issue occured when tried to open %s", av);
	if (i <= 1 || ft_line_count(e) <= 0)
		ft_strerror("File %s is empty", av);
	ft_remove_useless_lines(e);
}
