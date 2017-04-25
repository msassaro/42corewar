/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:10:59 by fpasquer          #+#    #+#             */
/*   Updated: 2015/12/16 15:41:32 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_printcolor(int color, char *str, size_t n)
{
	if (color == BLACK)
		ft_putstr("\033[30m");
	else if (color == RED)
		ft_putstr("\033[31m");
	else if (color == GREEN)
		ft_putstr("\033[32m");
	else if (color == YELLOW)
		ft_putstr("\033[33m");
	else if (color == BLUE)
		ft_putstr("\033[34m");
	else if (color == MAGENTA)
		ft_putstr("\033[35m");
	else if (color == CYAN)
		ft_putstr("\033[36m");
	else if (color == WHITE)
		ft_putstr("\033[37m");
	write(1, str, n);
	ft_putstr("\033[0m");
}
