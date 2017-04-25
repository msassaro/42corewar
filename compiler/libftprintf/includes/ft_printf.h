/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:01 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 20:08:52 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <wchar.h>

/*
** autorized FLAGS "0 -+#."
** autorized FORMAT "sSdDioOuUxXcCp%b"
** autorized LEN MODIF "hh,h,ll,l,j,z"
*/

# define PRINTF_FLAG	((char *)"#0+-. ")
# define PRINTF_FORMAT	((char *)"sSpdDioOuUxXcC%b")
# define PRINTF_LFLAG	((char *)"hljz")

typedef struct			s_format
{
	char				format;
	int					(*fct)();
}						t_format;

typedef struct			s_opt
{
	char				*flag;
	int					width;
	int					prec;
	char				format;
	char				*lflag;
}						t_opt;

typedef struct			s_typographic
{
	char				*type;
	char				*value;
}						t_typographic;

/*
** fct relative to ft_printf_detect.c
*/

void					ft_detect_flag(t_opt *opt, const char *fmt, int i);
void					ft_detect_width(t_opt *o, const char *fmt,
							va_list *ap, int i);
void					ft_detect_precision(t_opt *opt, const char *fmt, int i);
void					ft_detect_format(t_opt *opt, const char *fmt, int i);
void					ft_detect_lflag(t_opt *opt, const char *fmt, int i);

/*
** fct relative to ft_printf.c
*/

int						ft_printf_parse(t_str *o, const char *f, va_list *ap);
int						ft_printf(const char *format, ...);
char					*ft_sprintf(const char *format, ...);
int						ft_printf_fd(int fd, const char *format, ...);

/*
** fct relative to ft_printf_format_parse.c
*/

int						ft_printf_format(t_str *s, const char *fmt,
							va_list *ap, int i);

/*
** fct relative to ft_printf_stringarg.c
*/

void					ft_printf_add_string(t_opt *opt, char *add,
							int len, t_str *out);
void					ft_printf_add_char(t_str *out, char c);
long long int			ft_get_arg(t_opt *opt, va_list *ap);
unsigned long long int	ft_get_uarg(t_opt *opt, va_list *ap);
void					ft_flag_width(t_opt *opt, t_str *str);
void					ft_flag_zero(t_opt *opt, t_str *str);
void					ft_flag_precision(t_opt *opt, t_str *str);
void					ft_flag_space(long long int nb, t_opt *opt, t_str *str);
void					ft_flag_plus(long long int nb, t_opt *opt, t_str *str);

/*
** fct relative to ft_printf_format_cdbpercent.c
*/

int						ft_flag_percent(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_c(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_d(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_b(t_opt *opt, t_str *out, va_list *ap);

/*
** fct relative to ft_printf_format_s.c
*/

int						ft_flag_s(t_opt *opt, t_str *out, va_list *ap);

/*
** fct relative to ft_printf_format_s.c
*/

char					*ft_wstr_to_str(char **wstr, t_opt *opt,
							t_str *str_arg);

/*
** fct relative to ft_printf_format_oxup.c
*/

int						ft_flag_p(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_o(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_u(t_opt *opt, t_str *out, va_list *ap);
int						ft_flag_x(t_opt *opt, t_str *out, va_list *ap);

/*
** fct relative to ft_printf_bracket.c
*/

int						ft_printf_bracket(t_str *out, const char *fmt, int i);

/*
** fct relative to ft_printf_wchar.c
*/

t_str					*ft_printf_wchar(wchar_t wchar);

/*
** fct relative to ft_printf_wchar_2.c
*/

char					*ft_unicod_fill(char *wchar, char *unicod_mask);

#endif
