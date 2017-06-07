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

static void					print_info_winner(void *w_winner, t_player *plr)
{
	mvwprintw(w_winner, 1, (WIDTH_WINNER - 6) / 2, "WINNER");
	attron(COLOR_PAIR(plr->pos));
	mvwprintw(stdscr, NB_LINE_COLUMN / 2 - 1, (NB_LINE_COLUMN * 3 + 1) / 2 -
			ft_strlen(plr->name) / 2, "%s", plr->name);
	attroff(COLOR_PAIR(plr->pos));
}

static int					is_end(t_vm *vm)
{
	if (vm->nb_proces == 0)
		return (1);
	if (vm->cycle_to_die == 4294967282)
	{
		vm->cycle_to_die = 0;
		return (1);
	}
	return (0);
}

void						write_winner(t_vm *vm)
{
	t_player				*winner;

	if ((vm->flags & VISU) == 0)
	{
		if ((winner = get_winner2(vm)) != NULL)
		{
			ft_putstr("Contestant ");
			ft_putnbr(winner->pos);
			ft_putstr(", \"");
			ft_putstr(winner->name);
			ft_putstr("\", has won!\n");
		}
		del_vm(&vm);
		exit(0);
	}
}

void						pop_winner(t_vm *vm)
{
	unsigned int			y;
	unsigned int			x;
	t_player				*winner;

	if (is_end(vm) == 0)
		return ;
	write_winner(vm);
	refrech_win(vm);
	print_info(vm);
	print_grid(vm);
	y = (NB_LINE_COLUMN - HEIGHT_WINNER) / 2;
	x = ((NB_LINE_COLUMN * 3 + 1) - WIDTH_WINNER) / 2;
	vm->w_winner = subwin(stdscr, HEIGHT_WINNER, WIDTH_WINNER, y, x);
	clear_winner(y, x, vm->w_winner);
	if ((winner = get_winner2(vm)) != NULL)
	{
		print_info_winner(vm->w_winner, winner);
		box(vm->w_winner, ACS_VLINE, ACS_HLINE);
		wrefresh(vm->w_winner);
		refresh();
		while (check_key(getch(), vm) != ESCAPE)
			;
	}
	del_vm(&vm);
	exit(0);
}
