#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if ((new = (char*)malloc(sizeof(*new) * ft_strlen(s) + 1)) != NULL)
	{
		i = 0;
		while (*s != '\0')
		{
			new[i] = f(i, *s++);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
