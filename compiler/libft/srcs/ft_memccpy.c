/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:05:48 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 15:21:35 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This will copy the bytes from "src" to "dst"
** If "c" occurs in "src" the copy is stopped
** Returns a ptr of the byte after "c" in "b" if "c" exists
** Else n goes to zero and the function returns NULL
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	ptr_dest = (char*)dest;
	ptr_src = (char*)src;
	while (n-- > 0 && *ptr_src != c)
		*ptr_dest++ = *ptr_src++;
	if (*ptr_src == c)
	{
		*ptr_dest++ = *ptr_src++;
		return (ptr_dest);
	}
	else
		return (NULL);
}
