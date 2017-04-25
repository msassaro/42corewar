/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:43:06 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/17 14:43:41 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_free_strsplit(char **tab)
{
	unsigned int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		tab[y++] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
