# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 07:15:52 by msassaro          #+#    #+#              #
#    Updated: 2016/06/20 11:41:42 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm

###############################################################################
# Libraries PATH and HEADER

LFTDIR			= libft/
LFTPFDIR		= libftprintf/
LFT				= libft/libft.a
LFTPF			= libftprintf/libftprintf.a
INCL			= -I./libft/includes/ -I./includes/ -I./libftprintf/includes/
LIBS			= ./libft/libft.a ./libftprintf/libftprintf.a

HEADER			= ./includes/asm.h ./includes/op.h ./libft/includes/libft.h\
				  ./libft/includes/get_next_line.h\
				  ./libftprintf/includes/ft_printf.h

###############################################################################
# Compiler and Flags

CC				= gcc
CFLAG			= -Wall -Wextra -Werror -O3
###############################################################################

SRCS			= \
			binary.c\
			check_after_storage.c\
			debug.c\
			debug2.c\
			debug3.c\
			encode.c\
			error.c\
			error2.c\
			filter_label.c\
			flags.c\
			flags2.c\
			ft_is.c\
			init.c\
			label_addr.c\
			main.c\
			parse_header.c\
			recup.c\
			recup2.c\
			set_addr_and_header.c\
			set_code_op_and_num_param.c\
			set_size_cmd.c\
			store_item.c\
			store_item2.c\
			store_item3.c\
			utils.c\
			utils2.c\
			utils3.c\
			write_infos_msg.c

###############################################################################
# Concat SRCDIR and SRCS to have the total path
# Creation of objects files

SRCDIR			= ./srcs/
SRC				= $(addprefix $(SRCDIR), $(SRCS))
OBJ				= $(SRC:.c=.o)

###############################################################################
# COLORS

BLUE			= \033[0;36m
GREEN			= \033[1;32m
RED				= \033[1;31m
EOC				= \033[0m
YELLOW			= \033[33m
WHITE			= \033[97m
BG_BLUE			= \033[44m

###############################################################################
# Layout

NAMING			= $(YELLOW)[$(NAME)]------------>
NAMING2			= $(YELLOW)[$(NAME)] >>>>>>>>>>> 

###############################################################################

all: $(NAME)

$(NAME): $(LFT) $(LFTPF) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBS)
	@echo ""
	@echo "$(NAMING2)[Compile: $(GREEN)DONE$(YELLOW)]$(EOC)"
	@echo " "
	@echo "   $(BG_BLUE)          $(EOC)    $(BG_BLUE)          $(EOC)    $(BG_BLUE)          $(EOC)    $(BG_BLUE)          $(EOC)"
	@echo "   $(BG_BLUE)  $(EOC)            $(BG_BLUE)  $(EOC)      $(BG_BLUE)  $(EOC)    $(BG_BLUE)  $(EOC)      $(BG_BLUE)  $(EOC)    $(BG_BLUE)  $(EOC)"
	@echo "   $(BG_BLUE)  $(EOC)            $(BG_BLUE)  $(EOC)      $(BG_BLUE)  $(EOC)    $(BG_BLUE)          $(EOC)    $(BG_BLUE)          $(EOC)"
	@echo "   $(BG_BLUE)  $(EOC)            $(BG_BLUE)  $(EOC)      $(BG_BLUE)  $(EOC)    $(BG_BLUE)  $(EOC)  $(BG_BLUE)  $(EOC)        $(BG_BLUE)  $(EOC)"
	@echo "   $(BG_BLUE)          $(EOC)    $(BG_BLUE)          $(EOC)    $(BG_BLUE)  $(EOC)    $(BG_BLUE)    $(EOC)    $(BG_BLUE)          $(EOC)"
	@echo " "
	@echo "$(BG_BLUE)                                                          $(EOC)"
	@echo "$(BG_BLUE)$(WHITE)                       ASM Corewar                        $(EOC)"
	@echo "$(BG_BLUE)$(WHITE)               fpasquer   jllosa   msassaro               $(EOC)"
	@echo "$(BG_BLUE)                                                          $(EOC)"
	@echo " "

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCL) -o $@ -c $<
	@echo "$(YELLOW)█$(EOC)\c"

$(LFT):
	@make -C $(LFTDIR)

$(LFTPF):
	@make -C $(LFTPFDIR)

clean:
	@make -C $(LFTDIR) clean
	@make -C $(LFTPFDIR) clean
	@rm -f $(OBJ)
	@echo "$(NAMING)[Clean:   $(GREEN)DONE$(YELLOW)]$(EOC)"

fclean: clean
	@make -C $(LFTDIR) fclean
	@make -C $(LFTPFDIR) fclean
	@rm -f $(NAME)
	@echo "$(NAMING)[Fclean:  $(GREEN)DONE$(YELLOW)]$(EOC)"

re: fclean all

.PHONY: all lib1 lib2 clean fclean re design
