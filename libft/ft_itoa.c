/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:22:20 by jiglesia          #+#    #+#             */
/*   Updated: 2019/11/08 17:18:49 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_tochar(char *str, unsigned int *i, unsigned int n)
{
	if (n > 9)
		ft_tochar(str, i, n / 10);
	str[(*i)++] = n % 10 + '0';
}

static size_t	ft_size(int n)
{
	size_t		i;

	if (n < 0)
		i = 2;
	else
		i = 1;
	while (n /= 10)
		i++;
	return (++i);
}

char			*ft_itoa(int n)
{
	unsigned int		i;
	char				*str;
	unsigned int		a;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)ft_calloc(ft_size(n), sizeof(char))))
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	a = (n < 0) ? -n : n;
	ft_tochar(str, &i, a);
	str[i] = 0;
	return (str);
}
