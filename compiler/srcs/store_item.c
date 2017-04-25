/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:53:31 by msassaro          #+#    #+#             */
/*   Updated: 2016/06/06 11:33:44 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_lab_before_push(t_cmd *cmd, int j, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_strchr(LABEL_CHARS, str[i]))
			ft_cmd_error("label syntax", cmd, j);
	ft_push_item(cmd, str, LAB, j);
}

void	ft_check_op_before_push(t_env *e, t_cmd *cmd, int j, char *str)
{
	int		i;
	int		ok;

	i = -1;
	ok = 0;
	while (++i < 16)
	{
		if (ft_strequ(str, e->op[i].name))
		{
			ok = 1;
			break ;
		}
	}
	if (!ok)
		ft_cmd_error("this is a wrong instruction", cmd, j);
	ft_push_item(cmd, str, OP, j);
}

void	ft_check_item_line2(t_v *v, t_cmd *cmd, t_env *e)
{
	while (v->str[v->i])
	{
		if (v->str[v->i] == LABEL_CHAR && v->itm_nb == 0)
		{
			ft_check_item_line2_part1(v, cmd);
			break ;
		}
		else if ((v->str[v->i] == ' ' || v->str[v->i] == '\t')
		&& (v->itm_nb == 0 || v->itm_nb == 1) && v->instr_readed == 0)
		{
			ft_check_item_line2_part2(v, cmd, e);
			break ;
		}
		else if (v->str[v->i] == SEPARATOR_CHAR)
		{
			ft_check_item_line2_part3(v, cmd, e);
			break ;
		}
		else if (v->str[v->i + 1] == '\0')
		{
			ft_check_item_line2_part4(v, cmd, e);
			break ;
		}
		v->i++;
	}
}

void	ft_check_item_line(t_cmd *cmd, t_env *e)
{
	t_v		*v;

	v = (t_v*)ft_memalloc(sizeof(t_v));
	v->instr_readed = 0;
	v->i = -1;
	v->itm_nb = 0;
	v->op_ok = 0;
	v->str = cmd->line;
	while (v->str[++v->i])
	{
		while (v->str[v->i] && (v->str[v->i] == ' ' || v->str[v->i] == '\t'))
			v->i++;
		if (v->str[v->i] && v->str[v->i] != ' ' && v->str[v->i] != '\t')
		{
			v->st = v->i;
			ft_check_item_line2(v, cmd, e);
		}
	}
	if (v->op_ok != 1)
		ft_interror("syntax error at line %d", cmd->nb);
}

void	ft_store_items(t_env *e)
{
	t_cmd	*tmp;
	int		len;

	tmp = e->cmd;
	while (tmp)
	{
		if (ft_nbword(tmp->line) == 1)
		{
			len = ft_strlen(ft_strtrim(tmp->line));
			if (ft_strtrim(tmp->line)[len - 1] != LABEL_CHAR)
				ft_cmd_error("syntax error. missing ':'", tmp, len - 1);
			ft_check_lab_before_push(tmp, 0, ft_strndup(tmp->line, len - 1));
		}
		else if (ft_nbword(tmp->line) > 1)
			ft_check_item_line(tmp, e);
		else
			ft_delete_e_cmd(e, tmp);
		tmp = tmp->next;
	}
}
