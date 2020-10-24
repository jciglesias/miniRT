/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:55:53 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/13 01:12:25 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_rgb(int *a, char *line)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(line, ',');
	while (split[++i])
		a[i] = ft_atoi(split[i]);
	ft_strerror("", 0, split);
}

void	ft_fill_xyz(double *a, char *line)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(line, ',');
	while (split[++i])
		a[i] = ft_atod(split[i]);
	ft_strerror("", 0, split);
}
