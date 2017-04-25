/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:49:33 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/19 14:33:51 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/virtual_machine.h"
#include "../incs/corewar.h"

#define Q count2 = 0; count = 0; t[1] = 0; t[0] = 0;
#define R ft_strdel(&tmp); count2++; count++; t[0] += 3;

static void					print_flags(t_vm *vm)
{
	mvwprintw(vm->w_info, 21 + vm->nb_player * 3 + 1, 3, "FLAGS :");
	if ((vm->flags & DUMP) != 0)
		mvwprintw(vm->w_info, 22 + vm->nb_player * 3 + 1, 5,
				"DUMP    : Yes / %d", vm->nb_dump);
	else
		mvwprintw(vm->w_info, 22 + vm->nb_player * 3 + 1, 5, "DUMP    : No");
	if ((vm->flags & SUSPEND) != 0)
		mvwprintw(vm->w_info, 23 + vm->nb_player * 3 + 1, 5,
				"SUSPEND : Yes / %d", vm->nb_susp);
	else
		mvwprintw(vm->w_info, 23 + vm->nb_player * 3 + 1, 5, "SUSPEND : No");
	mvwprintw(vm->w_info, 24 + vm->nb_player * 3 + 1, 5, "NUMBER  : %s",
			(vm->flags & NUMBER) != 0 ? "Yes" : "No");
	if ((vm->flags & DUMP_M) != 0)
		mvwprintw(vm->w_info, 25 + vm->nb_player * 3 + 1, 5,
				"DUMP_M  : Yes / %d", vm->nb_dump);
	else
		mvwprintw(vm->w_info, 25 + vm->nb_player * 3 + 1, 5, "DUMP_M  : No");
}

void						print_info(t_vm *vm)
{
	if ((vm->flags & VISU) == 0)
		return ;
	mvwprintw(vm->w_info, 2, 3, "** %s **  ", vm->status == PAUSE ?
			"PAUSED" : "RUNNNING");
	mvwprintw(vm->w_info, 4, 3, "Cyles/second limit : %d", CYCLE_SEG);
	mvwprintw(vm->w_info, 7, 3, "Cycle %u", vm->cycle);
	mvwprintw(vm->w_info, 9, 3, "Processes : %u         ", vm->nb_proces);
	print_players(vm);
	mvwprintw(vm->w_info, 13 + vm->nb_player * 3 + 1, 3,
			"Cycle to die : %u    ", vm->cycle_to_die);
	mvwprintw(vm->w_info, 15 + vm->nb_player * 3 + 1, 3, "Cycle delta : %d",
			CYCLE_DELTA);
	mvwprintw(vm->w_info, 17 + vm->nb_player * 3 + 1, 3, "NBR_LIVE : %d",
			NBR_LIVE);
	mvwprintw(vm->w_info, 19 + vm->nb_player * 3 + 1, 3, "MAX_CHECK : %d",
			MAX_CHECK);
	print_flags(vm);
	wrefresh(vm->w_info);
}

void						print_hightlight(t_vm *vm, t_player *plr)
{
	char					*tmp;
	int						size;

	while (plr)
	{
		attron(A_STANDOUT);
		attron(COLOR_PAIR(plr->pos));
		tmp = ft_llitoa_base(vm->array[plr->i_grid].code_hexa, 16, &size);
		mvwprintw(stdscr, vm->array[plr->i_grid].y, vm->array[plr->i_grid].x,
				"%s", tmp);
		attroff(A_STANDOUT);
		attroff(COLOR_PAIR(plr->pos));
		plr = plr->next;
		ft_strdel(&tmp);
	}
}

/*
**	t[0] = x
**	t[1] = y
*/

void						print_grid(t_vm *vm)
{
	unsigned int			t[2];
	int						size;
	char					*tmp;
	int						count;
	int						count2;

	Q;
	if ((vm->flags & VISU) == 0)
		return ;
	while (t[1] < NB_LINE_COLUMN)
	{
		init_pair(vm->array[count2].player, vm->array[count2].player,
				COLOR_BLACK);
		attron(COLOR_PAIR(vm->array[count2].player));
		tmp = ft_llitoa_base(vm->array[count].code_hexa, 16, &size);
		mvwprintw(stdscr, t[1] + 1, t[0] + 2, "%s ", tmp);
		vm->array[count].x = t[0] + 2;
		vm->array[count].y = t[1] + 1;
		attroff(COLOR_PAIR(vm->array[count2].player));
		R;
		if (t[0] > 190 && ++t[1])
			t[0] = 0;
	}
	print_hightlight(vm, vm->plr);
	wrefresh(vm->w_grid);
}
