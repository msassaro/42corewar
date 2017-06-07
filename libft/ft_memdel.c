#include "libft.h"

void		ft_memdel(void **variable)
{
	free(*variable);
	*variable = NULL;
}
