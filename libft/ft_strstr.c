#include "libft.h"

static int	trouve_aiguille(const char *meule, const char *aiguille)
{
	while (*aiguille != '\0')
	{
		if (*meule != *aiguille)
			return (0);
		meule++;
		if (*meule == '\0')
			return ((*++aiguille == '\0') ? 1 : 0);
		aiguille++;
	}
	return (1);
}

char		*ft_strstr(const char *meule, const char *aiguille)
{
	if (*aiguille == '\0')
		return (char*)(meule);
	while (*meule != '\0')
	{
		if (*meule == *aiguille)
			if (trouve_aiguille(meule, aiguille))
				return ((char*)(meule));
		meule++;
	}
	return (NULL);
}
