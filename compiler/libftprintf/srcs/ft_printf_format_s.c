/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:26 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 19:59:02 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_wstrlen(wchar_t *wstr)
{
	int		i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

static char		*ft_wstr_get(va_list *ap, t_opt *opt, t_str *str_arg)
{
	char		**str;
	wchar_t		*wstr;
	int			i;

	i = 0;
	wstr = (wchar_t*)va_arg(*ap, wchar_t*);
	if (wstr == NULL)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (ft_wstrlen(wstr) * 4) + 1);
	while (wstr[i])
	{
		str[i] = (ft_printf_wchar(wstr[i]))->str;
		i++;
	}
	str[i] = NULL;
	return (ft_wstr_to_str(str, opt, str_arg));
}

int				ft_flag_s(t_opt *opt, t_str *out, va_list *ap)
{
	t_str	*str;

	str = malloc(sizeof(str));
	str->len = 0;
	if (ft_strequ(opt->lflag, "l") || opt->format == 'S')
		str->str = ft_wstr_get(ap, opt, str);
	else
		str->str = (char*)va_arg(*ap, char*);
	if (str->str == NULL)
		str->str = "(null)";
	if (str->str && !ft_strchr(opt->flag, '.'))
		str->len = ft_strlen(str->str);
	else if (ft_strchr(opt->flag, '.') && opt->format == 's')
		str->len = (opt->prec < (int)ft_strlen(str->str)) ? opt->prec
			: ft_strlen(str->str);
	ft_flag_width(opt, str);
	ft_flag_zero(opt, str);
	ft_printf_add_string(opt, str->str, str->len, out);
	free(str);
	return (0);
}
