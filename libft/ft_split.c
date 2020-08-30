/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:15:41 by jiglesia          #+#    #+#             */
/*   Updated: 2019/10/24 16:34:12 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		every_char(const char *str, int pos, char c)
{
	if (str[pos] == c)
		return (1);
	return (0);
}

static int		ft_count_letters(const char *str, int letrs, char c)
{
	while (str[letrs] && !every_char(str, letrs, c))
		letrs++;
	return (letrs);
}

static int		ft_count_words(const char *str, int spos, int cont, char c)
{
	while (str[spos] && every_char(str, spos, c))
		spos++;
	if (!str[spos])
		return (cont);
	while (str[spos] && !every_char(str, spos, c))
		spos++;
	return (ft_count_words(str, spos, cont + 1, c));
}

static char		**ft_decompose(char **tab, const char *str, int spos, char c)
{
	int letrs;
	int i;
	int tpos;

	tpos = 0;
	while (str[spos])
	{
		while (str[spos] && every_char(str, spos, c))
			spos++;
		if (!str[spos])
			break ;
		letrs = ft_count_letters(str, spos, c);
		if (!(tab[tpos] = (char*)malloc(sizeof(char) * (letrs + 1 - spos))))
			return (0);
		i = 0;
		while (str[spos] && !every_char(str, spos, c))
		{
			tab[tpos][i] = str[spos];
			spos++;
			i++;
		}
		tab[tpos++][i] = '\0';
	}
	tab[tpos] = 0;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char **tab;

	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) *
								(ft_count_words(s, 0, 0, c) + 1))))
			return (NULL);
		return (ft_decompose(tab, s, 0, c));
	}
	return (NULL);
}
