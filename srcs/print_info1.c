#include "../incs/virtual_machine.h"
#include "../incs/corewar.h"

static int					change_line(t_vm *vm, unsigned int i, char *line)
{
	char					*nb;
	char					*tmp;
	static unsigned int		j = 0;

	if (j == 0)
	{
		if ((nb = ft_itoa_base(i, 16)) == NULL)
			return (-1);
		while (ft_strlen(nb) < 3)
		{
			if ((tmp = ft_strjoin("0", nb)) == NULL)
				return (-1);
			ft_memdel((void**)&nb);
			nb = tmp;
		}
		ft_putstr_fd("0x0", vm->fd);
		ft_putstr_fd(nb, vm->fd);
		ft_putstr_fd(" : ", vm->fd);
		ft_memdel((void**)&nb);
	}
	ft_putstr_fd(line, vm->fd);
	ft_putstr_fd(j == 63 ? " \n" : " ", vm->fd);
	j = j == 63 ? 0 : j + 1;
	return (0);
}

static void					dump_memory(t_vm *vm)
{
	char					*s;
	char					*tmp;
	unsigned int			i;

	i = 0;
	if ((vm->flags & DUMP_M) != 0)
	{
		ft_putstr_fd("Cycle : ", vm->fd);
		ft_putnbr_fd(vm->cycle, vm->fd);
		ft_putchar_fd('\n', vm->fd);
	}
	while (i < NB_CASE_TAB)
	{
		if ((s = ft_itoa_base(vm->array[i++].code_hexa, 16)) == NULL)
			return ;
		if (ft_strlen(s) < 2)
		{
			if ((tmp = ft_strjoin("0", s)) == NULL)
				return ;
			ft_memdel((void**)&s);
			s = tmp;
		}
		change_line(vm, i - 1, s);
		ft_memdel((void**)&s);
	}
}

void						dump_print_player(t_vm *vm, int fd)
{
	unsigned int			i;
	t_player				*curs;

	i = 0;
	curs = vm->plr;
	ft_putstr_fd("Introducing contestants...\n", fd);
	while (curs != NULL && i++ < vm->nb_player)
	{
		ft_putstr_fd("* Player ", fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd(", weighing ", fd);
		ft_putnbr_fd(curs->size, fd);
		ft_putstr_fd(" bytes, \"", fd);
		ft_putstr_fd(curs->name, fd);
		ft_putstr_fd("\" (\"", fd);
		ft_putstr_fd(curs->comment, fd);
		ft_putstr_fd("\") !\n", fd);
		curs = curs->next;
	}
}

void						print_dump(t_vm *vm)
{
	if (vm->dump != vm->cycle)
		return ;
	dump_memory(vm);
	if ((vm->flags & DUMP) != 0 && (vm->flags & VISU) == 0)
	{
		del_vm(&vm);
		exit(0);
	}
	if ((vm->flags & DUMP_M) != 0)
	{
		ft_putchar_fd('\n', vm->fd);
		vm->dump += vm->nb_dump;
	}
}

void						print_players(t_vm *vm)
{
	unsigned int			i;

	if ((vm->flags & VISU) == 0)
		return ;
	i = 0;
	while (i < vm->nb_player)
	{
		mvwprintw(vm->w_info, 11 + i * 4, 3, "Name %d : ", vm->nb_rep_plr[i]);
		init_pair(i + 1, i + 1, COLOR_BLACK);
		attron(COLOR_PAIR(i + 1));
		mvwprintw(stdscr, 11 + i * 4, 210, "%s", vm->name_j[i]);
		attroff(COLOR_PAIR(i + 1));
		mvwprintw(vm->w_info, 12 + i * 4, 5, "Last live : %-10u",
				vm->cycle_last_live[i]);
		mvwprintw(vm->w_info, 13 + i * 4, 5, "Nb live : %-10u",
				vm->nb_live_each_plr[i]);
		i++;
	}
}
