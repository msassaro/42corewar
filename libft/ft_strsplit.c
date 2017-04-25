/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 08:27:44 by fpasquer          #+#    #+#             */
/*   Updated: 2016/01/22 09:57:44 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**save_tab(char **tab, const char *s, char c)
{
	char			*mem;
	unsigned int	y;
	unsigned int	i;

	i = 0;
	y = 0;
	mem = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c && mem == NULL)
			mem = (char*)&s[i];
		else if (s[i] == c && mem != NULL)
		{
			if ((tab[y++] = ft_strsub(s, mem - s, &s[i] - mem)) == NULL)
				return (ft_free_strsplit(tab));
			mem = NULL;
		}
		i++;
	}
	if (mem != NULL)
		if ((tab[y++] = ft_strsub(s, mem - s, &s[i] - mem)) == NULL)
			return (ft_free_strsplit(tab));
	return (tab);
}

char				**ft_strsplit(const char *s, char c)
{
	char			**tab;
	unsigned int	y;
	unsigned int	i;

	y = get_y(s, c);
	if ((tab = (char**)malloc(sizeof(*tab) * (y + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < y + 1)
		tab[i++] = NULL;
	return (save_tab(tab, s, c));
}
