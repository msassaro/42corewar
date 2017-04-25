/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:44:57 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/26 17:57:59 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function write "len" times the value "c" converted in unsigned char
** into the string "b"
** it returns the first param "b"
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pointer;

	pointer = (unsigned char*)b;
	while (len-- > 0)
	{
		*pointer = (unsigned char)c;
		pointer++;
	}
	return (b);
}
