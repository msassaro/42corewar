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

NAME			= libftprintf.a

INCLUDE			= includes/
CFLAGS			= -O3 -Wall -Werror -Wextra
CC				= $(SILENCE)gcc

SRCS			= \
			ft_printf.c\
			ft_printf_bracket.c\
			ft_printf_detect.c\
			ft_printf_flag.c\
			ft_printf_format_cdbpercent.c\
			ft_printf_format_oxup.c\
			ft_printf_format_parse.c\
			ft_printf_format_s.c\
			ft_printf_format_s_2.c\
			ft_printf_stringarg.c\
			ft_printf_wchar.c\
			ft_printf_wchar_2.c\

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

COLOR1			= \033[0;36m
COLOR2			= \033[1;32m
COLOR3			= \033[1;31m
EOC				= \033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(COLOR1)[$(NAME)]-->[Compile: $(COLOR2)DONE$(COLOR1)]$(EOC)"
	@echo "$(COLOR1)[$(NAME)]-->[Build Lib:$(COLOR2)"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(COLOR1)[$(NAME)]-->[Build:   $(COLOR2)DONE$(COLOR1)]$(EOC)"

%.o: %.c
	@echo "$(COLOR1)[$(NAME)]-->[Compile:$(COLOR3)$<\033[A\033[0m"
	@echo "$(COLOR2)"
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "$(COLOR3) [working]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(COLOR1)[$(NAME)]-->[Clean]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(COLOR1)[$(NAME)]-->[Clean:\033[1;32m   DONE$(COLOR1)]\033[0m"

fclean: clean
	@echo "$(COLOR1)[$(NAME)]-->[Fclean]\033[0;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(COLOR1)[$(NAME)]-->[Fclean:\033[1;32m  DONE$(COLOR1)]\033[0m"

re: fclean all

.PHONY: clean fclean
