#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem_s;
	unsigned int	i;

	i = 0;
	mem_s = (unsigned char *)s;
	while (i < n)
		if (mem_s[i++] == (unsigned char)c)
			return (&mem_s[--i]);
	return (NULL);
}
