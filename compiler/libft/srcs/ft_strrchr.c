/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:54:15 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 16:25:14 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function
*/

char	*ft_strrchr(const char *s, int c)
{
	int		size;

	size = 0;
	while (s[size])
		size++;
	while (0 <= size)
	{
		if (s[size] == c)
		{
			return (&(((char*)s)[size]));
		}
		size--;
	}
	return (0);
}
