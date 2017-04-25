/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 11:40:17 by msassaro          #+#    #+#             */
/*   Updated: 2016/06/20 11:41:21 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_line_count(t_env *e)
{
	int		count;
	t_cmd	*cmd;

	cmd = e->cmd;
	count = 0;
	while (cmd)
	{
		if (cmd->line)
			count++;
		cmd = cmd->next;
	}
	return (count);
}
