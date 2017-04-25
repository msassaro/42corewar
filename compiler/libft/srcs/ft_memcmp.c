/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:02:51 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 15:19:54 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the bytes between "s1" and "s2". We suppose the two are
** "n" bytes long.
** If the two strins are identical, the function returns 0.
** If there is a difference, it returns the difference s1[i] - s2[i]
** At the difference byte.
** Convert to unsigned char !
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	int				i;

	i = 0;
	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	while (n > 0 && ptr_s1[i] == ptr_s2[i])
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return (ptr_s1[i] - ptr_s2[i]);
}
