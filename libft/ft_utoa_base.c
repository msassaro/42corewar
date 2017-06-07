#include "libft.h"

char				*ft_utoa_base(unsigned long long int nb,
		const unsigned int base)
{
	char						*ret;
	static unsigned int			loop;
	static unsigned int			i;
	unsigned long long int		mem;

	if (base < 2 || base > 36)
		return (NULL);
	if (nb == 0)
	{
		if ((ret = ft_memalloc(sizeof(char) * (loop > 0 ? loop + 1 : 2))) ==
				NULL)
			return (NULL);
		if (loop == 0)
			ret[0] = '0';
		loop = 0;
		i = 0;
		return (ret);
	}
	loop++;
	mem = nb % base;
	ret = ft_utoa_base(nb / base, base);
	ret[i++] = (mem < 10) ? (char)mem + '0' : (char)mem - 10 + 'a';
	return (ret);
}
