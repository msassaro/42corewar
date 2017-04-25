/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:03:13 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 15:32:36 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will search for the occurence of 'c' in the string "s" during
** "n" bytes. If 'c' exists the function returns ptr to c.
** If c doesnt exists (or s =NULL || n == 0) it returns NULL
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_src;

	ptr_src = (unsigned char*)s;
	while (n > 0 && *ptr_src++ != (unsigned char)c)
	{
		n--;
	}
	if (n <= 0)
		return (NULL);
	else
	{
		ptr_src--;
		return (ptr_src);
	}
}
