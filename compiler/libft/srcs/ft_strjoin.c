/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:09:50 by msassaro          #+#    #+#             */
/*   Updated: 2015/12/17 15:06:36 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char			*new_s;
	unsigned int	len;
	unsigned int	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = 0;
	if (s1 != NULL)
		len += ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	if ((new_s = (char*)malloc(sizeof(*new_s) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	len = 0;
	if (s1 != NULL)
		while (s1[i] != '\0')
			new_s[len++] = s1[i++];
	i = 0;
	if (s2 != NULL)
		while (s2[i] != '\0')
			new_s[len++] = s2[i++];
	new_s[len] = '\0';
	return (new_s);
}
