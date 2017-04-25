/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 10:52:54 by fpasquer          #+#    #+#             */
/*   Updated: 2015/11/24 22:22:55 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb(unsigned int nb, int fd)
{
	unsigned int	mem;

	if (nb == 0)
		return ;
	mem = nb % 10;
	print_nb(nb / 10, fd);
	ft_putchar_fd(mem + '0', fd);
}

void			ft_putnbr_fd(int nb, int fd)
{
	unsigned int	mem_nb;

	if (nb == 0)
		ft_putchar_fd('0', fd);
	else
	{
		mem_nb = (nb < 0) ? nb * -1 : nb;
		if (nb < 0)
			ft_putchar_fd('-', fd);
		print_nb(mem_nb, fd);
	}
}
