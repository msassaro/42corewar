#include "libft.h"

size_t				ft_nblen(long long int nb)
{
	size_t				len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb > 0 ? nb / 10 : nb * 10;
	}
	return (len);
}
