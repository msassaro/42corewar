/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 08:59:06 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/07 09:10:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"
#include "../incs/virtual_machine.h"

int							change_index(int i, char *argv, int argc)
{
	i = (ft_strcmp(argv, "-d") == 0 || ft_strcmp(argv, "-s") == 0) ||
			ft_strcmp(argv, "-dm") == 0 ? i + 2 : i + 1;
	return ((i >= argc) ? -1 : i);
}

int							change_index2(t_vm *vm, int i, char **argv,
		int argc)
{
	if ((i = (vm->flags & NUMBER) != 0 ? i + 2 : i + 1) > argc)
		return (i);
	if ((vm->flags & NUMBER) != 0 && ft_is_number(argv[i - 1]) == 0)
		return (-1);
	return (i);
}
