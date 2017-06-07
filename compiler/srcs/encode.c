#include "asm.h"

/*
** Ici on va creer l'encodage.
** .
** On a les elements suivants:
** REG_CODE = 1 = 0000 0001
** DIR_CODE = 2 = 0000 0010
** IND_CODE = 3 = 0000 0011
** on va encoder sur un octet pour que cet octet contiene les types des
** parametres de la commande.
** On va ajouter le type du param en binaire et decaler a chaque fois de 2.
** .                      .. ..  .. ..
** .                       ^  ^   ^  ^
** .                       |__|___|__|___ A
** .                          |___|__|___ B
** .                              |__|___ C
** .                                 |____D
** ~~~~~~~~~~~~~~~~~~~~~~~~~
** Example:
** We have this -->   sti r1, %:live, %1
** 1er param est un T_REG, le 2e un T_DIR et le 3e un T_DIR
** .
** encode    = 0000 0000
** REG_CODE  = 0000 0001    i = 6
** .             encode |= (REG_CODE << 6)
** ---> encode = 0100 0000
** .             --
** ~~~~~~~~~~~~~~~~~~~~~~~~~
** encode    = 0100 0000
** DIR_CODE  = 0000 0010    i = 4
** .             encode |= (DIR_CODE << 4)
** ---> encode = 0110 0000
** .               --
** ~~~~~~~~~~~~~~~~~~~~~~~~~
** encode    = 0110 0000
** DIR_CODE  = 0000 0010    i = 2
** .             encode |= (DIR_CODE << 2)
** ---> encode = 0110 1000
** .                  --
** ~~~~~~~~~~~~~~~~~~~~~~~~~
** On a donc un encore = 0110 1000 (binaire) = 68 (hexadecimal)
*/

void	ft_encode2(t_cmd *cmd, t_item *item)
{
	int		i;

	i = 6;
	while (item)
	{
		if (item->type & PARAM)
		{
			if (item->type & T_REG)
				cmd->encode |= (REG_CODE << i);
			if (item->type & T_DIR)
				cmd->encode |= (DIR_CODE << i);
			if (item->type & T_IND)
				cmd->encode |= (IND_CODE << i);
			i -= 2;
		}
		item = item->next;
	}
}

void	ft_encode(t_env *e)
{
	t_cmd	*cmd;
	t_item	*item;

	cmd = e->cmd;
	while (cmd)
	{
		item = cmd->item;
		if (item != NULL)
			ft_encode2(cmd, item);
		else
			ft_delete_e_cmd(e, cmd);
		cmd = cmd->next;
	}
}
