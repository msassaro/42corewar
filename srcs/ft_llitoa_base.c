#include "../incs/corewar.h"

static int		ft_count(long long int n, int base, int *tab)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	return (i);
}

static void		ft_fill(char *str, int *tab, int unit, long long int n)
{
	int			i;
	int			x;

	x = unit;
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (i <= x)
	{
		str[i] = (tab[unit] < 10) ? tab[unit] + '0' : tab[unit] + 'a' - 10;
		unit--;
		i++;
	}
}

char			*ft_llitoa_base(long long int n, int base, int *u)
{
	char		*str;
	int			tab[64];
	int			tmp;
	char		*tmp2;

	str = NULL;
	*u = ft_count(n, base, tab);
	str = (*u) ? ft_strnew(*u) : ft_strnew(2);
	if (!*u && str)
	{
		*u = 2;
		ft_strcpy(str, "00");
		return (str);
	}
	tmp = *u;
	tmp--;
	if (str)
		ft_fill(str, tab, tmp, n);
	if (*u == 1)
	{
		tmp2 = str;
		str = ft_strjoin("0", str);
		free(tmp2);
	}
	return (str);
}
