/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:15:21 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 17:57:22 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this fct will return a char *memory.
** It will take the *s input then will copy it into memory, begining at start
** and for a len length
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*memory;

	if (s == NULL)
		return (NULL);
	memory = (char*)malloc(sizeof(char) * (len + 1));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		memory[i] = s[start + i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}
