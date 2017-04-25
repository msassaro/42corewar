/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_oxup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:19 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 19:20:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_flag_o(t_opt *opt, t_str *out, va_list *ap)
{
	unsigned long long int	nb;
	t_str					*str;

	str = malloc(sizeof(str));
	if (opt->format == 'O')
		nb = (long)va_arg(*ap, unsigned long int);
	else
		nb = ft_get_uarg(opt, ap);
	str->str = ft_itobase(nb, "01234567");
	str->len = (int)ft_strlen(str->str);
	if (ft_strchr(opt->flag, '#') && str->str)
	{
		if (str->str[0] != '0')
			str->str = ft_strjoin("0", str->str);
		if (ft_strchr(opt->flag, '.') || (nb != 0))
			str->len += 1;
	}
	ft_flag_precision(opt, str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}

static void	ft_flag_x_2(t_opt *opt, t_str *str)
{
	ft_flag_precision(opt, str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
}

int			ft_flag_x(t_opt *opt, t_str *out, va_list *ap)
{
	unsigned long long int	nb;
	t_str					*str;

	nb = ft_get_uarg(opt, ap);
	str = malloc(sizeof(str));
	str->str = ft_itobase(nb, "0123456789abcdef");
	str->len = ft_strlen(str->str);
	if ((ft_strchr(opt->flag, '#')) && (nb > 0))
	{
		str->str = ft_strjoin("0x", str->str);
		str->len += 2;
	}
	ft_flag_x_2(opt, str);
	if (ft_strchr(opt->flag, '#') && (nb > 0))
	{
		*ft_strchr(str->str, 'x') = '0';
		*(ft_strchr(str->str, '0') + 1) = 'x';
	}
	if (opt->format == 'X')
		str->str = ft_strmap(str->str, (char(*)(char))&ft_toupper);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}

int			ft_flag_u(t_opt *opt, t_str *out, va_list *ap)
{
	unsigned long long int	nb;
	t_str					*str;

	str = malloc(sizeof(str));
	if (opt->format == 'U')
		nb = (unsigned long)va_arg(*ap, unsigned long int);
	else
		nb = ft_get_uarg(opt, ap);
	str->str = ft_itobase(nb, "0123456789");
	str->len = ft_strlen(str->str);
	ft_flag_precision(opt, str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}

int			ft_flag_p(t_opt *opt, t_str *out, va_list *ap)
{
	long	nb;
	t_str	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(str));
	nb = (long)va_arg(*ap, long);
	str->str = ft_itobase(nb, "0123456789abcdef");
	str->len = ft_strlen(str->str);
	ft_flag_precision(opt, str);
	str->str = ft_strjoin("0x", str->str);
	str->len += 2;
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	if (ft_strchr(opt->flag, '0'))
	{
		*ft_strchr(str->str, 'x') = '0';
		str->str[1] = 'x';
	}
	ft_printf_add_string(opt, str->str, str->len, out);
	if (str->str != NULL)
		free(str->str);
	free(str);
	return (0);
}
