/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 10:32:51 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/19 14:39:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/virtual_machine.h"

static void					init_color_grid(t_vm *vm)
{
	vm->ff = 0;
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
}

void						refrech_win(t_vm *vm)
{
	clear();
	vm->w_grid = subwin(stdscr, NB_LINE_COLUMN + 2, NB_LINE_COLUMN * 2 +
			NB_LINE_COLUMN + 3, 0, 0);
	vm->w_info = subwin(stdscr, NB_LINE_COLUMN + 2, WIDTH_INFO, 0,
			NB_LINE_COLUMN * 2 + NB_LINE_COLUMN + 3);
	box(vm->w_grid, ACS_VLINE, ACS_HLINE);
	box(vm->w_info, ACS_VLINE, ACS_HLINE);
	wrefresh(vm->w_grid);
	wrefresh(vm->w_info);
	refresh();
}

void						init_affichage(t_vm *vm)
{
	unsigned int			i;
	t_player				*curs;

	i = 0;
	curs = vm->plr;
	while (i < vm->nb_player && i < MAX_PLAYER && curs != NULL)
	{
		ft_strncpy(vm->name_j[i], curs->name, LEN_NAME);
		vm->nb_rep_plr[i++] = curs->reg[1];
		curs = curs->next;
	}
}

void						init_ncurse(t_vm *vm)
{
	if ((vm->flags & VISU) != 0)
	{
		initscr();
		noecho();
		start_color();
		init_color_grid(vm);
	}
}

void						copy_player(t_vm *vm)
{
	unsigned int			i;
	t_player				*curs;

	if (vm == NULL)
		return ;
	i = 0;
	curs = vm->plr;
	while (i < vm->nb_player && curs != NULL)
	{
		ft_memcpy(&vm->base[i++], curs, sizeof(t_player));
		curs = curs->next;
	}
}
