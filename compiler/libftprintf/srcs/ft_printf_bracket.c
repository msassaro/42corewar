/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bracket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:06 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:28:08 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_typographic	g_typographic[] = {
	{"reset", "\033[0;0m"},
	{"eoc", "\033[39m"},
	{"eobg", "\033[49m"},
	{"bold", "\033[1m"},
	{"underline", "\033[4m"},
	{"black", "\033[30m"},
	{"white", "\033[97m"},
	{"blue", "\033[34m"},
	{"red", "\033[31m"},
	{"green", "\033[32m"},
	{"yellow", "\033[33m"},
	{"magenta", "\033[35m"},
	{"cyan", "\033[36m"},
	{"gray", "\033[37m"},
	{"bg black", "\033[40m"},
	{"bg red", "\033[41m"},
	{"bg green", "\033[42m"},
	{"bg yellow", "\033[43m"},
	{"bg blue", "\033[44m"},
	{"bg magenta", "\033[45m"},
	{"bg cyan", "\033[46m"},
	{"bg light", "\033[47m"},
	{"bg gray", "\033[47m"},
	{NULL, NULL},
};

int				ft_printf_bracket(t_str *out, const char *fmt, int i)
{
	int		j;
	int		len;
	int		keep_i;

	j = 0;
	len = 0;
	keep_i = i;
	while (fmt[keep_i] != '}' && fmt[keep_i] != '\0')
	{
		len++;
		keep_i++;
	}
	while (g_typographic[j].type != NULL)
	{
		if (ft_strnequ(fmt + i, g_typographic[j].type, len))
		{
			ft_printf_add_string(NULL, g_typographic[j].value,
					ft_strlen(g_typographic[j].value), out);
			return (len + 1);
		}
		j++;
	}
	ft_printf_add_char(out, '{');
	return (0);
}
