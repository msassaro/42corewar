#include "../incs/virtual_machine.h"
#include "../incs/corewar.h"

static t_player				*save_curs_player(t_player *lst,
		unsigned int nb_champ)
{
	unsigned int			i;
	unsigned int			position;
	t_player				*curs;

	curs = lst;
	position = NB_CASE_TAB / nb_champ;
	i = 0;
	while (curs != NULL)
	{
		curs->i_grid = position * i++;
		curs = curs->next;
	}
	return (lst);
}

static t_player				*new_player(char *name, int nb,
		unsigned int nb_champ, t_array *array)
{
	t_player				*new;
	int						fd;
	int						y;
	static int				spacing;
	static int				i = 1;

	y = NB_CASE_TAB / nb_champ;
	if ((fd = ft_fopen(name, "r")) == -1)
		return (NULL);
	if (!(new = (t_player*)ft_memalloc(sizeof(t_player))))
		return (NULL);
	new->name = ft_recover_name_champ(fd);
	new->comment = ft_recover_comment_champ(fd, &new->size);
	new->pos = i;
	new->process = i;
	ft_recover_instruction(fd, &array[spacing], &new->size);
	close(fd);
	new->reg[1] = nb;
	spacing += y;
	i++;
	return (new);
}

static void					add_new_player(t_player **lst, t_player **new)
{
	t_player				*curs;

	if (lst == NULL || new == NULL)
		return ;
	if ((*lst) == NULL)
		(*lst) = (*new);
	else
	{
		curs = (*lst);
		while (curs->next != NULL)
			curs = curs->next;
		curs->next = (*new);
		(*new)->prev = curs;
	}
}

t_player					*save_player(int argc, char **argv, t_vm *vm)
{
	int						i;
	int						j;
	unsigned int			nb_champ;
	t_player				*new;
	t_player				*lst;

	i = 0;
	while (i < argc && argv[i][0] == '-' && ft_is_number(argv[i]) == 0)
		if ((i = change_index(i, argv[i], argc)) < 0)
			return (NULL);
	j = -1;
	lst = NULL;
	nb_champ = ((vm->flags & NUMBER) != 0) ? (argc - i + 1) / 2 : argc - i;
	i = ((vm->flags & NUMBER) != 0) ? i + 1 : i;
	while (i < argc)
	{
		if ((new = new_player(argv[i], (vm->flags & NUMBER)
			!= 0 ? ft_atoi(argv[i - 1]) : j--, nb_champ, vm->array)) == NULL)
			return (NULL);
		add_new_player(&lst, &new);
		if ((i = change_index2(vm, i, argv, argc)) == -1)
			return (NULL);
		vm->nb_player++;
	}
	return (save_curs_player(lst, nb_champ));
}

t_player					*del_player(t_player **lst)
{
	t_player				*tmp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		ft_memdel((void**)&(*lst)->name);
		ft_memdel((void**)&(*lst)->comment);
		ft_memdel((void**)lst);
		(*lst) = tmp;
	}
	ft_memdel((void**)lst);
	return (NULL);
}
