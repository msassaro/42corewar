/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_str_malloc_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:13 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 17:43:11 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_t_str_malloc_plus(t_str *str, int size, char c)
{
	char	*tmp;
	int		i;

	i = str->len - 1;
	if ((str->len >= size) || (str->alloc_len >= size + 1))
		return (str->str);
	if ((tmp = ((char*)malloc(sizeof(char) * size + 1))) == NULL)
		return (NULL);
	ft_memset(tmp, c, size);
	while (i >= 0)
	{
		tmp[i] = str->str[i];
		i--;
	}
	tmp[size] = '\0';
	return (tmp);
}
