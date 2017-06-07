#include "asm.h"

void	ft_set_addr_and_header(t_env *e)
{
	t_cmd	*cmd;
	int		size;

	size = 0;
	cmd = e->cmd;
	while (cmd)
	{
		cmd->addr = size;
		size += cmd->size;
		cmd = cmd->next;
	}
	if (size < CHAMP_MIN_SIZE)
		ft_strerror("champion \"%s\" has no instructions", e->name);
	if (size > CHAMP_MAX_SIZE)
		ft_strerror("champion \"%s\" exceed the size limit", e->name);
	ft_bzero(&e->header, sizeof(t_header));
	ft_bzero(e->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(e->header.comment, COMMENT_LENGTH + 1);
	if (e->new_name)
		ft_strcpy(e->header.prog_name, e->new_name);
	else
		ft_strcpy(e->header.prog_name, e->name);
	ft_strcpy(e->header.comment, e->comment);
	e->header.magic = ft_reverse(COREWAR_EXEC_MAGIC);
	e->header.prog_size = ft_reverse(size);
}
