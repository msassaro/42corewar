/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:29:48 by fpasquer          #+#    #+#             */
/*   Updated: 2015/11/24 22:19:11 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*mem;

	if ((*alst) != NULL && del != NULL)
	{
		while ((*alst)->next != NULL)
		{
			mem = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = mem;
		}
		ft_lstdelone(alst, del);
	}
}
