#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char			*adr;
	unsigned int	i;

	adr = (char*)s;
	i = 0;
	while (adr[i] != '\0' && adr[i] != c)
		i++;
	return (adr[i] == c ? (char*)s + i : NULL);
}
