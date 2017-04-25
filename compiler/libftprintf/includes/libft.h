/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/18 11:05:45 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_str
{
	char			*str;
	int				len;
	int				alloc_len;
}					t_str;

/*
** str functions
*/

size_t				ft_strlen(const char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned in, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				**ft_free_strsplit(char **tab);
char				*ft_str_malloc_plus(char *str, int size, char c);
char				*ft_str_malloc_rplus(char *str, int size, char c);
char				*ft_str_replace_char(char *str, char old, char new_str);
int					ft_explode_count(char *line, char separator);
char				*ft_strcpy_startend(char *src, int start, int end);
char				*ft_remove_white_spaces(char *str, char c);

/*
** memory functions
*/

void				*ft_memalloc(size_t size);
void				*ft_memchr (const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr (const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
char				**ft_alloc_tab(int i, int j);

/*
** maths functions
*/

int					ft_sqrt(int nb);
int					ft_factorial(int nb);
long long			ft_power(long long nb, long long power);
int					ft_nbrlen(int nb);
int					ft_nbrlen_base(int nb, int len_base);

/*
** print functions
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_base(int nbr, char *base);
int					ft_print_ptr(unsigned long ptr);

/*
** checking functions
*/

int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_str_digit(char *str);
int					ft_str_alpha(char *str);

/*
** convert functions REVOIR LES {I,U}toa et base
*/

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
long long int		ft_long_atoi(const char *str);
int					ft_atoi_base(char *str, char *base);
char				*ft_itoa(long long n);
char				*ft_itoa_base(int nb, int len_base);
char				*ft_utoa(unsigned long long n);
int					ft_atoi_startend(const char *str, int start, int end);
char				*ft_itobase(unsigned long long int nb, const char *base);
int					ft_binary_to_dec(char *binary);

/*
** lst functions
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** fct relative to structure t_str
*/

char				*ft_t_str_malloc_plus(t_str *str, int size, char c);
char				*ft_t_str_malloc_rplus(t_str *str, int size, char c);

/*
** fct relative to get_next_line.c
*/

int					get_next_line(int const fd, char **line);

#endif
