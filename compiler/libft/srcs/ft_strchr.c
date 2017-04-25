/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:41:20 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/24 20:12:35 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Will localize the first occurence of the "c" char in "s"
** return a ptr to the occurence if it exists. NULL if it doesnt
** The terminating char is considered to be part of the string
** So if the c = '\0' it founds the occurence of c
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	if (!s || !c)
		return (NULL);
	ptr_s = (char*)s;
	i = 0;
	while (ptr_s[i] != c && ptr_s[i] != 0)
		i++;
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (NULL);
}
