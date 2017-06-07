#include "asm.h"

void	ft_debug4(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	ft_printf("{bg blue}LABEL ADDRESSAGE{reset}\n");
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			if (item->type == LAB)
				ft_printf("[ %d ]\t%s\n", cmd->addr, item->word);
			item = item->next;
		}
		cmd = cmd->next;
	}
}

void	ft_debug5_part2(t_cmd *cmd, t_label *l)
{
	t_item	*item;

	item = cmd->item;
	while (l)
	{
		if (l != NULL && l->addr == cmd->addr)
			ft_printf("{bg red}LABEL\t\t[ %d ]\t\t%s{reset}\n",
			l->addr, l->word);
		l = l->next;
	}
	ft_printf("{reset}{red}CMD ADDRESS\t[ %d ]\n{reset}", cmd->addr);
	while (item)
	{
		ft_printf("{green}[ %s ]{eoc}\t", ft_itoa(item->type));
		ft_print_item_type(item);
		ft_printf("{yellow}[ %d ]\t", item->code);
		ft_printf("{eoc}%s\n", item->word);
		item = item->next;
	}
	ft_printf("{green}\t\t\tSIZE\t[ %d ]\n{eoc}", cmd->size);
}

void	ft_debug5(t_env *e)
{
	t_cmd	*cmd;
	t_label	*l;

	l = e->label;
	cmd = e->cmd;
	ft_printf("{bg blue}COMPILATION CARACTERISTICS{reset}\n");
	ft_printf("{yellow}  NB{eoc}\tTYPE\tADDR\t{yellow}CODE{eoc}\tWORD\n");
	ft_putstr("-------------------------------------\n");
	while (cmd)
	{
		ft_debug5_part2(cmd, l);
		cmd = cmd->next;
	}
}

void	ft_debug6(t_env *e)
{
	t_cmd	*cmd;

	cmd = e->cmd;
	ft_printf("\n{bg blue}ENCODE PER COMMAND{reset}\n");
	ft_printf("{blue}REGISTER = 1   DIRECT = 2   INDIRECT = 3{eoc}\n");
	while (cmd)
	{
		ft_printf("{red}[%d]{eoc} ", (cmd->encode >> 6) & 0x3);
		ft_printf("{yellow}[%d]{eoc} ", (cmd->encode >> 4) & 0x3);
		ft_printf("{green}[%d]{eoc} ", (cmd->encode >> 2) & 0x3);
		ft_printf("{blue}[%d]{eoc} ", (cmd->encode >> 0) & 0x3);
		ft_printf(" %s\n", ft_strtrim(ft_replace_char_by(cmd->line,
						'\t', ' ')));
		cmd = cmd->next;
	}
	ft_printf("{bg blue}----------{reset}\n");
}
