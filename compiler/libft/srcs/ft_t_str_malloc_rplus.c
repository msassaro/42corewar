/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_str_malloc_rplus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:13 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 16:57:14 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_t_str_malloc_rplus(t_str *str, int size, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((tmp = ((char*)malloc(sizeof(char) * size))) == NULL)
		return (NULL);
	ft_memset(tmp, c, size);
	while ((i < str->len) && (i <= size))
	{
		tmp[i + size - str->len] = str->str[i];
		i++;
	}
	tmp[size] = '\0';
	return (tmp);
}
