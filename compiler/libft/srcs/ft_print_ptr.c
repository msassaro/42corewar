/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:01:38 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/16 13:45:20 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_ptr(unsigned long ptr)
{
	char	*str;

	ft_putstr("0x");
	str = ft_itoa_base(ptr, 16);
	ft_putstr(str);
	return (ft_strlen(str) + 2);
}
