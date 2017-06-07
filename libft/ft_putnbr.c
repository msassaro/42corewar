#include "libft.h"

void			ft_putnbr(int nb)
{
	ft_putnbr_fd(nb, STDOUT_FILENO);
}
