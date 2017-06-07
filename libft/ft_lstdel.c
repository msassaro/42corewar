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
