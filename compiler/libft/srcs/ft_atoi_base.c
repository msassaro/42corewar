/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 17:47:46 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function will convert str and base into int
** then it will find the power to start the base with: while (nb > base pow)
** then it will see for each pow the number X to apply. and put the X value
** into the char *result;
** ex: (nb - X * (nb pow)) ==> find X
** example for nb = 420 and base = 8
** 8^3 = 512	(420 < 512) => X = 0
** 8^2 = 64		(420 - (6 * 64) = 36) => X = 6
** 8^1 = 8		(420 - 8 * 4 = 4) => X = 4
** 8^0 = 1		(420 - 1 * 4 = 0) => X = 4
** then result = 4460 because we go by decreasing the pow
** this is why we revert result with ft_strrev
*/

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nb;
	int		base_nb;
	char	*result;

	i = 0;
	base_nb = ft_atoi(base);
	nb = ft_atoi(str);
	while (nb > (ft_power(base_nb, i)))
		i++;
	result = (char*)malloc(sizeof(char) * i + 1);
	ft_memset(result, '0', i + 1);
	while (i >= 0)
	{
		while ((nb - ft_power(base_nb, i)) >= 0)
		{
			result[i]++;
			nb -= ft_power(base_nb, i);
		}
		i--;
	}
	ft_strrev(result);
	return (ft_atoi(result));
}
