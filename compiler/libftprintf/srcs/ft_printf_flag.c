/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:13 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:28:14 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width(t_opt *opt, t_str *str)
{
	t_str	new_str;

	new_str.len = str->len;
	new_str.alloc_len = new_str.len;
	new_str.str = str->str;
	if (ft_strchr(opt->flag, '-') && (str->len < opt->width))
	{
		str->str = ft_t_str_malloc_plus(&new_str, opt->width, ' ');
		str->len = opt->width;
	}
	else if (!ft_strchr(opt->flag, '-') && (str->len < opt->width))
	{
		str->str = ft_t_str_malloc_rplus(str, opt->width, ' ');
		str->len = opt->width;
	}
}

void	ft_flag_space(long long int nb, t_opt *opt, t_str *str)
{
	char	*new_str;

	new_str = NULL;
	if ((nb >= 0) && ft_strchr(opt->flag, ' ') && !ft_strchr(opt->flag, '+'))
	{
		new_str = ft_memalloc(str->len + 1);
		new_str[0] = ' ';
		ft_memcpy(new_str + 1, str->str, str->len);
		new_str[str->len + 1] = '\0';
		free(str->str);
		str->str = new_str;
		str->len += 1;
	}
}

void	ft_flag_plus(long long int nb, t_opt *opt, t_str *str)
{
	char	*new_str;

	new_str = NULL;
	if (nb >= 0 && ft_strchr(opt->flag, '+'))
	{
		new_str = ft_memalloc(str->len + 1);
		new_str[0] = '+';
		ft_memcpy(new_str + 1, str->str, str->len);
		new_str[str->len + 1] = '\0';
		free(str->str);
		str->str = new_str;
		str->len += 1;
	}
}

void	ft_flag_zero(t_opt *o, t_str *str)
{
	if (str->str)
	{
		if (ft_strchr(o->flag, '0') && !ft_strchr(o->flag, '-') && !(o->prec))
			str->str = ft_str_replace_char(str->str, ' ', '0');
		if (ft_strchr(str->str, '-') && ft_strchr(o->flag, '0'))
		{
			*ft_strchr(str->str, '-') = '0';
			str->str[0] = '-';
		}
		if (ft_strchr(str->str, '+') && ft_strchr(o->flag, '0'))
		{
			*ft_strchr(str->str, '+') = '0';
			str->str[0] = '+';
		}
		if ((ft_atoi(str->str) >= 0) && ft_strchr(o->flag, ' ')
				&& !ft_strchr(o->flag, '-') && !ft_strchr(o->flag, '+')
				&& (o->format == 'd' || o->format == 'i'))
		{
			str->str[0] = ' ';
		}
	}
}

void	ft_flag_precision(t_opt *o, t_str *str)
{
	int		prec;

	if (o->prec > 0)
	{
		if (ft_strchr(o->flag, '#') && (o->format == 'x' || o->format == 'X'))
			prec = o->prec + 2;
		else if (ft_atoi(str->str) >= 0)
			prec = o->prec;
		else
			prec = o->prec + 1;
		if (str->len < prec)
		{
			str->str = ft_t_str_malloc_rplus(str, prec, '0');
			str->len = prec;
		}
		if (ft_strchr(str->str, '-'))
		{
			*ft_strchr(str->str, '-') = '0';
			str->str[0] = '-';
		}
	}
	if ((ft_atoi(str->str) == 0) && (ft_strchr(o->flag, '.')) && o->prec == 0)
		str->len -= 1;
}
