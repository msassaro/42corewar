/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <florianpasquereau37@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 13:54:45 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/02 10:11:36 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
**	Description :
**		Ouvre le fichier dont le nom est name avec le mode d'ouverture
**	suivant mode. Le curseur de lecture est au debut du fichier.
**	Mode possible :
**		r : Ouvre le fichier en mode lecture
**		r+: Ouvre le fichier en mode lecture + ecriture
**		w : Ouvre le fichier en mode ecriture.
**		w+: Ouvre le fichier en mode lecture et ecriture. Le cree
**			s'il n'existe pas
**		a : Ouvre le fichier en mode ajout. Place le curseur a la fin
**			du fichier. Le cree s'il n'existe pas
**		a+: Ouvre le fichier en mode ajout. Place le curseur au debut
**			du fichier. Le cree s'il n'existe pas
**	Valeur renvoyee:
**		Retourne le file descriptor du fichier, ou -1 en cas d erreur.
**		L erreur est indiquee dans le flux stderr
**	Mode de creation :
**		00400 : Utilisateur lecture
**		00200 : Utilisateur ecriture
**		00100 : Utitlisatuer execution
**		00040 : Groupe Lecture
**		00020 : Groupe ecriture
**		00010 : Groupe execution
**		00004 : TLM lecture
**		00002 : TLM ecriture
**		00001 : TLM execution
*/

#define LECT "r"
#define LECT_ECR "r+"
#define ECR "w"
#define LECT_ECR_CRE "w+"
#define AJOU_FIN "a"
#define AJOU_DEB "a+"

#define ERROR -1
#define MODE_CREATION 00664

static int			print_error(const char *name, const char *mode)
{
	ft_error(name);
	ft_error(" a echoue en mode ");
	ft_error(mode);
	return (ERROR);
}

int					ft_fopen(const char *name, const char *mode)
{
	int		fd;

	fd = ERROR;
	if (mode == NULL || name == NULL)
		return (ERROR);
	if (ft_strequ(LECT, mode))
		fd = open(name, O_RDONLY);
	else if (ft_strequ(LECT_ECR, mode))
		fd = open(name, O_RDWR);
	else if (ft_strequ(ECR, mode))
		fd = open(name, O_WRONLY | O_TRUNC);
	else if (ft_strequ(LECT_ECR_CRE, mode))
		fd = open(name, O_RDWR | O_CREAT | O_TRUNC, MODE_CREATION);
	else if (ft_strequ(AJOU_FIN, mode))
	{
		if ((fd = open(name, O_RDWR | O_APPEND)) == ERROR)
			fd = open(name, O_RDWR | O_CREAT, MODE_CREATION);
	}
	else if (ft_strequ(AJOU_DEB, mode))
	{
		if ((fd = open(name, O_RDWR)) == ERROR)
			fd = open(name, O_RDWR | O_CREAT, MODE_CREATION);
	}
	return ((fd == ERROR) ? print_error(name, mode) : fd);
}
