#include "asm.h"

/*
** PARSE_HEADER:
** Dans cette fonction, on va commencer par aller chercher (et checker) le
** nom et comment. Si ce ne sont pas les deux premieres lignes (lignes de
** commentaires et lignes vides ne comptent pas) ou si les conditions
** d'acceptation du nom/comment ne sont pas la (max size) alors c'est error.
** Autrement on set e->name et e->comment.
** .
** STORE_ITEMS:
** Ensuite on va recuperer chaque 'item' de chaque ligne. Dans chaque e->cmd
** on aura une liste chainee item qui contiendra ces items.
** Les items sont les labels, les op, les params.
** Lorsque on les ajoute a la liste chainee, on met le masque correspondant a
** leur type. 0x10, 0x20, 0x40 pour (resp.) LABEL, OP et PARAM
** .
** CHECK_ITEM_AFTER_STORAGE:
** On va ici parcourir les e->cmd et pour chaque item, on va verifier si son
** type correspond bien au masque qu'on lui a attribuer. si ce n'est pas le cas
** on enverra une erreur.
** .
** CHECK_PARAM_TYPE_PER_OP:
** On va checker tous les items, et on va regarder dans chaque cmd l'instruction
** Si l'instruction existe pas --> error. Sinon on va verifier que les params,
** qui sont les items suivants dans le cmd, correspondent bien au nombre et type
** de params attendu par cette instruction.
** .
** SET_CODE_OP_AND_NUM_PARAM:
** Ici on va aller regarder les items dans les e->cmd. En fonction du type de
** l'item (voir masques au dessus), si l'item est un OP alors on va aller
** mettre dans item->code l'opcode qui correspond a cet OP.
** Si l'item est un param, et que c'est un Registre ou pas un label, alors on va
** mettre la valeur qu'il a en parametre dans son code.
** (exemple: item:r1 ---> on met item->code = 1)
** .
** SET_SIZE_AND_ADDR_CMD:
** Ici on va aller mettre l'adresse dans chaque cmd. Pour ca on va parcourir les
** e->cmd et regarder leur items. En fonction du type de parametre, on va
** ajouter la 'size' du type de param en question a cmd->size. Si l'op
** a un encodage alors on rajoute cela a size.
** A la fin des items du cmd, on a la taille du cmd.
** .
** SET_PROGRAM_HEADER:
** Ici, on va mettre les addresses correspondantes a chaque e->cmd.
** Le premier cmd est a addr 0, ensuite on avance de cmd->size et on a l'addr
** du cmd suivamt. A la fin on a la taille totale des cmd.
** On met cette taille dans e->header.prog_size. (en appliquant ft_reverse car
** cas de little endian)
** On set egalement e->header.prog_name (en fonction du renomage avec flag -n
** ou pas) et e->header.comment et e->header.magic (ft_reverse).
** .
** SET_LABEL_ADDR:
** Ici on va parcourir les items des e->cmd. Pour chaque item qui est un LABEL,
** on va le push dans e->label.
** Ensuite, pour chaque item T_LAB, on va chercher le label correspondant et
** mettre l'addresse relative dans item->code.
** example: zjmp %:live --> on va aller chercher l'item de type label qui se
** nome 'live' et mettre l'addresse dans item->code. Addresse relative au cmd
** en cours.
** .
** FILTER_REMOVE_LABELS:
** on va juste remove les labels des cmd, et remove les cmd vide.
** .
** ENCODE:
** Ici on va faire l'encodage.
** .
** BINARY CREATION:
** Ici on va creer le binaire pour chaque e->cmd. Pour cela, on va parcourir
** les items contenus dans le cmd.
** On va recuperer la valeur contenue dans item->code et la mettre dans un
** buffer, splitee.
** De base, on commence par utiliser ft_reverse sur la valeur du code (little
** endian) et pour chaque case du buffer, on va y mettre la valeur decalee
** d'un octet (d'ou le i += 8).
** A la fin, on concat le buffer a la fin de cmd->bin et on continue pour
** chaque item.
** On aura donc le binaire associe a chaque e->cmd
*/

void	ft_parse(t_env *e)
{
	ft_parse_header(e);
	(g_flag_d == 1) ? ft_debug0(e) : ft_nodebug(e);
	ft_store_items(e);
	(g_flag_d == 1) ? ft_debug1(e) : ft_nodebug(e);
	ft_check_item_after_storage(e);
	ft_check_param_type_per_op(e);
	ft_set_code_to_op_and_num_param(e);
	(g_flag_d == 1) ? ft_debug2(e) : ft_nodebug(e);
	ft_set_size_cmd(e);
	ft_set_addr_and_header(e);
	(g_flag_d == 1) ? ft_debug3(e) : ft_nodebug(e);
	ft_set_labels_addr(e);
	(g_flag_d == 1) ? ft_debug4(e) : ft_nodebug(e);
	ft_filter_remove_labels(e);
	(g_flag_d || g_flag_c) ? ft_debug5(e) : ft_nodebug(e);
	ft_encode(e);
	(g_flag_k == 1) ? ft_debug6(e) : ft_nodebug(e);
	ft_binary_creation(e);
	(g_flag_b == 1) ? ft_debug7(e) : ft_nodebug(e);
}

/*
** On va entrer dans le programme ici et regarder le nombre d'arguments que
** l'on a recu.
** .
** On commence deja par init l'environement et les flags.
** .
** On recupere les flags et on va recuperer le ac_nb. ac_nb sera le numero
** de l'argument qui est le fichier que l'on va devoir checker et parser.
** .
** Ensuite on va checker le format du fichier. (extension etc). On recupere
** par la meme occasion le nom du fichier output.
** .
** On va lire le fichier, ligne par ligne avec GNL. On met chaque ligne dans
** e->cmd->line. On aura donc acces aux lignes du fichier dans l'environement e
** .
** On v parser les lignes que l'on vient de recuperer. Le but etant de 'ranger'
** dans cmd les instructions, opcode etc de chaque commande. Et a terme d'y
** mettre le binaire.
** .
** On va enfin ouvrir le fichier output en creation et ecrire dedans le
** header (contient prog_name, comment, prog_size et le corewar magic)
** (magic est une signature sans laquelle la vm refusera le champion)
** Ensuite on y ecrira chaque cmd->bin = le binaire de chaque commande.
*/

int		main(int ac, char **av)
{
	t_env	e;
	int		ac_nb;

	ac_nb = 1;
	ft_init_gflags();
	ft_init_env(&e);
	if (ac > 1)
	{
		ft_flags(ac, av, &ac_nb, &e);
		if (ac_nb > ac || !av[ac_nb])
			ft_strerror("no input file", "..");
		ft_check_file_format(&e, av[ac_nb]);
		ft_read_file(av[ac_nb], &e);
		ft_parse(&e);
		ft_write_outfile(&e);
		ft_print_infos(&e);
		ft_printf("asm: file {green}%s{eoc} created\n", e.output);
	}
	else
		ft_printf_fd(2, "{red}asm: error: no input file\n\tuse ./asm -h\n");
	return (0);
}
