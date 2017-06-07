#include "asm.h"

/*
** This will count the nb of words between '\t' and ' '
*/

int		ft_nbword(char *str)
{
	int		i;
	int		word;
	int		on_word;

	i = 0;
	on_word = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			on_word = 0;
		else if (on_word == 0)
		{
			word++;
			on_word = 1;
		}
		i++;
	}
	return (word);
}

/*
** If there are only spaces or tabs or if the line == NULL.
** then we suppose the line useless and we return 1.
** Else, we suppose the line is useful.
*/

int		ft_isuselessstr(char *str)
{
	int		i;

	i = 0;
	if ((int)ft_strlen(str) < 1)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** Here we recup th op by name
*/

t_op	ft_getop_name(char *name, t_env *e)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (ft_strequ(e->op[i].name, name))
			return (e->op[i]);
		i++;
	}
	return (e->op[17]);
}
