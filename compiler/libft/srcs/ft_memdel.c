/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:00:33 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/17 15:19:32 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function takes for parameter a pointer adress
** the pointed memory zone is freed and the pointer
** set to NULL
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
