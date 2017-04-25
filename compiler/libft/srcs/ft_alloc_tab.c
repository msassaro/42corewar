/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:38:51 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/01 15:38:53 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_alloc_tab(int i, int j)
{
	char	**tab;
	int		index;

	index = 0;
	tab = (char**)malloc(sizeof(char*) * (i + 1));
	while (index < i)
	{
		tab[index] = (char*)ft_memalloc(sizeof(char*) * (j + 1));
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
