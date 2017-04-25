/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:06:02 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/25 10:51:29 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function will look at a received char *str. It will remove all the
** multi c and replace it by only one c.
*/

static int		ft_nb_remove(char *tmp, char c)
{
	int		i;
	int		c_to_remove;

	i = 0;
	c_to_remove = 0;
	while (tmp[i])
	{
		while (tmp[i] != c && tmp[i])
			i++;
		while (tmp[i] == c && tmp[i])
		{
			if (tmp[i - 1] == c)
				c_to_remove++;
			i++;
		}
	}
	return (c_to_remove);
}

static char		*ft_mallocage(char *str, char c)
{
	int		len;
	int		c_to_remove;
	char	*tmp;

	len = ft_strlen(str);
	c_to_remove = ft_nb_remove(str, c);
	if (c_to_remove == 0)
		return (NULL);
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * (len - c_to_remove + 1))))
		return (NULL);
	return (tmp);
}

char			*ft_remove_white_spaces(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_strtrim(str);
	if (!(tmp = ft_mallocage(str, c)))
		return (str);
	while (str[i])
	{
		if (str[i] != c)
			tmp[j++] = str[i];
		else if (str[i] == c && str[i - 1] != c)
			tmp[j++] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
