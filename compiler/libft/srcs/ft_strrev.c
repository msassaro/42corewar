/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/01 09:26:48 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		j;
	char	keeper;

	j = 0;
	len = ft_strlen(str);
	if (str)
	{
		while (j < len / 2)
		{
			keeper = str[j];
			str[j] = str[len - j - 1];
			str[len - j - 1] = keeper;
			j++;
		}
	}
	return (str);
}
