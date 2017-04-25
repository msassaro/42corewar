#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/05/17 16:07:18 by fpasquer          #+#    #+#             *#
#*   Updated: 2016/06/03 16:55:35 by fpasquer         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

GCC		= gcc
NAME	= corewar
NAME2	= asm

DATE		= `date +'%d/%m/%y %H:%M:%S'`
CFLAGS		= -Wall -Wextra -Werror

OBJ_NAME	= $(SRC_NAME:.c=.o)
SRC_NAME =	main.c util.c init_vm.c virtual_machin.c print_info.c save_player.c\
			ft_recover_name_comment_champ.c\
			ft_recover_instruction.c\
			ft_parse_instruction.c\
			ft_power.c\
			ft_llitoa_base.c\
			ft_processus.c\
			ft_check_processus_life.c\
			ft_llitoa_base2.c\
			ft_check_delais.c\
			fork.c\
			ft_param_octets.c\
			save_player2.c\
			ft_instruction_without_ocp.c\
			ft_print_param_to_array_4_octets.c\
			winner.c\
			st.c\
			util2.c\
			ft_winner_last_process.c\
			winner2.c\
			init_vm2.c\
			ft_operand_instruction.c\
			ft_other_instruction.c\
			ft_parse_info.c\
			ft_indirect_param.c\
			print_info1.c
			
OTHERS		= libft Makefile auteur exemple

NCURSE_FLAGS	= -lncurses
SRCDIR			= srcs
OBJDIR			= objs
INCDIR1			= -I incs/
INCDIR			= incs/
INCLUDES		= incs/virtual_machine.h incs/corewar.h

LIBRARY			= libft/libft.a

SRC = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJDIR)/, $(OBJ_NAME))



All : $(NAME)

$(NAME) : $(OBJ) $(LIBRARY)
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(NCURSE_FLAGS)
	@echo "\033[0;32mCOREWAR EXE: DONE\033[0m"
	@make -C compiler
	@mv compiler/asm .

$(LIBRARY) :
	@make -C libft

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) 
	$(GCC) $(INCDIR1) $(CFLAGS) -o $@ -c $<

clean :
	@rm -rf $(OBJ)
	@make -C compiler/ clean

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME2)
	@make -C libft fclear
	@make -C compiler/ fclean

re : fclean All

push	:	fclean
			git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
			git commit -m "$(DATE)"
#			echo "Enter Your Commit : "
#			read root_path ; git commit -m "$$root_path"
			git push

norm:
	norminette $(SRC) $(INC)

.PHONY: All clean fclean re norm


# NAME 		= corewar
# FLAGS		= -Wall -Werror -Wextra -g
# SRC 		= main.c util.c init_vm.c virtual_machin.c print_info.c save_player.c

# OTHERS		= libft Makefile auteur minilibx_macos exemple


# OBJ			= $(SRC:.c=.o)
# INC			= incs/virtual_machine.h
# LIBFLAGS	= -L./libft/ -lft -lncurses
# SRCDIR		= ./srcs/
# OBJDIR		= ./objs/
# INCDIRLIB	= ./libft/incs/
# INCDIR		= ./incs/
# SRCS		= $(addprefix $(SRCDIR), $(SRC))
# OBJS		= $(addprefix $(OBJDIR), $(OBJ))
# DATE		= `date +'%d/%m/%y %H:%M:%S'`
# # .SILENT:


# all : $(NAME)

# $(NAME) : $(OBJ) $(LIBFLAGS)

# $(LIBFLAGS) :
# 	Make -C libft

# $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INC)
# 	$(GCC) $(INCDIR) $(CFLAG) -o $@ -c $<


# all : 		$(NAME)

# $(NAME) :
# 	echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
# 	echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
# 	Make -C libft/
# 	gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INCDIRLIB)
# 	echo "compiling $(NAME)..."
# 	mkdir -p $(OBJDIR)
# 	mv $(OBJ) $(OBJDIR)
# #	gcc $(FLAGS) -o $(NAME) -I /usr/X11/include -g -L/usr/X11/lib -lX11 -lmlx -lXext -framework OpenGL -framework AppKit $(OBJS) $(LIBFLAGS)
# 	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
# 	echo "$(NAME) has been created !"

# .PHONY:		clean fclean re push exe

# clean :
# 			Make -C ./libft/ clear
# 			rm -rf $(OBJS)
# 			rm -rf $(OBJDIR)
# 			echo "objects files has been removed !"

# fclean :	clean
# 			Make -C ./libft/ fclear
# 			rm -rf $(NAME)
# 			echo "$(NAME) has been removed !"

# re		:	fclean all

# exe		:	re
# 	./$(NAME) 

# push	:	fclean
# 			git add $(SRCDIR) $(INCDIR) $(OTHERS) ./libft
# 			git commit -m "$(DATE)"
# #			echo "Enter Your Commit : "
# #			read root_path ; git commit -m "$$root_path"
# 			git push
