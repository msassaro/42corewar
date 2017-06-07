#include "../incs/corewar.h"

int							ft_convert_hexa_to_int(unsigned char *str)
{
	int						str_len;
	int						count;
	int						result;

	result = 0;
	str_len = ft_strlen((char*)str) - 1;
	count = 0;
	while (str_len >= 0)
	{
		if (str[str_len] >= 'a')
			result += (str[str_len] - 97 + 10) * ft_power(count, 16);
		else
			result += (str[str_len] - 48) * ft_power(count, 16);
		str_len--;
		count++;
	}
	return (result);
}
