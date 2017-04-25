/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_str_malloc_plus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:57:13 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 16:39:49 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_parse(t_str *out, const char *fmt, va_list *ap)
{
	int		i;
	int		keep;

	i = 0;
	while (fmt[i])
	{
		keep = 0;
		if (fmt[i] == '%')
		{
			keep = ft_printf_format(out, fmt, ap, i + 1);
			if (keep != -1)
				i += keep;
			else
				return (-1);
		}
		else if (fmt[i] == '{')
			i += ft_printf_bracket(out, fmt, i + 1);
		else
			ft_printf_add_char(out, fmt[i]);
		i++;
	}
	return (0);
}

/*
** this is the starting fct we create out for the output
*/

int		ft_printf(const char *format, ...)
{
	t_str		*out;
	va_list		ap;
	int			len;

	out = (t_str*)malloc(sizeof(out));
	out->len = 0;
	out->alloc_len = ft_strlen(format);
	out->str = ft_memalloc(ft_strlen(format));
	va_start(ap, format);
	if (ft_printf_parse(out, format, &ap) == -1)
	{
		va_end(ap);
		free(out->str);
		free(out);
		return (-1);
	}
	write(1, out->str, out->len);
	len = out->len;
	va_end(ap);
	free(out->str);
	free(out);
	return (len);
}

char	*ft_sprintf(const char *format, ...)
{
	t_str		*out;
	char		*str_result;
	va_list		ap;

	out = (t_str*)malloc(sizeof(out));
	out->len = 0;
	out->alloc_len = ft_strlen(format);
	out->str = ft_memalloc(ft_strlen(format));
	va_start(ap, format);
	if (ft_printf_parse(out, format, &ap) == -1)
	{
		va_end(ap);
		free(out->str);
		free(out);
		return (NULL);
	}
	str_result = (char*)ft_memalloc(sizeof(char) * out->len + 1);
	ft_memcpy(str_result, out->str, out->len);
	free(out->str);
	free(out);
	va_end(ap);
	return (str_result);
}

int		ft_printf_fd(int fd, const char *format, ...)
{
	t_str		*out;
	va_list		ap;
	int			len;

	out = (t_str*)malloc(sizeof(out));
	out->len = 0;
	out->alloc_len = ft_strlen(format);
	out->str = ft_memalloc(ft_strlen(format));
	va_start(ap, format);
	if (ft_printf_parse(out, format, &ap) == -1)
	{
		va_end(ap);
		free(out->str);
		free(out);
		return (-1);
	}
	write(fd, out->str, out->len);
	len = out->len;
	va_end(ap);
	free(out->str);
	free(out);
	return (len);
}
