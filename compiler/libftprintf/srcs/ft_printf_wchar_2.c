/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:04:57 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 18:58:40 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** this fct will take the unicode mask then fill it with the binary
** number of the wanted wchar.
*/

static char		*ft_unicod_fill_2(char *result, int i, int j, char *wchar)
{
	while ((i >= 0) && (j >= 0))
	{
		if (result[i] == 'x')
		{
			result[i] = wchar[j];
			j--;
		}
		i--;
	}
	return (result);
}

char			*ft_unicod_fill(char *wchar, char *unicod_mask)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = ft_memalloc(ft_strlen(unicod_mask));
	while (i <= (int)ft_strlen(unicod_mask))
	{
		result[i] = unicod_mask[i];
		i++;
	}
	result[i] = '\0';
	i = ft_strlen(unicod_mask) - 1;
	j = ft_strlen(wchar) - 1;
	result = ft_unicod_fill_2(result, i, j, wchar);
	i = ft_strlen(unicod_mask);
	while (i >= 0)
	{
		if (result[i] == 'x')
			result[i] = '0';
		i--;
	}
	free(wchar);
	return (result);
}
