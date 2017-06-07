#include "libft.h"

char		*ft_strdup(const char *s)
{
	char			*dup;
	unsigned int	len;

	len = ft_strlen(s);
	if ((dup = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	dup[len] = '\0';
	return (ft_strcpy(dup, s));
}

char		*ft_strdup_and_len(const char *s, size_t *len)
{
	char			*dup;
	size_t			i;

	*len = ft_strlen(s);
	i = 0;
	if ((dup = malloc((*len + 1) * sizeof(char))) != NULL)
	{
		while (i < *len)
		{
			dup[i] = s[i];
			i++;
		}
		dup[*len] = '\0';
	}
	return (dup);
}
