/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:56:49 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 19:03:56 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_nbr_to_str(long long n, char *str,
						unsigned int placement)
{
	unsigned long long	nb;

	placement--;
	if (n < 0)
	{
		nb = (unsigned long long)-n;
		placement--;
	}
	else
		nb = (unsigned long long)n;
	if (nb >= 10)
	{
		ft_nbr_to_str((nb / 10), str, placement);
		str[placement] = ((nb % 10) + '0');
	}
	else
		str[placement] = (nb + '0');
	return (str);
}

static unsigned int		ft_number_len(long long n)
{
	unsigned int		count;
	unsigned long long	nb;

	count = 0;
	if (n < 0)
	{
		nb = (unsigned long long)-n;
		count++;
	}
	else
		nb = (unsigned long long)n;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char					*ft_utoa(unsigned long long n)
{
	unsigned int	number_len;
	char			*str;

	number_len = ft_number_len(n);
	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '0';
	}
	else
	{
		if (!(str = ft_strnew(number_len)))
			return (NULL);
		str = ft_nbr_to_str(n, str, number_len);
	}
	return (str);
}
