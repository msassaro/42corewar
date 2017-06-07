#include "asm.h"

char	*ft_keep_end(char *str)
{
	int		len;
	int		i;
	char	*new;

	new = ft_memalloc(3);
	ft_memset(new, '0', 2);
	len = ft_strlen(str);
	len--;
	i = len;
	new[1] = str[i];
	i--;
	if (i >= 0)
		new[0] = str[i];
	return (new);
}

void	ft_debug7(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;
	int		i;
	char	*str;

	i = 0;
	item = NULL;
	cmd = e->cmd;
	ft_printf("\n{bg blue}BINARY{reset}\n");
	while (cmd)
	{
		i = 0;
		while (i < cmd->size)
		{
			if (cmd->bin[i] == 0)
				str = "00";
			else
				str = ft_keep_end(ft_itobase(cmd->bin[i], "0123456789abcdef"));
			ft_printf("%s ", str);
			i++;
		}
		ft_putchar('\n');
		cmd = cmd->next;
	}
	ft_printf("{bg blue}----------{reset}\n");
}

void	ft_nodebug(t_env *e)
{
	(void)e;
}
