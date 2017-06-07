#include "libft.h"

char		**ft_free_strsplit(char **tab)
{
	unsigned int	y;

	y = 0;
	while (tab[y] != NULL)
	{
		free(tab[y]);
		tab[y++] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}
