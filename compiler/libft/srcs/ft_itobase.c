/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:01:56 by msassaro          #+#    #+#             */
/*   Updated: 2016/01/22 17:01:58 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itobase(unsigned long long int nb, const char *base)
{
	int							base_len;
	char						*str;
	int							i;
	unsigned long long int		tmp;

	base_len = ft_strlen(base);
	if (nb == 0 || base_len == 0)
		return (ft_strdup("0"));
	tmp = nb;
	i = 1;
	while ((tmp /= base_len) != 0)
		i++;
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base[tmp % base_len];
		tmp /= base_len;
	}
	return (str);
}
