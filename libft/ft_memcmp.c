#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem_s1;
	unsigned char	*mem_s2;

	mem_s1 = (unsigned char *)s1;
	mem_s2 = (unsigned char *)s2;
	while (n)
	{
		if (*mem_s1 != *mem_s2)
			return (*mem_s1 - *mem_s2);
		n--;
		mem_s1++;
		mem_s2++;
	}
	return (0);
}
