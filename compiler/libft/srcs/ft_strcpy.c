/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:46:12 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/24 12:33:26 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** will copy the "src" into "dst". With the '\0' included
** it returns dst
*/

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*src != '\0')
		*ptr_dest++ = *src++;
	*ptr_dest = '\0';
	return (dest);
}
