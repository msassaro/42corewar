/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:28:33 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/10 18:59:32 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** GLOBAL ON WCHAR AND UNICODE
** WCHAR_T = WIDE CHAR TYPE and it is a wide char in hexadecimal value
** WCHAR_MIN = (hexa) 0x80000000 || (decimal) -2147483648
** WCHAR_MAX = (hexa )0x7fffffff || (decimal) +2147483647
** we create an unicode mask to convert wchar into unicode
** to KNOW binary value use ==> echo -n "是"| xxd -b
** to KNOW hexa value use ==> echo -n "是"| xxd
*/

/*
** this fct will split the unicode with mask into different octal, into a
** **wchar_final tab. Each octal for each floor.
*/

static char				**ft_split_unicod(char *wchar)
{
	char	**wchar_final;
	int		i;
	int		j;
	int		k;

	wchar_final = ft_alloc_tab(4, 16);
	k = 0;
	i = 0;
	while (i <= (int)ft_strlen(wchar))
	{
		j = 0;
		while ((wchar[i] != ' ') && (j < 8))
		{
			wchar_final[k][j] = wchar[i];
			j++;
			i++;
		}
		wchar_final[k][j] = '\0';
		i++;
		k++;
	}
	wchar_final[k] = NULL;
	free(wchar);
	return (wchar_final);
}

/*
** this function will convert a binary into a decimal.
*/

static void				ft_wchar_bin_to_dec(char **tab, t_str *wchar)
{
	int		i;

	i = 0;
	wchar->str = (char*)malloc(sizeof(char) * 4 + 1);
	while (tab[i] != NULL)
	{
		wchar->str[i] = (char)ft_binary_to_dec(tab[i]);
		i++;
	}
	wchar->str[i] = '\0';
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
** this fct will look at the length of the binary number corresponding to the
** special wchar we want.
** Depending on the length, we will apply the corresponding unicod mask to it.
** When the mask is applied, we then split all octal then convert each octal
** into an int. This int, converted to a char, will be a part of the wanted
** wchar.
*/

static char				*ft_wchar_parse_2(int size, char *wchar,
						t_str *wchar_final)
{
	if (size <= 7)
		wchar = ft_unicod_fill(wchar, "0xxxxxxx");
	else if (7 < size && size <= 11)
		wchar = ft_unicod_fill(wchar, "110xxxxx 10xxxxxx");
	else if (11 < size && size <= 16)
		wchar = ft_unicod_fill(wchar, "1110xxxx 10xxxxxx 10xxxxxx");
	else if (16 < size)
		wchar = ft_unicod_fill(wchar, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	if (size <= 7)
		wchar_final->len = 1;
	else if (7 < size && size <= 11)
		wchar_final->len = 2;
	else if (11 < size && size <= 16)
		wchar_final->len = 3;
	else if (16 < size)
		wchar_final->len = 4;
	else
		wchar_final->len = 0;
	return (wchar);
}

/*
** this fct will look at the length of the binary number corresponding to the
** special wchar we want.
** Depending on the length, we will apply the corresponding unicod mask to it.
** When the mask is applied, we then split all octal then convert each octal
** into an int. This int, converted to a char, will be a part of the wanted
** wchar.
*/

static t_str			*ft_wchar_parse(unsigned int w, t_str *wchar_final)
{
	char	*wchar;
	int		size;
	char	**wchar_split;

	wchar = ft_itobase(w, "01");
	size = ft_strlen(wchar);
	wchar = ft_wchar_parse_2(size, wchar, wchar_final);
	wchar_split = ft_split_unicod(wchar);
	ft_wchar_bin_to_dec(wchar_split, wchar_final);
	return (wchar_final);
}

/*
** this fct in the main entry for wchar
*/

t_str					*ft_printf_wchar(wchar_t reception)
{
	unsigned int		w;
	t_str				*wchar;

	wchar = malloc(sizeof(wchar));
	w = reception;
	ft_wchar_parse(w, wchar);
	return (wchar);
}
