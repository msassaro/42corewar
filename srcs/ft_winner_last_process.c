#include "../incs/corewar.h"
#include "../incs/virtual_machine.h"

static void					clear_winner(unsigned int nb_line,
		unsigned int nb_column, void *w_winner)
{
	unsigned int			y;
	unsigned int			x;

	y = 0;
	while (y < nb_line)
	{
		x = 0;
		while (x < nb_column)
			mvwprintw(w_winner, y, x++, " ");
		y++;
	}
}

static void					print_info_winner(void *w_winner)
{
	mvwprintw(w_winner, 1, (WIDTH_WINNER - 6) / 2, "WINNER");
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, NB_LINE_COLUMN / 2 - 1, (NB_LINE_COLUMN * 3 + 1) / 2 -
			2 / 2, "%s", "TEST");
	attroff(COLOR_PAIR(1));
}

void						pop_winner_last_process(t_vm *vm)
{
	unsigned int			y;
	unsigned int			x;

	refrech_win(vm);
	print_info(vm);
	print_grid(vm);
	y = (NB_LINE_COLUMN - HEIGHT_WINNER) / 2;
	x = ((NB_LINE_COLUMN * 3 + 1) - WIDTH_WINNER) / 2;
	vm->w_winner = subwin(stdscr, HEIGHT_WINNER, WIDTH_WINNER, y, x);
	clear_winner(y, x, vm->w_winner);
	print_info_winner(vm->w_winner);
	box(vm->w_winner, ACS_VLINE, ACS_HLINE);
	wrefresh(vm->w_winner);
	refresh();
	while (check_key(getch(), vm) != ESCAPE)
		;
	del_vm(&vm);
	exit(0);
}
