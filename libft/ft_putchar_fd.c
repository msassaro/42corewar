#include "libft.h"

void			ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}
