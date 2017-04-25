/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:30:53 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/24 15:34:26 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** We copy s2 into s1. (and add unsigned casts)
*/

void	*ft_umemcpy(void *s1, const void *s2, size_t n)
{
	unsigned char			*u8_s1;
	const unsigned char		*u8_s2;

	u8_s1 = (unsigned char*)s1;
	u8_s2 = (const unsigned char*)s2;
	while (n--)
		*u8_s1++ = *u8_s2++;
	return (s1);
}

/*
** We malloc a new memory then we copy s into it and return the new copy.
*/

void	*ft_memdup(const void *s, size_t n)
{
	void	*new;

	if ((new = (void*)ft_memalloc(n)) == NULL)
		return (NULL);
	return (ft_umemcpy(new, s, n));
}

/*
** Here we join s1 for a len l1 and s2 with a len l2
** Then we free s1 and s2 and return the concat of the two.
*/

void	*ft_memjoin(const void *s1, size_t l1, const void *s2, size_t l2)
{
	char	*s;
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	s = (char*)ft_memalloc(l1 + l2);
	ft_umemcpy(s, str1, l1);
	ft_umemcpy(s + l1, str2, l2);
	free(str1);
	free(str2);
	return (s);
}

int		ft_reverse(int old)
{
	int		new;

	new = 0;
	new += (old >> 0 & 0xFF) << 24;
	new += (old >> 8 & 0xFF) << 16;
	new += (old >> 16 & 0xFF) << 8;
	new += (old >> 24 & 0xFF) << 0;
	return (new);
}
