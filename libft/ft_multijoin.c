/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:09:25 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/09 21:17:58 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char			*ft_multijoin(unsigned int nb_arg, ...)
{
	char			*new;
	unsigned int	len;
	unsigned int	i;
	va_list			ap1;
	va_list			ap2;

	va_start(ap1, nb_arg);
	va_start(ap2, nb_arg);
	i = 0;
	len = 0;
	while (i++ < nb_arg)
		len += ft_strlen(va_arg(ap1, char*));
	va_end(ap1);
	if ((new = (char*)ft_memalloc(sizeof(*new) * len + 1)) != NULL)
		while (--i)
			ft_strcat(new, va_arg(ap2, char*));
	va_end(ap2);
	return (new);
}
