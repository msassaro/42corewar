/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:52:12 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/16 09:52:27 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

int							ft_power(int power, int nb)
{
	int						i;
	int						tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	i = 0;
	while (i < power)
	{
		tmp *= nb;
		i++;
	}
	return (tmp);
}
