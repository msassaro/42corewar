/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 21:31:48 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/20 11:27:41 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

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

#endif
