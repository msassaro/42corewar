#include "libft.h"

t_list				*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*new;

	if ((new = (t_list*)malloc(sizeof(*new))) != NULL)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			if ((new->content = (void*)malloc(sizeof(content))) == NULL)
				return (NULL);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
