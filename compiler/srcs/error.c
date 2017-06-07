#include "asm.h"

/*
** Char Line Col error.
*/

void	ft_clc_error(char *msg, char c, int line, int col)
{
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg)
	{
		ft_printf_fd(2, ": line[%d] col[%d] -> ", line, col);
		ft_printf_fd(2, msg, c);
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}

/*
** Str Line Col error.
*/

void	ft_slc_error(char *msg, char *s, int line, int col)
{
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg)
	{
		ft_printf_fd(2, ": \'%s\' arround line[%d] col[%d] -> ", s, line, col);
		ft_printf_fd(2, msg);
		ft_putchar('\n');
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}

void	ft_charerror(char *msg, char c)
{
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg)
	{
		ft_printf_fd(2, ": ");
		ft_printf_fd(2, msg, c);
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}

void	ft_strerror(char *msg, char *str)
{
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg)
	{
		ft_printf_fd(2, ": ");
		ft_printf_fd(2, msg, str);
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}

void	ft_interror(char *msg, int nb)
{
	ft_printf_fd(2, "{red}asm: error");
	if (g_flag_e && msg)
	{
		ft_printf_fd(2, ": ");
		ft_printf_fd(2, msg, nb);
	}
	ft_printf_fd(2, "\n{eoc}");
	exit(0);
}
