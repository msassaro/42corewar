/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:03:53 by msassaro          #+#    #+#             */
/*   Updated: 2016/04/19 13:11:53 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_explode_count(char *line, char separator)
{
	int		i;
	int		nb_part;

	i = 0;
	nb_part = 0;
	while (line[i])
	{
		while (line[i] == separator)
			i++;
		if (line[i] != separator)
		{
			nb_part++;
			while ((line[i] != separator) && line[i])
				i++;
		}
	}
	return (nb_part);
}
