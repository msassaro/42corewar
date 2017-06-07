#include "../incs/virtual_machine.h"

static int					get_number(char *nb)
{
	int						i;

	if (ft_is_number(nb) == 0)
		return (-1);
	i = 0;
	while (ft_isspace(nb[i]) == 1 || nb[i] == '+')
		i++;
	if (nb[i] == '-' || nb[i] == '\0')
		return (-1);
	return (ft_atoi(nb));
}

static int					get_flag(t_vm *vm, int argc, char **argv)
{
	int						i;
	int						flag;

	i = 0;
	flag = NONE;
	while (i++ < argc)
		if (ft_strcmp("-d", argv[i - 1]) == 0 ||
				ft_strcmp("-dm", argv[i - 1]) == 0)
		{
			flag = ft_strcmp("-d", argv[i - 1]) == 0 ? flag | DUMP : flag;
			flag = ft_strcmp("-dm", argv[i - 1]) == 0 ? flag | DUMP_M : flag;
			if ((vm->nb_dump = get_number(argv[i])) == -1)
				return (-1);
		}
		else if (ft_strcmp("-n", argv[i - 1]) == 0)
			flag = flag | NUMBER;
		else if (ft_strcmp("-v", argv[i - 1]) == 0)
			flag = flag | VISU;
		else if (ft_strcmp("-s", argv[i - 1]) == 0)
		{
			flag = flag | SUSPEND;
			if ((vm->nb_susp = get_number(argv[i])) == -1)
				return (-1);
		}
	return (flag);
}

static int					check_all_flags(int cpy_flags)
{
	int						flags;

	flags = 0;
	flags = ((cpy_flags & DUMP) != 0) ? flags | DUMP : flags;
	flags = ((cpy_flags & DUMP_M && (cpy_flags & DUMP) == 0) != 0) ?
			flags | DUMP_M : flags;
	flags = ((cpy_flags & NUMBER) != 0) ? flags | NUMBER : flags;
	flags = ((cpy_flags & VISU) != 0) ? flags | VISU : flags;
	flags = ((cpy_flags & SUSPEND) != 0 && (cpy_flags & VISU) != 0) ?
			flags | SUSPEND : flags;
	return (flags);
}

t_vm						*init_vm(int argc, char **argv)
{
	int						tmp_flags;
	t_vm					*new_;

	if ((new_ = ft_memalloc(sizeof(t_vm))) == NULL)
		return (NULL);
	if ((tmp_flags = get_flag(new_, argc, argv)) == -1)
		return (NULL);
	new_->flags = check_all_flags(tmp_flags);
	if ((new_->plr = save_player(argc - 1, &argv[1], new_)) == NULL)
		return (NULL);
	if ((new_->flags & DUMP) != 0 || (new_->flags & DUMP_M) != 0)
		if ((new_->fd = ft_fopen(NAME_FILE_DUMP_MEM, "w+")) == -1)
			return (NULL);
	init_ncurse(new_);
	new_->status = ((new_->flags & VISU) != 0) ? PAUSE : RUN;
	new_->pause = ((new_->flags & SUSPEND) != 0) ? new_->nb_susp : 0;
	new_->dump = ((new_->flags & DUMP) != 0) ? new_->nb_dump : 0;
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	new_->nb_proces = new_->nb_player;
	new_->cycle_to_die = INIT_CYCLE_TO_DIE;
	init_affichage(new_);
	copy_player(new_);
	return (new_->nb_player <= MAX_PLAYER ? new_ : del_vm(&new_));
}

t_vm						*del_vm(t_vm **vm)
{
	if (vm == NULL || *vm == NULL)
		return (NULL);
	if (((*vm)->flags & VISU) != 0)
		endwin();
	if ((*vm)->nb_proces > 0)
		del_player(&(*vm)->plr);
	if (((*vm)->flags & DUMP) != 0)
		close((*vm)->fd);
	return (NULL);
}
