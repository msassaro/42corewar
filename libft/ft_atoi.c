/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 10:23:21 by fpasquer          #+#    #+#             */
/*   Updated: 2016/04/21 10:06:05 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int				ft_atoi(const char *nptr)
{
	unsigned long long int	nb;
	unsigned long long int	limit;
	int						signe;

	signe = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\r' ||
			*nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			signe = -1;
	limit = (signe == 1) ? LLONG_MAX : (unsigned long long int)LLONG_MIN * -1;
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (nb * 10 > limit)
			return (limit);
		nb *= 10;
		if (nb + (*nptr - '0') > limit)
			return (limit);
		nb += *nptr++ - '0';
	}
	return ((long long int)nb * signe);
}
