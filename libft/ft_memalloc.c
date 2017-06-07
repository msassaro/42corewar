#include "libft.h"

void		*ft_memalloc(size_t n)
{
	void		*variable;

	if ((variable = malloc(n)) == NULL)
		return (NULL);
	ft_bzero(variable, n);
	return (variable);
}
