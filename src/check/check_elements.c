/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:53:46 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 11:08:33 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_r(char *line)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || split[3])
		return (ft_strerror("Error\nbad resolution\n", 0, split));
	while (split[1][++i])
		if (split[1][i] < '0' || split[1][i] > '9')
			return (ft_strerror("Error\nbad resolution\n", 0, split));
	i = -1;
	while (split[2][++i])
		if (split[2][i] < '0' || split[2][i] > '9')
			return (ft_strerror("Error\nbad resolution\n", 0, split));
	return (ft_strerror(NULL, 1, split));
}

int	ft_check_a(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || split[3])
		return (ft_strerror("Error\nbad A format\n", 0, split));
	if (!ft_check_double(split[1]))
		return (ft_strerror(" for A format\n", 0, split));
	if (ft_atod(split[1]) < 0 || ft_atod(split[1]) > 1)
		return (ft_strerror("Error\nBad ambient ratio\n", 0, split));
	if (!ft_check_rgb(split[2]))
		return (ft_strerror(" for Ambient\n", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_c(char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nbad camera format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for camera\n", 0, split));
	if (!ft_check_vec(split[2]))
		return (ft_strerror(" for camera\n", 0, split));
	i = -1;
	while (split[3][++i])
		if (split[3][i] < '0' || split[3][i] > '9' || ft_atoi(split[3]) > 180)
			return (ft_strerror("Error\nwrong FOV for camera\n", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_l(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nwrong light format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for light\n", 0, split));
	if (!ft_check_double(split[2]))
		return (ft_strerror(" for light brightness\n", 0, split));
	if (ft_atod(split[2]) < 0. || ft_atod(split[2]) > 1.)
		return (ft_strerror("Error\nl brightness [0.0,1.0]\n", 0, split));
	if (!ft_check_rgb(split[3]))
		return (ft_strerror(" for light\n", 0, split));
	return (ft_strerror("", 1, split));
}
