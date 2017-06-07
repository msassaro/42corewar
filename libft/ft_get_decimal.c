#include <stdio.h>

static double		get_rest(double nb, double *nb_soustrac)
{
	while ((nb > 0 && nb - (*nb_soustrac) >= (*nb_soustrac)) ||
				(nb < 0 && nb - (*nb_soustrac) <= (*nb_soustrac)))
		nb = (nb > 0) ? nb - (*nb_soustrac) : nb - (*nb_soustrac);
	(*nb_soustrac) /= 10;
	return (nb);
}

double				ft_get_decimal(const double nb, double *decimal)
{
	double	nb_soustrac;
	double	rest;

	nb_soustrac = (nb > 0) ? 100000000000000000 : -100000000000000000;
	rest = get_rest(nb, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	rest = get_rest(rest, &nb_soustrac);
	(*decimal) = get_rest(rest, &nb_soustrac);
	if ((*decimal) >= 1 || (*decimal) <= -1)
		(*decimal) -= ((*decimal) > 0) ? 1 : -1;
	return (nb - (*decimal));
}
