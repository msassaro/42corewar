/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_startend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:04:29 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 17:04:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_startend(const char *str, int start, int end)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	if (str[start] == '-')
	{
		sign = -1;
		start++;
	}
	else if (str[start] == '+')
		start++;
	while (('0' <= str[start] && str[start] <= '9') && (start <= end))
	{
		result = result * 10 + (str[start] - '0');
		start++;
	}
	return (result * sign);
}
