/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:57:41 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/04 10:26:18 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H

# define VIRTUAL_MACHINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <ncurses.h>

# define NB_CASE_TAB 4096
# define NB_LINE_COLUMN 64

# define MAX_REG 16

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

typedef struct				s_player
{
	/*
	** RAJOUT PAR JC
	*/

	int 					do_instruction;
	int 					delais;

	/*
	**
	*/

	char					*name;			//nom du joueur
	char					*comment;		//commentaire du joueur
	unsigned char			color;			//couleur du joueur pour la grille
	int						reg[MAX_REG];	//les 16 registres du joueur
	int						nb_player;		//nb_representant le joueur
	unsigned int			i_grid;			//index dans la grille
	unsigned int			nb_live;		//nb de live dans le cicle
	unsigned int			last_live;		//cicle du last live
	unsigned int			i_player;		//index du joueur pour comter live
	int						size;			//taille du champion
	struct s_player			*next;			//pour les forks
}							t_player;

typedef struct				s_array
{
	unsigned char			code_hexa;			//code exa de la case
	unsigned char			player;				//nb du joueur a qui est la case
}							t_array;

typedef struct				s_vm
{
	/*
	** RAJOUT PAR JC
	*/

	unsigned int 			cycle_tmp;			// compteur s'incremente jusqu'a cycle_to_die puis reset a 0;
	unsigned int 			check_max;

	/*
	**
	*/

	int						status;				//run ou pause
	int						*grid;				//grille 1d pour JC
	int						**grid2d;			//dito grid en 2d
	int						nb_dump;			//dump memoire / les nb_dump cycle
	int						nb_susp;			//suspend memoire / les nb_susp cycle
	int						flags;				//flags
	int						fd;					//ou sera dump la memoire
	unsigned int			nb_player;			//nombre de joueur de la partie
	unsigned int			cycle;				//nb de cycle
	unsigned int			cycle_to_die;		//nb de cycle_to_die
	unsigned int			nb_live;			//pour compter le nombre de live
	unsigned long long int	nb_proces;			//nb Processes
	unsigned long long int	pause;				//pour gerer SUSPEND
	unsigned long long int	dump;				//pour gerer DUMP
	t_array					array[NB_CASE_TAB];	//tableau memoire instruction
	t_player				*plr;				//tableau de joueur
	WINDOW					*w_grid;			//affichage de la grille ncurses
	WINDOW					*w_info;			//affichage des infos courante
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

#endif
