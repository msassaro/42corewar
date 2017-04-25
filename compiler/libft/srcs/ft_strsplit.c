/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:06:02 by msassaro          #+#    #+#             */
/*   Updated: 2015/11/28 17:46:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(const char *s, char c)
{
	int		result;
	int		toogle_in_word;

	result = 0;
	toogle_in_word = 0;
	while (*s != '\0')
	{
		if (toogle_in_word == 1 && *s == c)
			toogle_in_word = 0;
		if (toogle_in_word == 0 && *s != c)
		{
			toogle_in_word = 1;
			result++;
		}
		s++;
	}
	return (result);
}

static int		ft_word_len(const char *s, char c)
{
	int		result;

	result = 0;
	while (*s != c && *s != '\0')
	{
		result++;
		s++;
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		nb_word;

	i = 0;
	nb_word = ft_nb_words((const char *)s, c);
	res = (char **)malloc(sizeof(*res) * (ft_nb_words((const char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (nb_word)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_strsub((const char *)s, 0, ft_word_len((const char *)s, c));
		if (res[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		i++;
		nb_word--;
	}
	res[i] = NULL;
	return (res);
}
