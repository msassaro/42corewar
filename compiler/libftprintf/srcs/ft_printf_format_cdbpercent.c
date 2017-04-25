/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_cdbpercent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:16 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:36:17 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_percent(t_opt *opt, t_str *out, va_list *ap)
{
	t_str	*str;
	int		len;

	if (opt->width > 1)
		len = opt->width;
	else
		len = 1;
	str = malloc(sizeof(str));
	str->str = ft_memalloc(1);
	str->str[0] = '%';
	str->len = ft_strlen(str->str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	(void)ap;
	return (0);
}

int		ft_flag_c(t_opt *opt, t_str *out, va_list *ap)
{
	t_str	*str;
	t_str	*wchar;

	str = malloc(sizeof(str));
	if (ft_strequ(opt->lflag, "l") || opt->format == 'C')
	{
		wchar = ft_printf_wchar((va_arg(*ap, wchar_t)));
		str->str = wchar->str;
		str->len = wchar->len;
	}
	else
	{
		str->len = 1;
		str->str = ft_memalloc(1);
		str->str[0] = (char)va_arg(*ap, int);
	}
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}

int		ft_flag_d(t_opt *opt, t_str *out, va_list *ap)
{
	t_str			*str;
	long long int	nb;

	str = malloc(sizeof(str));
	if (opt->format == 'D')
		nb = (long)va_arg(*ap, unsigned long int);
	else
		nb = ft_get_arg(opt, ap);
	str->str = ft_itoa(nb);
	str->len = ft_strlen(str->str);
	ft_flag_precision(opt, str);
	ft_flag_space(nb, opt, str);
	ft_flag_plus(nb, opt, str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}

int		ft_flag_b(t_opt *opt, t_str *out, va_list *ap)
{
	int		nb;
	t_str	*str;

	str = malloc(sizeof(str));
	nb = (int)va_arg(*ap, int);
	str->str = ft_itobase(nb, "01");
	str->len = (int)ft_strlen(str->str);
	ft_flag_precision(opt, str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}
