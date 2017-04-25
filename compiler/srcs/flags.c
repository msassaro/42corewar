/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:26:10 by msassaro          #+#    #+#             */
/*   Updated: 2016/06/07 15:40:36 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Here we just init the flags at 0.
** g_flag_e --> error mode --> -e
** g_flag_d --> detail mde --> -d
** g_flag_n --> set a new name.
*/

void	ft_init_gflags(void)
{
	g_flag_e = 0;
	g_flag_d = 0;
	g_flag_s = 0;
	g_flag_i = 0;
	g_flag_b = 0;
	g_flag_c = 0;
	g_flag_k = 0;
}

void	ft_check_newname(char *name, t_env *e, int *ac_nb)
{
	if ((int)ft_strlen(name) < NAME_LENGHT_MIN)
		ft_strerror("new name too small -%s", name);
	else if ((int)ft_strlen(name) > PROG_NAME_LENGTH)
		ft_strerror("new name too long -%s", name);
	e->new_name = ft_strdup(name);
	*ac_nb += 1;
}

int		ft_flags_part2(char c)
{
	if (c == 'e')
		g_flag_e = 1;
	else if (c == 'h' || c == '-')
		ft_user_man();
	else if (c == 'r')
		ft_file_requirements();
	else if (c == 'c')
		g_flag_c = 1;
	else if (c == 'b')
		g_flag_b = 1;
	else if (c == 'd')
		g_flag_d = 1;
	else if (c == 's')
		g_flag_s = 1;
	else if (c == 'i')
		g_flag_i = 1;
	else if (c == 'k')
		g_flag_k = 1;
	else
		return (0);
	return (1);
}

void	ft_flags_part3(int v[2], char **av, t_env *e, int *ac_nb)
{
	if (v[1] + 1 < v[0])
		ft_check_newname(av[v[1] + 1], e, ac_nb);
	else
		ft_strerror("no correct name following -%s", av[v[1]]);
}

/*
** BECAUSE OF THE NORM:
** ac = v[0]
** i = v[1]
*/

void	ft_flags(int ac, char **av, int *ac_nb, t_env *e)
{
	int		j;
	int		v[2];

	v[1] = 0;
	v[0] = ac;
	while (++v[1] < ac)
	{
		if (av[v[1]][0] == '-')
		{
			j = 0;
			while (av[v[1]][++j])
			{
				if (ft_flags_part2(av[v[1]][j]))
					;
				else if (av[v[1]][j] == 'n')
					ft_flags_part3(v, av, e, ac_nb);
				else
					ft_strerror("wrong option -%s", av[v[1]]);
			}
			*ac_nb += 1;
		}
	}
}
