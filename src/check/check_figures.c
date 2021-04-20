/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:55 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 11:24:13 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_sp(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nbad sp format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for sp\n", 0, split));
	if (!ft_check_double(split[2]))
		return (ft_strerror(" for sp diameter\n", 0, split));
	if (!ft_check_rgb(split[3]))
		return (ft_strerror(" for sp\n", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_pl(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nbad pl format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for plane\n", 0, split));
	if (!ft_check_vec(split[2]))
		return (ft_strerror(" for plane\n", 0, split));
	if (!ft_check_rgb(split[3]))
		return (ft_strerror(" for plane\n", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_sq(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		return (ft_strerror("Error\nbad sq format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for square\n", 0, split));
	if (!ft_check_vec(split[2]))
		return (ft_strerror(" for square\n", 0, split));
	if (!ft_check_double(split[3]))
		return (ft_strerror(" for square side\n", 0, split));
	if (!ft_check_rgb(split[4]))
		return (ft_strerror(" for square\n", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_cy(char *line)
{
	char	**spl;

	spl = ft_split(line, ' ');
	if (!spl[1] || !spl[2] || !spl[3] || !spl[4] || !spl[5] || spl[6])
		return (ft_strerror("Error\nbad cy format\n", 0, spl));
	if (!ft_check_xyz(spl[1]))
		return (ft_strerror(" for cylinder\n", 0, spl));
	if (!ft_check_vec(spl[2]))
		return (ft_strerror(" for cylinder\n", 0, spl));
	if (!ft_check_double(spl[3]))
		return (ft_strerror(" for cylinder diameter\n", 0, spl));
	if (!ft_check_double(spl[4]))
		return (ft_strerror(" for cylinder height\n", 0, spl));
	if (!ft_check_rgb(spl[5]))
		return (ft_strerror(" for cylinder\n", 0, spl));
	return (ft_strerror("", 1, spl));
}

int	ft_check_tr(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		return (ft_strerror("Error\nbad tr format\n", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror(" for triangle\n", 0, split));
	if (!ft_check_xyz(split[2]))
		return (ft_strerror(" for triangle\n", 0, split));
	if (!ft_check_xyz(split[3]))
		return (ft_strerror(" for triangle\n", 0, split));
	if (!ft_check_rgb(split[4]))
		return (ft_strerror(" for triangle\n", 0, split));
	return (ft_strerror("", 1, split));
}
