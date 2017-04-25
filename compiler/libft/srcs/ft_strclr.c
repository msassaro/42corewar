/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:07:27 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/25 17:12:18 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function take a string and assign '\0' to all its chars
*/

void	ft_strclr(char *s)
{
	while (s != NULL && *s)
		*s++ = '\0';
}
