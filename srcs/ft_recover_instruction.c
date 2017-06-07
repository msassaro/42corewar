#include "../incs/corewar.h"

void						ft_recover_instruction(int fd, t_array *array,
		int *size)
{
	char					instruction[10000];
	int						y;
	int						i;
	static int				player = 0;

	player++;
	ft_bzero(instruction, sizeof(char) * 10000);
	i = read(fd, instruction, 10000);
	if ((i == -1 || i == 0))
	{
		ft_putendl("ERROR READ : ft_recover_instruction");
		exit(ERROR_READ);
	}
	if (i != *size || *size > 682 || *size <= 0)
	{
		ft_putendl("ERROR SIZE : ft_recover_instruction");
		exit(ERROR_SIZE_CHAMP);
	}
	y = 0;
	while (y < i)
		y += ft_parse_instruction(&instruction[y], &array[y]);
	y = 0;
	while (y < i)
		array[y++].player = player;
}
