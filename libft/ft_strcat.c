#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
