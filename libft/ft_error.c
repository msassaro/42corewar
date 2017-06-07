#include "libft.h"

void			ft_error(const char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}
