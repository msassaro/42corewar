/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:04:02 by fpasquer          #+#    #+#             */
/*   Updated: 2015/11/24 22:24:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dest;
	size_t	l_src;

	i = 0;
	l_dest = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size > (l_dest + 1))
	{
		while (i < (size - l_dest - 1))
		{
			dst[l_dest + i] = src[i];
			i++;
		}
		dst[l_dest + i] = '\0';
	}
	if (size >= l_dest)
		return (l_dest + l_src);
	return ((l_dest + l_src) - (l_dest - size));
}
