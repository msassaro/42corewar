#include "libft.h"

size_t			ft_putendl_fd(const char *s, int fd)
{
	unsigned int	len;

	len = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (len + 1);
}
