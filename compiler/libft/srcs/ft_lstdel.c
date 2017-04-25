/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:22:47 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 15:53:28 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*next_list;
	t_list		*memory;

	if (alst != NULL)
	{
		next_list = *alst;
		while (next_list != NULL)
		{
			(*del)((*next_list).content, (*next_list).content_size);
			memory = next_list->next;
			free(next_list);
			next_list = memory;
		}
		*alst = NULL;
	}
}
