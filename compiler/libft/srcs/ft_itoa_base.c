/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:03:51 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/18 10:59:07 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*g_base = "0123456789abcdef";

char			*ft_itoa_base(int nb, int len_base)
{
	int		len_nb;
	char	*str;

	len_nb = ft_nbrlen_base(nb, len_base);
	str = (char*)malloc(sizeof(char) * len_nb + 1);
	if (nb < 0)
		str[0] = '-';
	str[len_nb] = '\0';
	while (nb)
	{
		str[--len_nb] = (nb > 0) ? g_base[nb % len_base]
			: g_base[-(nb % len_base)];
		nb /= len_base;
	}
	return (str);
}
