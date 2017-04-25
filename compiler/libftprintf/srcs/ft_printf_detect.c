/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_detect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:10 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:35:46 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_lflag[] = {
	"h",
	"hh",
	"l",
	"ll",
	"j",
	"z",
	NULL
};

void	ft_detect_flag(t_opt *opt, const char *fmt, int i)
{
	char	*flag;
	int		j;

	j = 0;
	opt->flag = NULL;
	flag = (char*)ft_memalloc(sizeof(char) * 6);
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i])
			|| ft_strchr(PRINTF_LFLAG, fmt[i]))
			&& !ft_strchr(PRINTF_FORMAT, fmt[i]) && fmt[i])
	{
		if (!ft_strchr(flag, fmt[i]) && ft_strchr(PRINTF_FLAG, fmt[i]))
		{
			if (fmt[i] == '0' && (ft_isdigit(fmt[i - 1])
				|| fmt[i - 1] == '.'))
				;
			else
			{
				flag[j] = fmt[i];
				j++;
			}
		}
		i++;
		opt->flag = flag;
	}
}

void	ft_detect_width(t_opt *opt, const char *fmt, va_list *ap, int i)
{
	int		start;
	int		end;

	opt->width = 0;
	start = 0;
	end = 0;
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i]))
				&& !ft_strchr(PRINTF_FORMAT, fmt[i]) && fmt[i])
	{
		if (fmt[i] == '*')
			opt->width = (int)(va_arg(*ap, int));
		if (ft_isdigit(fmt[i]) && fmt[i - 1] != '.')
			start = i;
		while (ft_isdigit(fmt[i]) && fmt[i])
		{
			end = i;
			i++;
		}
		opt->width = ft_atoi_startend(fmt, start, end);
		i++;
	}
}

void	ft_detect_precision(t_opt *opt, const char *fmt, int i)
{
	int		start;
	int		end;

	opt->prec = 0;
	start = 0;
	end = 0;
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i]))
				&& !ft_strchr(PRINTF_FORMAT, fmt[i]) && fmt[i])
	{
		if (fmt[i] == '.')
		{
			while (fmt[i] == '.')
				i++;
			if (ft_isdigit(fmt[i]))
			{
				start = i;
				while ('0' <= fmt[i] && fmt[i] <= '9')
					i++;
				end = i;
			}
			opt->prec = ft_atoi_startend(fmt, start, end);
		}
		i++;
	}
}

void	ft_detect_format(t_opt *opt, const char *fmt, int i)
{
	opt->format = '\0';
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i])
			|| ft_strchr(PRINTF_LFLAG, fmt[i])) && fmt[i]
			&& !ft_strchr(PRINTF_FORMAT, fmt[i]))
		i++;
	if (ft_strchr(PRINTF_FORMAT, fmt[i]))
		opt->format = fmt[i];
}

void	ft_detect_lflag(t_opt *opt, const char *fmt, int i)
{
	int		j;
	int		len;

	j = 0;
	opt->lflag = NULL;
	while ((ft_strchr(PRINTF_FLAG, fmt[i]) || ft_isdigit(fmt[i]))
			&& !ft_strchr(PRINTF_FORMAT, fmt[i])
			&& !ft_strchr(PRINTF_LFLAG, fmt[i]) && fmt[i])
		i++;
	while (g_lflag[j] != NULL)
	{
		len = (int)ft_strlen((char*)g_lflag[j]);
		if (ft_strnequ(g_lflag[j], fmt + i, len) == 1)
			opt->lflag = g_lflag[j];
		j++;
	}
}
