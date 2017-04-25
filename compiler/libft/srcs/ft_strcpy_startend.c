/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:47:46 by msassaro          #+#    #+#             */
/*   Updated: 2016/05/03 07:08:36 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_startend(char *src, int start, int end)
{
	int		i;
	int		len;
	char	*result;
	int		j;

	i = 0;
	j = 0;
	if (start > end || start < 0 || end < 0)
		return (NULL);
	len = end - start + 1;
	if (len < 1)
		return (NULL);
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = start;
	while (src[i] && i <= end && j < len)
	{
		result[j] = src[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
