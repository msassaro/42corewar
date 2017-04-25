/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_malloc_rplus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:19 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 16:57:20 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_malloc_rplus(char *str, int size, char c)
{
	char	*tmp;
	int		len_str;
	int		i;

	i = 0;
	len_str = ft_strlen(str);
	if (len_str >= size)
		return (str);
	if ((tmp = ((char*)malloc(sizeof(char) * size))) == NULL)
		return (NULL);
	ft_memset(tmp, c, size);
	while (str[i])
	{
		tmp[i + size - len_str] = str[i];
		i++;
	}
	tmp[size] = '\0';
	free(str);
	return (tmp);
}
