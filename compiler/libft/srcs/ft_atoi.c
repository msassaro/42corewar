/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:26:31 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/12 19:01:12 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function takes a char and converts it into an int
** At the end if there is a char is return the read number
** example: " -42gg" ==> -42
** VARIABLES:
** sign = var[0]
** result = var[1]
** i = var[2]
*/

static int	ft_char_spe(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		v[3];

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
