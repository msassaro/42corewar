/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:34:42 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/24 21:31:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
		}
		if (s2[j] == '\0')
		{
			return ((char*)s1 + i);
		}
		i++;
	}
	return (0);
}
