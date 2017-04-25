/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:50 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 16:57:51 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace_char(char *str, char old, char new)
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = ft_memalloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == old)
			new_s[i] = new;
		else
			new_s[i] = str[i];
		i++;
	}
	return (new_s);
}
