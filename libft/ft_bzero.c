#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;

	mem = (unsigned char *)s;
	while (n)
	{
		n--;
		*mem++ = 0;
	}
}
