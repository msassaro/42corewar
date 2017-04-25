/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stringarg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:30 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:38:20 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_printf_add_string(t_opt *opt, char *add, int len,
						t_str *out)
{
	out->str = ft_t_str_malloc_plus(out, out->len + len, 0);
	ft_memcpy(out->str + out->len, add, len);
	out->len += len;
	(void)opt;
}

void					ft_printf_add_char(t_str *out, char c)
{
	out->str = ft_t_str_malloc_plus(out, out->len + 1, 0);
	out->str[out->len] = c;
	out->len += 1;
}

long long int			ft_get_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->lflag, "hh"))
		return ((long long int)(signed char)(va_arg(*ap, int)));
	if (ft_strequ(opt->lflag, "h"))
		return ((long long int)(short)(va_arg(*ap, int)));
	if (ft_strequ(opt->lflag, "ll"))
		return ((long long int)(va_arg(*ap, long long)));
	if (ft_strequ(opt->lflag, "l"))
		return ((long long int)(va_arg(*ap, long)));
	if (ft_strequ(opt->lflag, "j"))
		return ((long long int)(va_arg(*ap, intmax_t)));
	if (ft_strequ(opt->lflag, "z"))
		return ((long long int)(va_arg(*ap, long)));
	return ((long long int)(va_arg(*ap, int)));
}

unsigned long long int	ft_get_uarg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->lflag, "hh"))
		return ((unsigned long long int)(unsigned char)(va_arg(*ap, int)));
	if (ft_strequ(opt->lflag, "h"))
		return ((unsigned long long int)(unsigned short)(va_arg(*ap, int)));
	if (ft_strequ(opt->lflag, "ll"))
		return ((unsigned long long int)(va_arg(*ap, unsigned long long)));
	if (ft_strequ(opt->lflag, "l"))
		return ((unsigned long long int)(va_arg(*ap, unsigned long)));
	if (ft_strequ(opt->lflag, "j"))
		return ((unsigned long long int)(va_arg(*ap, uintmax_t)));
	if (ft_strequ(opt->lflag, "z"))
		return ((unsigned long long int)(va_arg(*ap, unsigned long)));
	return ((unsigned long long int)(va_arg(*ap, unsigned int)));
}
