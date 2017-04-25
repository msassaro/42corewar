/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:37:00 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/13 18:05:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_pow(double nb, int exp)
{
	double		retour;
	int			entier;

	if (nb == 0)
		return (0.0);
	if (exp == 0)
		return ((nb < 0) ? -1.0 : 1.0);
	retour = 1;
	entier = exp;
	while (entier != 0)
	{
		retour = (exp > 0) ? retour * nb : retour / nb;
		entier = (entier < 0) ? entier + 1 : entier - 1;
	}
	return (retour);
}
