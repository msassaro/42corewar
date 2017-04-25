/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:53:20 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/20 10:53:40 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_islabel(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
	}
	return (1);
}

int		ft_isop(char *str, t_env *e)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (ft_strequ(str, e->op[i].name))
			return (1);
		i++;
	}
	return (0);
}

/*
** Here we check if its a good parameter
*/

int		ft_isreg_param(t_item *item)
{
	int		i;

	if (item->word[0] == 'r')
	{
		i = ft_atoi(item->word + 1);
		if (i < 0 || i > REG_NUMBER)
			return (0);
		item->type |= T_REG;
	}
	else
		return (0);
	return (1);
}

int		ft_isdir_param(char *s, t_item *item)
{
	if (*s == '%')
	{
		item->type |= T_DIR;
		return (1);
	}
	else
		item->type |= T_IND;
	return (0);
}

int		ft_isparam(t_item *item)
{
	char	*s;

	s = item->word;
	if (ft_isreg_param(item))
		s++;
	else
	{
		if (ft_isdir_param(s, item))
			s++;
		if (*s == ':')
		{
			s++;
			if (!ft_islabel(s))
				return (0);
			item->type |= T_LAB;
		}
		else if (!ft_str_digit(s))
			return (0);
	}
	item->word = ft_strdup(s);
	return (1);
}
