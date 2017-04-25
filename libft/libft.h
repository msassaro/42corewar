/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 21:31:48 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/06 20:35:00 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define DEDANS 1
# define DEHORS 0

# define HEAD 1
# define TAIL 2

/*
** Color pour la fonction ft_printcolor_str.
*/

# define BLACK 30
# define RED 31
# define GREEN 32
# define YELLOW 33
# define BLUE 34
# define MAGENTA 35
# define CYAN 36
# define WHITE 37
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5211

typedef struct		s_file
{
	int				fd;
	char			*l;
	unsigned int	nb_file;
	struct s_file	*next;
}					t_file;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**Partie 1
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t buff_dest);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule, const char *aiguille);
char				*ft_strnstr(const char *meule, const char
						*aiguille, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long int		ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**Partie 2
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int nb);
void				ft_putchar(char c);
size_t				ft_putstr(const char *s);
size_t				ft_putendl(const char *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(unsigned char c, int fd);
size_t				ft_putstr_fd(const char *s, int fd);
size_t				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);

/*
**Partie 3
*/

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nnew);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	bibliotheque perso
*/

unsigned int		ft_strlen_wout_spc_be(const char *s);
char				**ft_free_strsplit(char **tab);
char				*ft_itoa_base(long long int nb, const unsigned int base);
char				*ft_utoa_base(unsigned long long int nb,
		const unsigned int base);
void				*ft_move_octe(void *s, char del, size_t n);
void				ft_error(const char *s);
int					ft_fopen(const char *name, const char *mode);
char				*ft_gets_stdin(char *buff, size_t n);
double				ft_get_decimal(const double nb, double *decimal);
int					ft_isspace(int c);
double				ft_pow(double nb, int exp);
char				*ft_strndup(const char *s, size_t len);
void				ft_print_adr_fd(void *adr, int fd);
void				ft_print_adr(void *adr);
void				ft_printcolor(int color, char *str, size_t n);
void				ft_clrscr(void);

/*
** Utilisation de la library time pour ft_rand()
**		Obligatoire pour randome
** Utilisation de la library arg pour ft_multijoin()
**		include otorise dans le projet ft_printf
*/

int					ft_rand(int min, int max);
char				*ft_multijoin(unsigned int nb_arg, ...);
void				*ft_memjoin(const void *src1, size_t n_src1, const
		void *src2, size_t n_src2);
int					get_next_line(int fd, char **line);
unsigned int		get_y(const char *s, char c);
long long int		ft_abs(long long int nb);
char				*ft_strdup_and_len(const char *s, size_t *len);
size_t				ft_nblen(long long int nb);
size_t				len_y(char **tab);

char				**join_tab2d_str(char **tab, char *str, int where);
char				**join_2_tabs_2d(char **tab1, char **tab2);
char				**ft_strsplit_guil(char *s, char c);
int					ft_is_number(char *s);
int					ft_atoi_base(const char *s, int base, int *nb);

#endif
