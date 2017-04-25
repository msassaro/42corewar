/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:32:05 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:32:08 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char_spe(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

long long int	ft_long_atoi(const char *str)
{
	long long int		v[3];

	v[2] = 0;
	v[0] = 1;
	v[1] = 0;
	while (str[v[2]])
	{
		while (ft_char_spe(str[v[2]]) == 1)
			v[2]++;
		if (str[v[2]] == '+' || str[v[2]] == '-')
		{
			if (str[v[2]] == '-')
				v[0] *= -1;
			v[2]++;
		}
		while ('0' <= str[v[2]] && str[v[2]] <= '9')
		{
			v[1] = v[1] * 10 + (str[v[2]] - '0');
			v[2]++;
		}
		if (str[v[2]] < '0' || '9' < str[v[2]])
			return (v[1] * v[0]);
		v[2]++;
	}
	return (v[1] * v[0]);
}
