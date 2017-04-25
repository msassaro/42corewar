/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:58:15 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/13 20:45:52 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*retour;
	t_list		*lst2;

	retour = NULL;
	lst2 = NULL;
	if (lst != NULL)
		if ((retour = ft_lstnew(lst->content, lst->content_size)) != NULL)
		{
			lst2 = f(lst);
			retour = lst2;
			while (lst->next != NULL)
			{
				lst2->next = f(lst->next);
				lst2 = lst2->next;
				lst = lst->next;
			}
		}
	return (retour);
}
