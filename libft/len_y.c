#include "libft.h"

size_t					len_y(char **tab)
{
	size_t				y;

	if (tab == NULL)
		return (0);
	y = 0;
	while (tab[y] != NULL)
		y++;
	return (y);
}
