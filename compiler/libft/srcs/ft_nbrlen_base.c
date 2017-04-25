/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:03:51 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 18:51:22 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen_base(int nb, int len_base)
{
	int		len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		len++;
		nb /= len_base;
	}
	return (len);
}
