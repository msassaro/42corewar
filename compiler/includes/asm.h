/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:24:50 by msassaro          #+#    #+#             */
/*   Updated: 2016/06/20 12:19:50 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include "get_next_line.h"
# include "../libftprintf/includes/ft_printf.h"

# define USER_MAN				"docs/user_man.md"
# define AFP					system("afplay sfx/yeah.m4a&")
# define STYLE					"docs/style.md"
# define REQUIREMENTS			"docs/file_requirements.md"
# define COMMENT_CHAR_2			';'
# define LINE_LENGHT			1500
# define NAME_LENGHT_MIN		2
# define COMMENT_LENGHT_MIN		2
# define LABEL_LENGHT_MIN		2
# define LABEL_LENGHT_MAX		30
# define LAB					0x10
# define OP						0x20
# define PARAM					0x40
# define CODESIZE_OP			1
# define CODESIZE_ENCODE		1
# define CODESIZE_REG			1
# define CODESIZE_DIR			DIR_SIZE
# define CODESIZE_IND			IND_SIZE
# define CHAMP_MIN_SIZE			1

typedef struct	s_v
{
	int			i;
	char		*str;
	int			st;
	int			itm_nb;
	int			op_ok;
	int			instr_readed;
}				t_v;

typedef struct	s_op
{
	char		*name;
	int			nb_param;
	int			type_param[4];
	int			opcode;
	int			nb_cycles;
	char		*description;
	int			encode;
	int			idx;
}				t_op;

typedef struct	s_item
{
	char		*word;
	int			type;
	int			code;
	int			line_nb;
	int			col;
	char		*line;
	void		*next;
}				t_item;

typedef struct	s_cmd
{
	t_item		*item;
	char		*line;
	int			size;
	int			nb;
	int			encode;
	int			addr;
	char		*bin;
	void		*next;
}				t_cmd;

typedef struct	s_label
{
	int			addr;
	int			nb;
	char		*word;
	void		*next;
}				t_label;

typedef struct	s_env
{
	t_op		op[20];
	int			name_ok;
	int			comment_ok;
	char		*name;
	char		*new_name;
	char		*comment;
	char		*output;
	t_header	header;
	t_cmd		*cmd;
	t_label		*label;
}				t_env;

/*
** utils.c
*/

t_op			ft_getop_name(char *name, t_env *e);
int				ft_nbword(char *str);
int				ft_isuselessstr(char *str);

/*
** utils2.c
*/

void			ft_delete_cmd_lab(t_cmd *cmd, t_item *lab);
void			ft_delete_e_cmd(t_env *e, t_cmd *l);
void			ft_check_file_format(t_env *e, char *input);
int				ft_ac_start(char **av, int ac);

/*
** utils3.c
*/

void			*ft_umemcpy(void *s1, const void *s2, size_t n);
void			*ft_memdup(const void *s, size_t n);
void			*ft_memjoin(const void *s1, size_t l1,
				const void *s2, size_t l2);
int				ft_reverse(int old);

/*
** parse_header.c
*/

void			ft_check_name(char *s, t_env *e, int j, int i);
void			ft_check_comment(char *s, t_env *e, int j, int i);
void			ft_delete_cmd_name_comment(t_env *e);
void			ft_parse_header2(t_env *e);
void			ft_parse_header(t_env *e);

/*
** parse_header2.c
*/

void			ft_set_addr_and_header(t_env *e);

/*
** recup.c
*/

void			ft_remove_useless_lines(t_env *e);
char			*ft_format_str(char *str, int line_nb);
t_cmd			*ft_create_cmd(char *line, int i);
void			ft_push_line(t_env *e, char *line, int i);
void			ft_read_file(char *av, t_env *e);
int				ft_line_count(t_env *e);

/*
** global
*/

int				g_flag_e;
int				g_flag_d;
int				g_flag_s;
int				g_flag_i;
int				g_flag_b;
int				g_flag_c;
int				g_flag_k;

/*
** error.c
*/

void			ft_strerror(char *msg, char *str);
void			ft_clc_error(char *msg, char c, int line, int col);
void			ft_slc_error(char *msg, char *s, int line, int col);
void			ft_charerror(char *msg, char c);
void			ft_interror(char *msg, int nb);

/*
** error2.c
*/

void			ft_itmerr(char *msg, t_item *item);
void			ft_cmd_error(char *msg, t_cmd *cmd, int col);

/*
** init.c
** Contains the table of op instr
*/

void			ft_init_env(t_env *e);

/*
** store_item.c
*/

void			ft_check_lab_before_push(t_cmd *cmd, int j, char *str);
void			ft_check_op_before_push(t_env *e, t_cmd *cmd, int j, char *str);
void			ft_check_item_line(t_cmd *cmd, t_env *e);
void			ft_store_items(t_env *e);

/*
** store_item2.c
*/

t_item			*ft_create_item(char *word, int type, t_cmd *cmd, int col);
void			ft_push_item(t_cmd *cmd, char *word, int type, int col);

/*
** store_item3.c
*/

void			ft_check_item_line2_part1(t_v *v, t_cmd *cmd);
void			ft_check_item_line2_part2(t_v *v, t_cmd *cmd, t_env *e);
void			ft_check_item_line2_part3(t_v *v, t_cmd *cmd, t_env *e);
void			ft_check_item_line2_part4(t_v *v, t_cmd *cmd, t_env *e);

/*
** ft_is.c
*/

int				ft_islabel(char *str);
int				ft_isop(char *str, t_env *e);
int				ft_isreg_param(t_item *item);
int				ft_isdir_param(char *s, t_item *item);
int				ft_isparam(t_item *item);

/*
** debug.c
*/

void			ft_print_debug(t_env *e, int nb);

/*
** check_after_storage.c
*/

void			ft_check_item_after_storage(t_env *e);
void			ft_check_param_type_per_op(t_env *e);

/*
** set_code_size_addr.c
*/

void			ft_set_code_to_op_and_num_param(t_env *e);
int				ft_get_label_addr(t_env *e, char *label);
void			ft_set_labels_addr(t_env *e);

/*
** set_size_cmd.c
*/

void			ft_set_size_cmd(t_env *e);

/*
** filter_label.c
*/

void			ft_filter_remove_labels(t_env *e);

/*
** set_encode.c
*/

void			ft_encode(t_env *e);

/*
** binary.c
*/

char			*ft_getbin(int val, int nb_octet);
int				ft_addbin(t_cmd *cmd, int size, int code, int codesize);
void			ft_binary_creation(t_env *e);

/*
** write_infos_msg.c
*/

void			ft_print_message(t_env *e);
void			ft_print_infos(t_env *e);
void			ft_write_outfile(t_env *e);

/*
** debug.c
*/

void			ft_debug0(t_env *e);
void			ft_debug1(t_env *e);
void			ft_print_item_type(t_item *item);
void			ft_debug2(t_env *e);
void			ft_debug3(t_env *e);

/*
** debug2.c
*/

void			ft_debug4(t_env *e);
void			ft_debug5_part2(t_cmd *cmd, t_label *l);
void			ft_debug5(t_env *e);
void			ft_debug6(t_env *e);

/*
** debug3.c
*/

char			*ft_keep_end(char *str);
void			ft_debug7(t_env *e);
void			ft_nodebug(t_env *e);

/*
** flags.c
*/

void			ft_init_gflags(void);
void			ft_check_newname(char *name, t_env *e, int *ac_nb);
int				ft_flags_part2(char c);
void			ft_flags_part3(int v[2], char **av, t_env *e, int *ac_nb);
void			ft_flags(int ac, char **av, int *ac_nb, t_env *e);

/*
** flags2.c
*/

void			ft_file_requirements(void);
void			ft_user_man(void);

#endif
