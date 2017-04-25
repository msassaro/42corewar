/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/18 11:05:45 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_char(char *str, char c)
{
	char	*result;
	int		i;
	int		to_remove;
	int		len;
	int		j;

	if (!str || (len = (int)ft_strlen(str)) < 1)
		return (NULL);
	i = -1;
	j = 0;
	to_remove = 0;
	while (str[++i])
		if (str[i] == c)
			to_remove++;
	if (!(result = (char*)ft_memalloc(sizeof(char) * (len - to_remove + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] != c)
			result[j++] = str[i];
	return (result);
}
