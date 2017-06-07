#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < n)
		dest[i++] = (char)src[j++];
	dest[i] = '\0';
	return (dest);
}
