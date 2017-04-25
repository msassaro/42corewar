/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:51:20 by fpasquer          #+#    #+#             */
/*   Updated: 2016/01/05 18:11:03 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb(unsigned long long int nb, int fd)
{
	unsigned long long int	mem;

	if (nb == 0)
	{
		ft_putstr_fd("0x", fd);
		return ;
	}
	mem = nb % 16;
	print_nb(nb / 16, fd);
	if (mem < 10)
		ft_putchar_fd(mem + '0', fd);
	else
	{
		mem -= 10;
		ft_putchar_fd(mem + 'a', fd);
	}
}

void			ft_print_adr_fd(void *adr, int fd)
{
	unsigned long long int		val_adr;

	val_adr = (unsigned long long int)adr;
	if (val_adr == 0)
		ft_putstr_fd("0x0", fd);
	else
		print_nb(val_adr, fd);
}
