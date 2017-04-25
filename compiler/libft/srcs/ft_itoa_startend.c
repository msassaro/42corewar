/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:19:38 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 17:44:36 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function takes an int and translate it into char.
** the ft_number_len function ==> count the size of the number
** ft_nbr_to_str ==> recursive function that put each corresponding char
** into the str string and return the string
*/

static char				*ft_nbr_to_str(long long n, char *str,
						unsigned int placement)
{
	unsigned long long	nb;

	placement--;
	if (n < 0)
	{
		nb = (unsigned long long)-n;
		str[0] = '-';
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
	unsigned int			count;
	unsigned long long		nb;

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

char					*ft_itoa_startend(long long n)
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
