# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 21:49:10 by fpasquer          #+#    #+#              #
#*   Updated: 2016/03/13 09:23:30 by fpasquer         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = libft.h

ADD = Makefile auteur

DATE = $(LOGPATH) `date +'%y/%m/%d %H:%M:%S'`

SRC = ft_atoi.c ft_bzero.c ft_clrscr.c ft_error.c ft_fopen.c ft_free_strsplit.c	\
	ft_get_decimal.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c		\
	ft_isprint.c ft_isspace.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstdel.c	\
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c			\
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memjoin.c	\
	ft_memmove.c ft_memset.c ft_multijoin.c ft_pow.c ft_print_adr.c				\
	ft_print_adr_fd.c ft_printcolor.c ft_putchar.c ft_putchar_fd.c ft_putendl.c	\
	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c		\
	ft_rand.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c		\
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c	\
	ft_strlcat.c ft_strlen.c ft_strlen_wout_spc_be.c ft_strmap.c ft_strmapi.c	\
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c\
	ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	ft_tolower.c ft_toupper.c ft_utoa_base.c get_next_line.c get_y.c ft_abs.c	\
	ft_nblen.c len_y.c ft_strsplit_guil.c ft_is_number.c ft_atoi_base.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clear:
	rm -rf $(OBJ)

fclear: clear
	rm -rf $(NAME)

re: fclear all

norminette:
	norminette $(SRC) $(HEAD)

push: fclear
	git add $(SRC) $(HEAD) $(ADD)
	git commit -m "$(DATE)"
	git push

.PHONY: all clear fclear re norminette push
