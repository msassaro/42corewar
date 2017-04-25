/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:32:02 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 18:04:24 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*result;
	t_list	*memory;
	t_list	*memory2;

	if (lst == NULL || f == NULL)
		return (NULL);
	memory2 = f(lst);
	if ((result = ft_lstnew(memory2->content, memory2->content_size)))
	{
		memory = result;
		lst = lst->next;
		while (lst)
		{
			memory2 = f(lst);
			if (!(memory->next = ft_lstnew(memory2->content,
				memory2->content_size)))
				return (NULL);
			memory = memory->next;
			lst = lst->next;
		}
	}
	return (result);
}
