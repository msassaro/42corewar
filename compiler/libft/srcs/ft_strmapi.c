/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:10:06 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/25 17:11:04 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function create a new string with the right memory size
** It applies the f function to each char of this new
** mapped_str then precise the index
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned in, char))
{
	int		i;
	char	*mapped_str;

	if (s == NULL || f == NULL)
		return (NULL);
	mapped_str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapped_str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		mapped_str[i] = f(i, s[i]);
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
