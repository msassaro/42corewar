/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:12:58 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/26 16:10:29 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function will create a new string allocated with the right size
** then apply the function f to each char of the mapped_str
** It returns the freshly created string: mapped_str
*/

char	*ft_strmap(char const *s, char (*f)(char))
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
		mapped_str[i] = f(s[i]);
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
