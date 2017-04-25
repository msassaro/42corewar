/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:18:45 by fpasquer          #+#    #+#             */
/*   Updated: 2016/03/08 09:54:13 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char			*save_line(char **buff)
{
	char		*adr;
	char		*line;
	char		*new_buff;

	if ((adr = ft_strchr((*buff), '\n')) == NULL)
		line = ft_strdup((*buff));
	else
		line = ft_strsub((*buff), 0, adr - (*buff));
	if ((new_buff = ft_strsub((*buff), (adr == NULL) ? ft_strlen(line) :
		ft_strlen(line) + 1, ft_strlen((*buff)))) == NULL)
		return (NULL);
	ft_memdel((void**)buff);
	(*buff) = new_buff;
	return (line);
}

static int			save_buff(int fd, char **buff)
{
	char	*adr;
	char	*tmp;
	char	mem[BUFF_SIZE + 1];
	int		count;

	adr = NULL;
	while (adr == NULL)
	{
		if ((count = read(fd, mem, BUFF_SIZE)) <= 0)
			return (count);
		mem[count] = '\0';
		if ((tmp = ft_strjoin((*buff), mem)) == NULL)
			return (-1);
		ft_memdel((void**)buff);
		(*buff) = tmp;
		adr = ft_strchr(mem, '\n');
	}
	return (1);
}

static int			add_file(int fd, t_file **lst, t_file **bloc)
{
	t_file		*new;

	if ((new = (t_file*)ft_memalloc(sizeof(t_file))) == NULL)
		return (-1);
	if ((save_buff(fd, &new->l)) == -1)
	{
		ft_memdel((void**)&new);
		return (-1);
	}
	if (new->l == NULL)
	{
		ft_memdel((void**)&new);
		return (0);
	}
	new->next = (*lst);
	new->fd = fd;
	new->nb_file = ((*lst) == NULL) ? 0 : (*lst)->nb_file + 1;
	(*lst) = new;
	(*bloc) = new;
	return (1);
}

static int			del_file(t_file **file, t_file *obj)
{
	t_file *tmp1;
	t_file *tmp2;
	t_file *tmp3;

	if (obj == NULL)
		return (-1);
	tmp1 = (*file);
	tmp2 = (*file);
	tmp3 = (*file);
	if ((*file) == obj)
		tmp1 = (*file)->next;
	else
	{
		while (tmp2 != obj)
		{
			tmp3 = tmp2;
			tmp2 = tmp2->next;
		}
		tmp3->next = tmp2->next;
	}
	ft_memdel((void**)&tmp2->l);
	ft_memdel((void**)&tmp2);
	(*file) = tmp1;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static t_file	*adr_file;
	t_file			*file;
	int				retour;

	file = adr_file;
	if (fd < 0 || line == NULL)
		return (-1);
	while (file != NULL)
	{
		if (file->fd == fd)
			break ;
		file = file->next;
	}
	if (file != NULL)
		if (save_buff(fd, &file->l) == -1)
			return (-1);
	if (file == NULL)
		if ((retour = add_file(fd, &adr_file, &file)) <= 0)
			return ((retour == 0) ? 0 : del_file(&adr_file, NULL));
	if (ft_strlen(file->l) == 0)
		return (del_file(&adr_file, file));
	if (((*line) = save_line(&file->l)) == NULL)
		return (-1);
	return (1);
}
