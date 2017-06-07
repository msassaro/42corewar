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

/*
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
*/

void	ft_file_requirements(void)
{
ft_printf("---------------------------------------------------------------\n");
ft_printf("               FILE REQUIREMENTS for ASM Corewar\n");
ft_printf("---------------------------------------------------------------\n");
ft_printf("\n");
ft_printf("         - Your file need a ' .s ' extension to work.\n");
ft_printf("         - Do not exceed a size of CHAMP_MAX_SIZE\n");
ft_printf("         - Please refer to the below operations\n");
ft_printf("\n");
ft_printf("           REGISTER = 1   DIRECT = 2   INDIRECT = 3\n");
ft_printf("       __________________________________________________\n");
ft_printf("      |     | NB   |                |       |     |  NB  |\n");
ft_printf("      |NAME |PARAM |TYPE PARAM      |ENCODE |INDEX|CYCLES|\n");
ft_printf("       --------------------------------------------------\n");
ft_printf("   1   live     1          {2}         No      No    10\n");
ft_printf("   2   ld       2       {2|3, 1}       Yes     No    5\n");
ft_printf("   3   st       2       {1, 1|3}       Yes     No    5\n");
ft_printf("   4   add      3       {1, 1, 1}      Yes     No    10\n");
ft_printf("   5   sub      3       {1, 1 ,1}      Yes     No    10\n");
ft_printf("   6   and      3  {1|2|3, 1|2|3, 1}   Yes     No    6\n");
ft_printf("   7   or       3  {1|2|3, 1|2|3, 1}   Yes     No    6\n");
ft_printf("   8   xor      3  {1|2|3, 1|2|3, 1}   Yes     No    6\n");
ft_printf("   9   zjmp     1          {2}         No      Yes   20\n");
ft_printf("   10  ldi      3  {1|2|3, 1|2|3, 1}   Yes     Yes   25\n");
ft_printf("   11  sti      3   {1, 1|2|3, 1|2}    Yes     Yes   25\n");
ft_printf("   12  fork     1          {2}         No      Yes   800\n");
ft_printf("   13  lld      2        {2|3, 1}      Yes     No    10\n");
ft_printf("   14  lldi     3   {1|2|3, 1|2, 1}    Yes     Yes   50\n");
ft_printf("   15  lfork    1         {2}          No      Yes   1000\n");
ft_printf("   16  aff      1         {1}          Yes     No    2\n");
}

/*
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
*/

void	ft_user_man(void)
{
ft_printf("---------------------------------------------------------------\n");
ft_printf("              ASM Corewar      General Command MAN\n");
ft_printf("---------------------------------------------------------------\n");
ft_printf("\n");
ft_printf("     SYNOPSIS\n");
ft_printf("           ./asm [ -bdehiknrs ] [ (only 1) file ]\n");
ft_printf("\n");
ft_printf("     DESCRIPTION\n");
ft_printf("           The ASM corewar will take a champion.s writen\n");
ft_printf("           in the corewar asm language and will build and\n");
ft_printf("           compile a corresponding champion.cor file.\n");
ft_printf("           (please see the file requirements docs).\n");
ft_printf("\n");
ft_printf("     FLAGS\n");
ft_printf("           -b     Display Binary output.\n");
ft_printf("           -c     Display compilation caracteristics.\n");
ft_printf("           -d     Debug mode.\n");
ft_printf("           -e     Display detailed errors.\n");
ft_printf("           -h     Help. User shell man.\n");
ft_printf("           -i     Information mode.\n");
ft_printf("           -k     Display encoding details.\n");
ft_printf("           -n     New name (./asm -n \"new name\" champ.s)\n");
ft_printf("           -r     File requirements.\n");
ft_printf("\n");
ft_printf("---------------------------------------------------------------");
}
