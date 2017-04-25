/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_malloc_plus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:13 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 16:57:14 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_malloc_plus(char *str, int size, char c)
{
	char	*tmp;
	int		len_str;
	int		i;

	i = 0;
	len_str = ft_strlen(str);
	if (len_str >= size)
		return (str);
	if ((tmp = ((char*)malloc(sizeof(char) * size + 1))) == NULL)
		return (NULL);
	ft_memset(tmp, c, size);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[size] = '\0';
	free(str);
	return (tmp);
}
