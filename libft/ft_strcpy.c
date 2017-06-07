#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while ((dest[i] = (char)src[i]) != '\0')
		i++;
	dest[i] = '\0';
	return (dest);
}
