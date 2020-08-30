/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:53:46 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/30 20:39:25 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_r(char *line)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(line, ' ');
	if (!split[1] || !split[2])
		return (0);
	while (split[1][++i])
		if (split[1][i] < '0' || split[1][i] > '9')
			return (0);
	i = -1;
	while (split[2][++i])
		if (split[2][i] < '0' || split[2][i] > '9')
			return (0);
	if (!split[3])
		return (1);
	return (0);
}

int	ft_check_a(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2])
		return (0);
	if (!ft_check_double(split[1]))
		return (0);
	if (split[1][2] && ((split[1][2] > '0' && split[1][0] >= '1') ||
						split[1][1] != '.'))
		return (0);
	if (!ft_check_rgb(split[2]))
		return (0);
	if (!split[3])
		return (1);
	return (0);
}

int	ft_check_c(char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3])
		return (0);
	if (!ft_check_xyz(split[1]))
		return (0);
	if (!ft_check_vec(split[2]))
		return (0);
	i = -1;
	while (split[3][++i])
		if (split[3][i] < '0' || split[3][i] > '9')
			return (0);
	if (!split[4])
		return (1);
	return (0);
}

int	ft_check_l(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3])
		return (0);
	if (!ft_check_xyz(split[1]))
		return (0);
	if (!ft_check_double(split[2]))
		return (0);
	if (split[1][2] && ((split[2][2] > '0' && split[2][0] >= '1') ||
						split[2][1] != '.'))
		return (0);
	if (!ft_check_rgb(split[3]))
		return (0);
	if (!split[4])
		return (1);
	return (0);
}