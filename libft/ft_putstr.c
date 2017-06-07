#include "libft.h"

size_t			ft_putstr(const char *s)
{
	return (ft_putstr_fd(s, STDOUT_FILENO));
}
