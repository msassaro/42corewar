#include "libft.h"

char				*ft_itoa_base(long long int nb, const unsigned int base)
{
	char						*tmp;
	char						*ret;
	unsigned long long int		nb_cpy;

	nb_cpy = (unsigned long long int)(nb < 0) ? nb * -1 : nb;
	if ((ret = ft_utoa_base(nb_cpy, base)) != NULL)
	{
		if (nb < 0 && base == 10)
		{
			if ((tmp = ft_strjoin("-", ret)) == NULL)
				return (NULL);
			ft_memdel((void**)&ret);
			ret = tmp;
		}
	}
	return (ret);
}
