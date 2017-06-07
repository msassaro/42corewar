#include "../incs/virtual_machine.h"

void						error(char *s)
{
	ft_putendl(s);
	exit(-1);
}

int							check_key(int key, t_vm *vm)
{
	if (key == ESCAPE)
		return (ESCAPE);
	if (key == SPACE)
		vm->status = vm->status == PAUSE ? RUN : PAUSE;
	else if (key == 410)
		return (REFRESH);
	return (-1);
}

int							**make_tab_2d(int *tab, int height, int width)
{
	int						**ret;
	int						y;
	long long int			i;
	long long int			mem;
	long long int			end;

	if ((ret = ft_memalloc(sizeof(int*) * height)) == NULL)
		return (NULL);
	i = 0;
	mem = 0;
	y = 0;
	end = height * width;
	while (i < end)
	{
		if (i == mem)
		{
			ret[y++] = &tab[i];
			mem += width;
		}
		i++;
	}
	return (ret);
}

unsigned int				get_new_index(int decalage, unsigned int i_grid,
		t_vm *vm)
{
	long long int			cpy_i_grid;

	cpy_i_grid = (long long int)i_grid;
	if (cpy_i_grid + decalage < NB_CASE_TAB && cpy_i_grid + decalage > 0)
	{
		return ((cpy_i_grid + decalage) % NB_CASE_TAB);
	}
	else if (cpy_i_grid + decalage < 0)
	{
		decalage = decalage % NB_CASE_TAB;
		decalage += cpy_i_grid;
		return ((NB_CASE_TAB + decalage) % NB_CASE_TAB);
	}
	decalage -= NB_CASE_TAB - i_grid;
	vm->ff = 0;
	return ((decalage) % NB_CASE_TAB);
}

unsigned int				get_new_index_with_mod(int decalage,
		unsigned int i_grid, t_vm *vm)
{
	return (get_new_index(decalage % NB_MOD, i_grid, vm));
}
