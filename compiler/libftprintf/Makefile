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
CFLAGS			= -Wall -Werror -Wextra
CC				= gcc

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

LIB				= ar rc

################################################################################

BLUE			= \033[0;34m
LIGHTBLUE		= \033[0;36m
GREEN			= \033[1;32m
RED				= \033[1;31m
EOC				= \033[0m
YELLOW			= \033[33m
WHITE			= \033[97m
BG_BLUE			= \033[44m

ABOVE			= \033[A	# print on the line above
ERASE			= \033[2K	# erase the line and go to next line

NAMING			= $(LIGHTBLUE)[ $(NAME) ]   ▶ 

################################################################################

all: $(NAME)

$(NAME):$(OBJS)
	@echo "$(NAMING)Compile $(GREEN)✔$(EOC)"
	@$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAMING)$(GREEN)LIBFTPRINTF DONE ✔$(EOC)"

%.o: %.c
	@echo "$(NAMING)Compile $(LIGHTBLUE) $< $(ABOVE)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<
	@echo "$(NAMING)Compile"
	@echo "$(ABOVE) $(ERASE) $(ABOVE)"

clean:
	@/bin/rm -rf $(OBJS)
	@echo "$(NAMING)Clean   ✔$(EOC)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(NAMING)Fclean  ✔$(EOC)"

re: fclean all

#.SILENT = everything is silent
#.SILENT :

#.PHONY = to be sure make will run in case a filename = rule
.PHONY: clean fclean re 
