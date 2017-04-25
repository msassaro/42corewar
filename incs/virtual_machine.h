/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:57:41 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/19 19:17:12 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H

# define VIRTUAL_MACHINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <ncurses.h>

# define WIDTH_WINNER 44
# define HEIGHT_WINNER 12

# define NB_CASE_TAB 4096
# define NB_MOD 512
# define NB_LINE_COLUMN 64

# define LEN_NAME 20

# define MAX_REG 17

# define MAX_PLAYER 4

# define WIDTH_INFO 60

# define PAUSE 0
# define RUN 1

# define ESCAPE 27
# define SPACE 32

# define CYCLE_SEG 50

# define REFRESH 10

# define INIT_CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECK 10

# define COLOR_0 "\033[0;31m"
# define COLOR_1 "\033[0;32m"
# define COLOR_2 "\033[0;33m"
# define COLOR_3 "\033[0;34m"

# define MY_MAX_LEN_NAME 20

/*
**	Flags:
**		_ Dump la memoire tout les x cycles
**			[-d 12] : dump la memoire tout les 12 cycles
**		_ Number Permet de preciser pour chaque joueur leur nombre atribue
**			[-n 20 joueur_name] attribue le nombre 20 a joueur_name
**			Si 1 -n est utilise, lensemble des joueurs doivent avoir un nombre
**		_ Visu active le mode d'affichage avec les Ncurses
**			[-v]
**		_ Dump et met en pause le programme tout les x cycles
**			[-s 35]
*/

# define NONE 0
# define DUMP 1
# define NUMBER 2
# define VISU 4
# define SUSPEND 8
# define DUMP_M 16

# define NAME_FILE_DUMP_MEM "dump_memory.txt"

/*
**	typedef struct				s_info
**	{
**	int		epd;
**	int		nb_arg;
**	int		instruction;
**	int		ocp;					//ocp
**	int		size_ocp_param;			//size des X parametres.
**	int		size_ocp_param2;
**	int		t_f_param; 				//t = type, f = first
**	int		t_s_param;				//t = type, s = second
**	int		t_t_param;				//t = type, t = third
**	int		s_f_param;				//s = size
**	int		s_s_param;				//s = size
**	int		s_t_param;				//s = size
**	int		nb_f_param;				//valeur du parametre 1
**	int		nb_s_param;				//valeur du parametre 2
**	int		nb_t_param;				//valeur du parametre 3
**	int		index_ocp;				//index de l'ocp dans la grille.
**	int		index_f_param;			//index de du 1 parametre dans la grille.
**	int		index_s_param;			//index de du 2 parametre dans la grille.
**	int		index_t_param;			//index de du 3 parametre dans la grille.
**	int		reg_f;					//numero du registre.
**	int		reg_s;
**	int		reg_t;
**	int		error;
**}							t_info;
*/

typedef struct				s_info
{
	int						epd;
	int						nb_arg;
	int						instruction;
	int						ocp;
	int						size_ocp_param;
	int						size_ocp_param2;
	int						t_f_param;
	int						t_s_param;
	int						t_t_param;
	int						s_f_param;
	int						s_s_param;
	int						s_t_param;
	int						nb_f_param;
	int						nb_s_param;
	int						nb_t_param;
	int						index_ocp;
	int						index_f_param;
	int						index_s_param;
	int						index_t_param;
	int						reg_f;
	int						reg_s;
	int						reg_t;
	int						error;
}							t_info;

/*
**typedef struct				s_player
**{
**	instruction;
**	do_instruction;
**	delais;
**	pos; 			//numero du joueur par rapport au start.
**	*name;			//nom du joueur
**	comment;		//commentaire du joueur
**	reg[MAX_REG];	//les 16 registres du joueur
**	process;		//process
**	i_grid;			//index dans la grille
**	nb_live;		//nb de live dans le cicle
**	last_live;		//cicle du last live
**	i_player;		//index du joueur pour comter live
**	size;			//taille du champion
**	carry;
**	info;
**	*next;			//pour les forks
**	*prev;			//?
**}							t_player;
*/

typedef struct				s_player
{
	char					instruction;
	int						do_instruction;
	unsigned int			delais;
	int						pos;
	char					*name;
	char					*comment;
	unsigned int			reg[MAX_REG];
	unsigned int			process;
	unsigned int			i_grid;
	unsigned int			nb_live;
	unsigned int			last_live;
	unsigned int			cycle_last_live;
	unsigned int			i_player;
	int						size;
	int						carry;
	t_info					info;
	struct s_player			*next;
	struct s_player			*prev;
}							t_player;

/*
**	typedef struct				s_array
**{
**	code_hexa;			//code exa de la case
**	player;				//nb du joueur a qui est la case
**	x;
**	y;
**}							t_array;
*/

typedef struct				s_array
{
	unsigned char			code_hexa;
	unsigned char			player;
	int						x;
	int						y;
}							t_array;

/*
**	typedef struct				s_vm
**	{
**	name_j[MAX_PLAYER][LEN_NAME + 1];//affiche le nom des joueurs
**	cycle_tmp;			// compteur s'incremente jusqu'a cycle_to_die et rest 0
**	check_max;
**	*array_pos;
**	count_pos;
**	status;				//run ou pause
**	*grid;				//grille 1d pour JC
**	**grid2d;			//dito grid en 2d
**	nb_dump;			//dump memoire / les nb_dump cycle
**	nb_susp;			//suspend memoire / les nb_susp cycle
**	flags;				//flags
**	fd;					//ou sera dump la memoire
**	nb_rep_plr[MAX_PLAYER];			//affichage du nombre representant le joueur
**	nb_player;			//nombre de joueur de la partie
**	cycle;				//nb de cycle
**	cycle_to_die;		//nb de cycle_to_die
**	nb_live;			//pour compter le nombre de live
**	nb_live_each_plr[MAX_PLAYER];// Pour afficher le nombre de live fork compris
**	cycle_last_live[MAX_PLAYER];// pour afficher le cycle du dernier live
**	nb_proces;			//nb Processes
**	pause;				//pour gerer SUSPEND
**	dump;				//pour gerer DUMP
**	array[NB_CASE_TAB];	//tableau memoire instruction
**	*plr;				//tableau de joueur
**	*w_grid;			//affichage de la grille ncurses
**	*w_info;			//affichage des infos courante
**	*w_winner;			//affiche le winner
**	}							t_vm;
*/

typedef struct				s_vm
{
	char					name_j[MAX_PLAYER][LEN_NAME + 1];
	unsigned int			cycle_tmp;
	unsigned int			check_max;
	int						*array_pos;
	int						count_pos;
	int						status;
	int						*grid;
	int						**grid2d;
	int						nb_dump;
	int						nb_susp;
	int						flags;
	int						fd;
	int						nb_rep_plr[MAX_PLAYER];
	unsigned int			nb_player;
	unsigned int			cycle;
	unsigned int			cycle_to_die;
	unsigned int			nb_live;
	unsigned int			nb_live_each_plr[MAX_PLAYER];
	unsigned int			cycle_last_live[MAX_PLAYER];
	unsigned long long int	nb_proces;
	unsigned long long int	pause;
	unsigned long long int	dump;
	t_array					array[NB_CASE_TAB];
	t_player				*plr;
	t_player				last_del;
	t_player				base[NB_CASE_TAB];
	WINDOW					*w_grid;
	WINDOW					*w_info;
	WINDOW					*w_winner;
	char					ff;
}							t_vm;

void						error(char *s);
t_vm						*init_vm(int argc, char **argv);
t_vm						*del_vm(t_vm **vm);
void						refrech_win(t_vm *vm);
void						loop_virtual_machin(t_vm *vm);
int							check_key(int key, t_vm *vm);
int							**make_tab_2d(int *tab, int height, int width);
void						print_grid(t_vm *vm);
void						print_info(t_vm *vm);
void						print_dump(t_vm *vm);
t_player					*save_player(int argc, char **argv, t_vm *vm);
t_player					*del_player(t_player **lst);
int							change_index(int i, char *argv, int argc);
int							change_index2(t_vm *vm, int i, char **argv,
		int argc);
void						pop_winner(t_vm *vm);
unsigned int				get_new_index(int decalage, unsigned int i_grid,
		t_vm *vm);
unsigned int				get_new_index_with_mod(int decalage,
		unsigned int i_grid, t_vm *vm);
void						dump_print_player(t_vm *vm, int fd);
void						print_show(t_vm *vm, char *fonction_name,
		unsigned int process);
void						init_ncurse(t_vm *vm);
void						init_affichage(t_vm *vm);
t_player					*get_winner2(t_vm *vm);
void						print_players(t_vm *vm);
void						copy_player(t_vm *vm);

#endif
