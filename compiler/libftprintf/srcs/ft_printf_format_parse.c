/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_parse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:23 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 19:29:24 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** this variable contains all the fct ptr corresponding to the format types.
*/

t_format	g_formats[] = {
	{'%', &ft_flag_percent},
	{'s', ft_flag_s},
	{'S', &ft_flag_s},
	{'p', &ft_flag_p},
	{'d', &ft_flag_d},
	{'D', &ft_flag_d},
	{'i', &ft_flag_d},
	{'o', &ft_flag_o},
	{'O', &ft_flag_o},
	{'u', &ft_flag_u},
	{'U', &ft_flag_u},
	{'x', &ft_flag_x},
	{'X', &ft_flag_x},
	{'c', &ft_flag_c},
	{'C', &ft_flag_c},
	{'b', &ft_flag_b},
	{'\0', NULL}
};

/*
** this fct is used to count the len of "special" chars.
** useful because we get the len to increment to go to the next "normal" char.
*/

static int	ft_step_after_flag(const char *fmt, int i)
{
	int		len;

	len = 0;
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i])
				|| ft_strchr(PRINTF_LFLAG, fmt[i]))
			&& !ft_strchr(PRINTF_FORMAT, fmt[i]) && fmt[i])
	{
		i++;
		len++;
	}
	return (len + 1);
}

static void	ft_get_without_format_type(const char *fmt, int i, t_opt *opt,
					t_str *out)
{
	t_str	*str;

	if (fmt[i] == '\0')
		return ;
	str = malloc(sizeof(str));
	str->str = ft_strnew(1);
	str->str[0] = fmt[i];
	str->len = 1;
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	free(str);
}

static int	ft_printf_format_2(t_opt opt, t_str *out, va_list *ap)
{
	int		j;

	j = 0;
	while (g_formats[j].format != '\0')
	{
		if (g_formats[j].format == opt.format)
		{
			if (g_formats[j].fct(&opt, out, ap) == -1)
				return (-1);
			break ;
		}
		j++;
	}
	return (0);
}

/*
** In this function this is the heart of the format parsing.
** we will firstly detect the flags, precision, min width and format type ...
** and the length id if they exists. If not it just do nothing and it will
** print the letter following '%'
** We also create the structure option in wich we will store all these values.
** To apply the conversion type, we will check if the conversion type
** correspond to one in the g_formats variable.
** If it does, we use the correcponding function with a fct ptr
*/

int			ft_printf_format(t_str *out, const char *fmt, va_list *ap, int i)
{
	t_opt	opt;
	int		len;

	len = 0;
	ft_detect_flag(&opt, fmt, i);
	ft_detect_width(&opt, fmt, ap, i);
	ft_detect_precision(&opt, fmt, i);
	ft_detect_lflag(&opt, fmt, i);
	len = ft_step_after_flag(fmt, i);
	ft_detect_format(&opt, fmt, i);
	if (ft_strchr(PRINTF_FORMAT, opt.format))
	{
		if (ft_printf_format_2(opt, out, ap) == -1)
			return (-1);
	}
	else
	{
		len--;
		ft_get_without_format_type(fmt, i + len, &opt, out);
		if (fmt[i] != '\0')
			len++;
	}
	return (len);
}
