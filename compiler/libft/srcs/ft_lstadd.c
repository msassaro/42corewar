/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:22:38 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 16:32:54 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** add new element to the begining of the list
*/

void	ft_lstadd(t_list **alist, t_list *new)
{
	if (new != NULL && alist != NULL)
	{
		new->next = *alist;
		*alist = new;
	}
}
