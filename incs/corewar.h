/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:32:51 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/16 09:32:53 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "virtual_machine.h"
# include <fcntl.h>

# define T_REG 1
# define T_DIR 2
# define T_IND 3

# define MASK_6_BITS 0x30
# define MASK_4_BITS 0xC

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

# define ERROR_MALLOC 10
# define ERROR_READ 11
# define ERROR_FILE 12
# define ERROR_SIZE_CHAMP 13
# define ERROR_REG 55
# define ERROR_OCP 56

# define DIR_C 30
# define IND_C 31
# define REG_C 32

# define NB_LIVE_MIN 21
# define CHECKS_MAX 10

typedef struct				s_ocp
{
	int						i;
	int						(*p)(t_vm *vm, t_player *plr, int octet, int index);
}							t_ocp;

typedef struct				s_delais
{
	char					instruction;
	int						delais;
}							t_delais;

typedef struct				s_instruction
{
	char					instruction;
	int						(*p)(t_vm *vm, t_player *plr);
	int						epd;
}							t_instruction;

typedef struct				s_ocp_param
{
	char					instruction;
	char					f_p[4];
	char					s_p[4];
	char					t_p[4];
	int						nb_param;
}							t_ocp_param;

char						*ft_recover_name_champ(int fd);
char						*ft_recover_comment_champ(int fd, int *champ_size);
int							ft_open_file(char **str, int nb_champ,
		t_player *champ, t_array *array);
void						ft_recover_instruction(int fd, t_array *array,
		int *size);
int							ft_parse_instruction(char *str, t_array *array);
int							ft_power(int power, int nb);

/*
** UTILITAIRE
*/

void						ft_parse_info(t_vm *vm, t_player *plr);
int							ft_convert_hexa_to_int(unsigned char *str);
char						*ft_llitoa_base(long long int n, int base, int *u);
char						*ft_llitoa_base2(long long int n, int base, int *u);
int							ft_check_size_max(int i, int index);
int							ft_param_0_octet(t_vm *vm, t_player *plr,
		int octet, int index);
int							ft_param_4_octets(t_vm *vm, t_player *plr,
		int octet, int index);
int							ft_param_1_octets(t_vm *vm, t_player *plr,
		int octet, int index);
void						ft_print_param_to_array_4_octets(t_vm *vm,
		t_player *plr, int index, unsigned int nb);
int							ft_check_size_max(int i, int index);
void						pop_winner_last_process(t_vm *vm);
void						ft_parse_info(t_vm *vm, t_player *plr);
int							ft_check_size_max2(int i, int index);

/*
** DIVERS INSTRUCTION
*/

void						ft_processus(t_vm *vm);
void						ft_check_processus_life(t_vm *vm);
void						ft_check_delais(t_vm *vm, t_player *plr);
void						ft_parse_info(t_vm *vm, t_player *plr);
int							ft_indirect_param(t_vm *vm, t_player *plr,
								int move);

/*
** OPERATIONS / BITWISES
*/

int							ft_aff(t_vm *vm, t_player *plr);
int							ft_and(t_vm *vm, t_player *plr);
int							ft_xor(t_vm *vm, t_player *plr);
int							ft_or(t_vm *vm, t_player *plr);
int							ft_sub(t_vm *vm, t_player *plr);
int							ft_add(t_vm *vm, t_player *plr);
int							ft_nothing(t_vm *vm, t_player *plr);
int							ft_sti(t_vm *vm, t_player *plr);
int							ft_zjmp(t_vm *vm, t_player *plr);
int							ft_live(t_vm *vm, t_player *plr);
int							ft_ldi(t_vm *vm, t_player *plr);
int							ft_fork(t_vm *vm, t_player *plr);

int							ft_ld(t_vm *vm, t_player *plr);
int							ft_lld(t_vm *vm, t_player *plr);
int							ft_lfork(t_vm *vm, t_player *plr);
int							ft_st(t_vm *vm, t_player *plr);

#endif
