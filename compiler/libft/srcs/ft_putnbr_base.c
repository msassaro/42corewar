/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:36 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 16:57:39 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this fct will take an int and it will convert it into the wanted base
** then it will print it
*/

void	ft_putnbr_base(int nbr, char *base)
{
	char	*str_nb;
	int		res;

	res = 0;
	str_nb = ft_itoa(nbr);
	res = ft_atoi_base(str_nb, base);
	ft_putnbr(res);
}
