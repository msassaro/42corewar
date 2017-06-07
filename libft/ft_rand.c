#include "libft.h"
#include <time.h>

int				ft_rand(int min, int max)
{
	static int	loop;

	if (loop == 0)
		srand(time(NULL));
	loop = 1;
	return ((rand() % (max - min + 1)) + min);
}
