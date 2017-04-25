/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:24:59 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/31 13:22:53 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_debug0(t_env *e)
{
	ft_printf("{bg blue}NAME AND COMMENT IDENTIFICATION{reset}\n");
	ft_printf("{blue}name:    {eoc}%s\n", e->name);
	ft_printf("{blue}comment: {eoc}%s\n", e->comment);
}

void	ft_debug1(t_env *e)
{
	t_cmd	*cmd;

	cmd = e->cmd;
	ft_printf("{bg blue}LINE RECUPERATION{reset}\n");
	while (cmd)
	{
		ft_printf("{blue}line[%d]:{eoc} ", cmd->nb);
		ft_printf("%s\n", ft_replace_char_by(cmd->line, '\t', ' '));
		cmd = cmd->next;
	}
}

void	ft_print_item_type(t_item *item)
{
	if (item->type == LAB)
		ft_putstr("LABEL         \t");
	if (item->type == OP)
		ft_putstr("OP            \t");
	if (item->type == (PARAM | T_REG))
		ft_putstr("REGISTER      \t");
	if (item->type == (PARAM | T_DIR))
		ft_putstr("DIRECT        \t");
	if (item->type == (PARAM | T_IND))
		ft_putstr("INDIRECT      \t");
	if (item->type == (PARAM | T_DIR | T_LAB))
		ft_putstr("DIRECT LABEL  \t");
	if (item->type == (PARAM | T_IND | T_LAB))
		ft_putstr("INDIRECT LABEL\t");
}

void	ft_debug2(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	ft_printf("{bg blue}CMD CARACTERISTICS{reset}\n");
	ft_printf("{blue}LABEL [ %d ]\tDIRECT   [ %d ]\n", LAB, T_DIR);
	ft_printf("OP    [ %d ]\tINDIRECT [ %d ]\n", OP, T_IND);
	ft_printf("PARAM [ %d ]{eoc}\n", PARAM);
	ft_putstr("-------------------------------------\n");
	ft_printf("{yellow}  NB{eoc}\tTYPE\t\t{yellow}OPCODE{eoc}\tWORD\n");
	ft_putstr("-------------------------------------\n");
	while (cmd)
	{
		item = cmd->item;
		while (item)
		{
			ft_printf("{green}[ %s ]{eoc}\t", ft_itoa(item->type));
			ft_print_item_type(item);
			ft_printf("{yellow}[ %d ]\t", item->code);
			ft_printf("{eoc}%s\n", item->word);
			item = item->next;
		}
		ft_putstr("  ----------------------------------\n");
		cmd = cmd->next;
	}
}

void	ft_debug3(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	ft_printf("{bg blue}ADD ADDRESS + SIZE TO CMD CARACTERISTICS{reset}\n");
	ft_printf("{yellow}  NB{eoc}\tTYPE\tADDR\t{yellow}OPCODE{eoc}\tWORD\n");
	ft_putstr("-------------------------------------\n");
	while (cmd)
	{
		item = cmd->item;
		ft_printf("{red}CMD ADDRESS\t[ %d ]\n{eoc}", cmd->addr);
		while (item)
		{
			ft_printf("{green}[ %s ]{eoc}\t", ft_itoa(item->type));
			ft_print_item_type(item);
			ft_printf("{yellow}[ %d ]\t", item->code);
			ft_printf("{eoc}%s\n", item->word);
			item = item->next;
		}
		ft_printf("{green}\t\t\tSIZE\t[ %d ]\n{eoc}", cmd->size);
		ft_putstr("  ---------------------------\n");
		cmd = cmd->next;
	}
}
