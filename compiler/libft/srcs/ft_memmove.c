/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:04:53 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/26 18:01:15 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*dstcpy;
	const char		*srccpy;

	dstcpy = dest;
	srccpy = src;
	while (len-- > 0)
	{
		if (dstcpy > srccpy)
		{
			dstcpy = dest + len;
			srccpy = src + len;
			*dstcpy = *srccpy;
		}
		else
			*dstcpy++ = *srccpy++;
	}
	return (dest);
}
