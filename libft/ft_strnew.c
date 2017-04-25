/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 08:21:04 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/01 09:54:07 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char *s;

	if ((s = (char*)malloc(sizeof(*s) * size + 1)) == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
