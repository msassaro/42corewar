/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_guil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 10:31:15 by fpasquer          #+#    #+#             */
/*   Updated: 2016/03/30 08:54:51 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char					**end_split(char **tab, char *s, char c)
{
	char					**ret_s;
	char					**ret;

	if (tab == NULL)
		return (ft_strsplit(s, c));
	if ((ret_s = ft_strsplit(s, c)) == NULL)
		return (NULL);
	ret = join_2_tabs_2d(tab, ret_s);
	ft_free_strsplit(tab);
	ft_free_strsplit(ret_s);
	return (ret);
}

static char					**loop(char ***add, char ***ret, char ***tmp,
		char **s)
{
	if ((*add = join_2_tabs_2d(*ret, *tmp)) == NULL)
		return (NULL);
	if (*ret != NULL)
		ft_free_strsplit(*ret);
	if ((*ret = join_tab2d_str(*add, *s, TAIL)) == NULL)
		return (NULL);
	ft_free_strsplit(*tmp);
	ft_free_strsplit(*add);
	return (*ret);
}

char						**join_tab2d_str(char **tab, char *str, int where)
{
	char					**ret;
	unsigned int			y;
	unsigned int			j;
	unsigned int			len_y_tab;

	len_y_tab = tab == NULL ? 0 : len_y(tab);
	if ((ret = ft_memalloc(sizeof(char *) * (len_y_tab + 2))) == NULL)
		return (NULL);
	y = 0;
	j = 0;
	if (where == HEAD)
		if ((ret[y + j++] = ft_strdup(str)) == NULL)
			return (NULL);
	if (tab != NULL)
		while (tab[y] != NULL)
		{
			if ((ret[y + j] = ft_strdup(tab[y])) == NULL)
				return (NULL);
			y++;
		}
	if (where == TAIL)
		if ((ret[y + j++] = ft_strdup(str)) == NULL)
			return (NULL);
	return (ret);
}

char						**join_2_tabs_2d(char **tab1, char **tab2)
{
	char					**ret;
	unsigned int			y1;
	unsigned int			y2;
	unsigned int			i;
	unsigned int			j;

	y1 = tab1 == NULL ? 0 : len_y(tab1);
	y2 = tab2 == NULL ? 0 : len_y(tab2);
	if ((ret = ft_memalloc(sizeof(char *) * (y1 + y2 + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (tab1 != NULL)
		while (tab1[i] != NULL)
			if ((ret[j++] = ft_strdup(tab1[i++])) == NULL)
				return (NULL);
	i = 0;
	if (tab2 != NULL)
		while (tab2[i] != NULL)
			if ((ret[j++] = ft_strdup(tab2[i++])) == NULL)
				return (NULL);
	return (ret);
}

char						**ft_strsplit_guil(char *s, char c)
{
	char					*start;
	char					*end;
	char					**tmp;
	char					**add;
	char					**ret;

	ret = NULL;
	while (*s != '\0')
	{
		end = NULL;
		if ((start = ft_strchr(s, '\"')) != NULL)
			end = ft_strchr(start + 1, '\"');
		if (end == NULL)
			return (end_split(ret, s, c));
		*start = '\0';
		if ((tmp = ft_strsplit(s, c)) == NULL)
			return (NULL);
		s = start + 1;
		*end = '\0';
		if ((ret = loop(&add, &ret, &tmp, &s)) == NULL)
			return (NULL);
		s = end + 1;
	}
	return (ret == NULL ? ft_strsplit(s, c) : ret);
}
