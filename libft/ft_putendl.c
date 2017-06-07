#include "libft.h"

size_t			ft_putendl(const char *s)
{
	return (ft_putendl_fd(s, STDOUT_FILENO));
}
