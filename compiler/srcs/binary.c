/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:24:56 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/31 13:47:30 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** here we will receve the value of item->code, and the size (= nb octet)
** .
** In case of big endian we reverse.
** Then we will put each part into the buffer. (depending on nb of octet)
** .
** we return the content of buff (equivalent to a char* (1 line))
*/

char	*ft_getbin(int val, int nb_octet)
{
	char	buffer[nb_octet];
	int		i;
	int		nb;

	i = 0;
	nb = nb_octet;
	while (nb--)
	{
		buffer[nb] = (char)((val >> i) & 0xFF);
		i += 8;
	}
	return ((char *)ft_memdup(buffer, nb_octet));
}

/*
** Here we will get the bin from the item->code received (int code);
** Then we will add it at the end of cmd->bin.
** .
** At the end we will return size + codesize. (size is the lenght of cmd->bin)
*/

int		ft_addbin(t_cmd *cmd, int size, int code, int codesize)
{
	char	**bin;
	char	*c_bin;

	bin = &(cmd->bin);
	c_bin = ft_getbin(code, codesize);
	if ((*bin = (char*)ft_memjoin(*bin, size, c_bin, codesize)) == NULL)
		ft_strerror("error binary creation", "");
	return (size + codesize);
}

/*
** Here we will check for each cmd:
** In each item of cmd, for the OP items, we will add_bin with the code of op
** and if there is cycles --> we add pcode.
** .
** size is used to know the length of cmd->bin. We copy at the end of it.
*/

int		ft_binary_creation2(int size, t_item *item, t_env *e, t_cmd *cmd)
{
	t_op	op;

	if (item->type == OP)
	{
		op = ft_getop_name(item->word, e);
		size = ft_addbin(cmd, size, item->code, CODESIZE_OP);
		if (op.encode)
			size = ft_addbin(cmd, size, cmd->encode, CODESIZE_ENCODE);
	}
	else if (item->type & T_REG)
		size = ft_addbin(cmd, size, item->code, 1);
	else if (item->type & T_IND || ((item->type & T_DIR) && op.idx))
		size = ft_addbin(cmd, size, item->code, CODESIZE_IND);
	else if (item->type & T_DIR)
		size = ft_addbin(cmd, size, item->code, CODESIZE_DIR);
	return (size);
}

void	ft_binary_creation(t_env *e)
{
	t_item	*item;
	t_cmd	*cmd;
	int		size;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		size = 0;
		while (item)
		{
			size = ft_binary_creation2(size, item, e, cmd);
			item = item->next;
		}
		cmd = cmd->next;
	}
}
