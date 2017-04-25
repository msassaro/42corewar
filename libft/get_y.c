/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:57:12 by fpasquer          #+#    #+#             */
/*   Updated: 2016/03/12 10:30:43 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int				get_y(const char *s, char c)
{
	int				curseur;
	unsigned int	y;

	y = 0;
	if (s != NULL)
	{
		curseur = DEHORS;
		while (*s == c && *s != '\0')
			s++;
		while (*s != '\0')
		{
			if (*s == c)
				if (curseur == DEDANS)
					y++;
			curseur = (*s++ == c) ? DEHORS : DEDANS;
		}
		if (curseur == DEDANS)
			y++;
	}
	return (y);
}
