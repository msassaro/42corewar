/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 09:10:42 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/15 21:56:27 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*new_s;
	unsigned int	i;

	new_s = NULL;
	if (start <= ft_strlen(s))
	{
		if ((new_s = (char*)ft_memalloc(sizeof(*new_s) * len + 1)) == NULL)
			return (NULL);
		i = 0;
		while (s[start + i] != '\0' && i < len)
		{
			new_s[i] = s[start + i];
			i++;
		}
		new_s[i] = '\0';
	}
	return (new_s);
}
