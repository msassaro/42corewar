#include "libft.h"

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}
