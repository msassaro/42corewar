/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_infos_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:55:47 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/31 13:56:20 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Ici on va print les informations concernant le champion que l'on vient
** de compiler.
** Si il y a eut une redefinition du nom alors on affiche l'ancien
** et le nouveau nom dans les infos. Sinon juste le nom.
*/

void	ft_print_infos(t_env *e)
{
	if (g_flag_i)
	{
		ft_printf("Informations about {green}%s{eoc}\n\n", e->output);
		if (e->new_name)
		{
			ft_printf("{yellow}Old name: {eoc}%s\n", e->name);
			ft_printf("{yellow}New name: {eoc}%s\n", e->header.prog_name);
		}
		else
			ft_printf("{yellow}Name:     {eoc}%s\n", e->header.prog_name);
		ft_printf("{yellow}Comment:  {eoc}%s\n", e->header.comment);
		ft_printf("{yellow}Size:     {eoc}%d bytes\n",
							ft_reverse(e->header.prog_size));
		ft_printf("{yellow}Magic:    {eoc}%s\n\n",
							ft_itoa_base(COREWAR_EXEC_MAGIC, 16));
	}
}

/*
** Ici on va siplement essayer d'ouvrir le fichier output qui correspond au
** fichier d'entree avec extension modifiee.
** (input: test.s ----> output = test.cor)
**            ---                    ----
** On ouvre ce fichier en creation. Si le fd retourne une erreur, on va
** dans error et on quitte le programme.
** .
** Si le fichier s'ouvre correctement, on ecrit le header dans le fichier
** pour commencer.
** Puis ensuite on va y ecrire chaque cmd->bin present dans e. ce qui
** correspond au binaire de chaque commande.
** .
** O_RDWR -----> open for read and write.
** O_CREAT ----> if file exists, no effect, otherwise the file is created.
** O_TRUNC ----> length truncated to 0.
** S_IRUSR ----> read permission, owner.
** S_IWUSR ----> write permission, owner.
*/

void	ft_write_outfile(t_env *e)
{
	int		fd;
	t_cmd	*cmd;

	fd = open(e->output, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		ft_strerror("%s file out error", e->output);
	cmd = e->cmd;
	write(fd, (char*)&(e->header), sizeof(e->header));
	while (cmd)
	{
		write(fd, cmd->bin, cmd->size);
		cmd = cmd->next;
	}
}
