/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:26:26 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/31 13:26:27 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_file_requirements(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(REQUIREMENTS, O_RDONLY);
	if (fd < 0)
		ft_printf_fd(2, "error while trying to open %s\n", REQUIREMENTS);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	exit(0);
}

void	ft_user_man(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(USER_MAN, O_RDONLY);
	if (fd < 0)
		ft_printf_fd(2, "error while trying to open %s\n", USER_MAN);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
	}
	exit(0);
}
