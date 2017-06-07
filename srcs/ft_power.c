#include "../incs/corewar.h"

int							ft_power(int power, int nb)
{
	int						i;
	int						tmp;

	tmp = nb;
	if (power == 0)
		return (1);
	i = 0;
	while (i < power)
	{
		tmp *= nb;
		i++;
	}
	return (tmp);
}
