/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:47:46 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/01 10:18:01 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will copy "src" into "dst" at most "len" characters.
** If src < len ==> the rest of "dst" is filled with '\0'.
** return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = (char)src[i];
		i++;
	}
	while (i < n)
	{
		dst[i++] = '\0';
	}
	return (dst);
}
