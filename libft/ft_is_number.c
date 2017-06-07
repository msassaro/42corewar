#include "libft.h"

int					ft_is_number(char *nb)
{
	int						i;

	i = 0;
	while (ft_isspace(nb[i]) == 1)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
		i++;
	if (nb[i] == '\0')
		return (0);
	while (nb[i] != '\0')
		if (ft_isdigit(nb[i++]) != 1)
			return (0);
	return (i == 0 ? 0 : 1);
}
