# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 18:12:18 by msassaro          #+#    #+#              #
#    Updated: 2015/12/29 18:21:09 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

INCLUDE			= includes/
CFLAGS			= -O3 -Wall -Werror -Wextra
CC				= $(SILENCE)gcc

SRCS	= \
			ft_alloc_tab.c\
			ft_atoi.c\
			ft_atoi_base.c\
			ft_atoi_startend.c\
			ft_binary_to_dec.c\
			ft_bzero.c\
			ft_factorial.c\
			ft_free_strsplit.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_itoa_startend.c\
			ft_itobase.c\
			ft_long_atoi.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_nbrlen.c\
			ft_nbrlen_base.c\
			ft_power.c\
			ft_print_ptr.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_base.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_sqrt.c\
			ft_str_malloc_plus.c\
			ft_str_malloc_rplus.c\
			ft_str_replace_char.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strndup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strrev.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_t_str_malloc_plus.c\
			ft_t_str_malloc_rplus.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_utoa.c\
			get_next_line.c\
			ft_str_digit.c\
			ft_str_alpha.c\
			ft_explode_count.c\
			ft_remove_white_spaces.c\
			ft_remove_char.c\
			ft_replace_char_by.c\
			ft_strcpy_startend.c

SRCDIR			= ./srcs/
SRC				= $(addprefix $(SRCDIR), $(SRCS))
OBJS			= $(SRC:.c=.o)

V				= 0
SILENCE_1		:=
SILENCE_0		:=@
SILENCE			= $(SILENCE_$(V))

LIB				= $(SILENCE)ar rc
RM				= $(SILENCE)rm -rf

SKIP_1 			:=
SKIP_0 			:= \033[A
SKIP 			= $(SKIP_$(V))

COLOR1			= \033[0;34m
COLOR2			= \033[1;32m
COLOR3			= \033[1;31m
EOC				= \033[0m

NAMING			= $(COLOR1)[$(NAME)]-------->

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(NAMING)[Compile: $(COLOR2)DONE$(COLOR1)]$(EOC)"
	@echo "$(NAMING)[Build Lib:$(COLOR2)"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(NAMING)[Build:   $(COLOR2)DONE$(COLOR1)]$(EOC)"

%.o: %.c
	@echo "$(NAMING)[Compile:$(COLOR3)$<\033[A\033[0m"
	@echo "$(COLOR2)"
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "$(COLOR3) [working]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(NAMING)[Clean]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(NAMING)[Clean:\033[1;32m   DONE$(COLOR1)]\033[0m"

fclean: clean
	@echo "$(NAMING)[Fclean]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(NAMING)[Fclean:\033[1;32m  DONE$(COLOR1)]\033[0m"

re: fclean all

.PHONY: clean fclean
