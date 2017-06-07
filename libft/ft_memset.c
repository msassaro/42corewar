#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned int	i;

	i = 0;
	mem = (unsigned char *)s;
	while (n)
	{
		mem[i++] = (unsigned char)c;
		n--;
	}
	return (s);
}
