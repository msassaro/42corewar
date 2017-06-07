#include "../incs/corewar.h"

static char					*ft_fill_less(char *str, int size, int octet)
{
	char					*tmp;
	int						i;
	int						count;

	octet = (octet == 2) ? 4 : 8;
	count = 0;
	i = 8 - size;
	if (size == octet)
		return (str);
	if (!(tmp = ft_strnew(octet)))
		exit(-1);
	while (i < octet)
	{
		tmp[i] = str[count];
		i++;
		count++;
	}
	free(str);
	return (tmp);
}

static void					ft_str_base_16(char *str)
{
	int						i;

	i = 0;
	while (i < 8)
	{
		if (str[i] >= '0' && str[i] <= '9')
			str[i] = str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 87;
		i++;
	}
}

void						ft_print_param_to_array_4_octets(t_vm *vm,
		t_player *plr, int index, unsigned int nb)
{
	int						size;
	char					*tmp;
	int						i;

	i = 0;
	tmp = ft_llitoa_base2(nb, 16, &size);
	tmp = ft_fill_less(tmp, size, 4);
	ft_str_base_16(tmp);
	while (i < 8)
	{
		vm->array[index].code_hexa = (16 * tmp[i]) + (tmp[i + 1]);
		vm->array[index].player = plr->pos;
		i += 2;
		index++;
		if (index > 4095)
			index %= 4096;
	}
	ft_strdel(&tmp);
}
