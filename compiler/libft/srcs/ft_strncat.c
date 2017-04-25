/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:20:49 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 15:23:52 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will copy "n" caracters of "s2" at the end of "s1" then
** add the terminating '\0'.
** return "s1"
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		size;
	size_t	i;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	while (s2[i] && i < n)
	{
		s1[size + i] = s2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
