/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 10:26:30 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/20 12:16:43 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/corewar.h"

void						ft_recover_instruction(int fd, t_array *array,
		int *size)
{
	char					instruction[10000];
	int						y;
	int						i;
	static int				player = 0;

	player++;
	ft_bzero(instruction, sizeof(char) * 10000);
	i = read(fd, instruction, 10000);
	if ((i == -1 || i == 0))
	{
		ft_putendl("ERROR READ : ft_recover_instruction");
		exit(ERROR_READ);
	}
	if (i != *size || *size > 682 || *size <= 0)
	{
		ft_putendl("ERROR SIZE : ft_recover_instruction");
		exit(ERROR_SIZE_CHAMP);
	}
	y = 0;
	while (y < i)
		y += ft_parse_instruction(&instruction[y], &array[y]);
	y = 0;
	while (y < i)
		array[y++].player = player;
}
