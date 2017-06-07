#include "asm.h"

void	ft_check_item_line2_part1(t_v *v, t_cmd *cmd)
{
	v->itm_nb++;
	ft_check_lab_before_push(cmd, v->i,
			ft_strndup(v->str + v->st, v->i - v->st));
}

void	ft_check_item_line2_part2(t_v *v, t_cmd *cmd, t_env *e)
{
	v->itm_nb++;
	v->instr_readed++;
	ft_check_op_before_push(e, cmd, v->i,
			ft_strndup(v->str + v->st, v->i - v->st));
	v->op_ok++;
}

void	ft_check_item_line2_part3(t_v *v, t_cmd *cmd, t_env *e)
{
	v->itm_nb++;
	ft_push_item(cmd, ft_strndup(v->str + v->st, v->i - v->st),
			PARAM, v->i);
}

void	ft_check_item_line2_part4(t_v *v, t_cmd *cmd, t_env *e)
{
	v->itm_nb++;
	ft_push_item(cmd, ft_strndup(v->str + v->st, v->i - v->st + 1),
			PARAM, v->i);
}
