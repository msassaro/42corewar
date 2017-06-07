#include "libft.h"

char		*ft_strtrim(const char *s)
{
	unsigned int	len;
	unsigned int	i;
	char			*new_s;

	len = ft_strlen_wout_spc_be(s);
	if ((new_s = (char*)malloc(sizeof(*new_s) * len + 1)) == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	i = 0;
	while (i < len)
		new_s[i++] = (char)*s++;
	new_s[i] = '\0';
	return (new_s);
}
