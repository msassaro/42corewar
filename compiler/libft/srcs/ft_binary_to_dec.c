/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:38:08 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/01 15:38:12 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_binary_to_dec(char *binary)
{
	int		result;
	int		i;
	int		j;

	result = 0;
	i = 0;
	j = 7;
	while (i < 8)
	{
		if (binary[j] == '1')
			result += ft_power(2, i);
		i++;
		j--;
	}
	return (result);
}
