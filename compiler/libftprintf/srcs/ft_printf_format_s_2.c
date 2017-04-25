/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_s_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 19:58:11 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 20:00:12 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_wstr_to_str_2(char **wstr)
{
	char	*result;
	int		i;

	i = 0;
	while (wstr[i])
		i++;
	if ((result = (char*)ft_memalloc(sizeof(char) * (4 * i + 1))) == NULL)
		return (NULL);
	return (result);
}

static void		ft_wstr_to_str_init_v(int v[3])
{
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

static void		ft_wstr_to_str_incr_v(int v[3])
{
	v[1]++;
	v[2]++;
}

char			*ft_wstr_to_str(char **wstr, t_opt *opt, t_str *str_arg)
{
	int		v[3];
	char	*result;

	ft_wstr_to_str_init_v(v);
	if ((result = ft_wstr_to_str_2(wstr)) == NULL)
		return (NULL);
	while (wstr[v[0]])
	{
		v[1] = 0;
		if (ft_strchr(opt->flag, '.') && (((int)ft_strlen(wstr[v[0]])
						+ (int)ft_strlen(result)) > opt->prec))
			str_arg->len = ft_strlen(result);
		else
		{
			while (wstr[v[0]][v[1]])
			{
				result[v[2]] = wstr[v[0]][v[1]];
				ft_wstr_to_str_incr_v(v);
			}
		}
		free(wstr[v[0]]);
		v[0]++;
	}
	free(wstr);
	return (result);
}
