#include "asm.h"

void	ft_cmd_error(char *msg, t_cmd *cmd, int col)
{
	int		i;

	i = 0;
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg && cmd)
	{
		ft_printf_fd(2, ": line[%d] col[%d] -> %s\n", cmd->nb, col, msg);
		cmd->line = ft_replace_char_by(cmd->line, '\t', ' ');
		ft_printf_fd(2, "%s\n", cmd->line);
		while (i++ < col - 1)
		{
			if (i < (col - 5))
				ft_putchar_fd(' ', 2);
			else
				ft_printf_fd(2, "{yellow}~");
		}
		ft_printf_fd(2, "^{eoc}");
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}

void	ft_itmerr(char *msg, t_item *itm)
{
	int		i;

	i = 0;
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg && itm)
	{
		ft_printf_fd(2, ": \'%s\' line[%d] col[%d] ->", itm->word,
				itm->line_nb, itm->col);
		ft_printf_fd(2, " %s\n", msg);
		itm->line = ft_replace_char_by(itm->line, '\t', ' ');
		ft_printf_fd(2, "%s\n", itm->line);
		while (i++ < itm->col - 1)
		{
			if (i < (itm->col - 5))
				ft_putchar_fd(' ', 2);
			else
				ft_printf_fd(2, "{yellow}~");
		}
		ft_printf_fd(2, "^{eoc}");
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}
