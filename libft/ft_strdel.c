#include "libft.h"

void		ft_strdel(char **s)
{
	free(*s);
	*s = NULL;
}
