/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:17:15 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/24 17:23:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** will copy "s2" at the end of "s1" then add the terminating '\0'
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	while (s2[i])
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
