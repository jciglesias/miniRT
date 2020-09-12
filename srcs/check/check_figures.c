/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:55 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/12 18:35:15 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_sp(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nbad sp format", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror("for sp", 0, split));
	if (!ft_check_double(split[2]))
		return (ft_strerror("for sp diameter", 0, split));
	if (!ft_check_rgb(split[3]))
		return (ft_strerror("for sp", 0, split));
	free(line);
	return (ft_strerror("", 1, split));
}

int	ft_check_pl(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
		return (ft_strerror("Error\nbad pl format", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror("Error\nfor plane", 0, split));
	if (!ft_check_vec(split[2]))
		return (ft_strerror("Error\nfor plane", 0, split));
	if (!ft_check_rgb(split[3]))
		return (ft_strerror("Error\nfor plane", 0, split));
	free(line);
	return (ft_strerror("", 1, split));
}

int	ft_check_sq(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		return (ft_strerror("Error\nbad sq format", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror("for square", 0, split));
	if (!ft_check_vec(split[2]))
		return (ft_strerror("for square", 0, split));
	if (!ft_check_double(split[3]))
		return (ft_strerror("for square side", 0, split));
	if (!ft_check_rgb(split[4]))
		return (ft_strerror("for square", 0, split));
	free(line);
	return (ft_strerror("", 1, split));
}

int	ft_check_cy(char *line)
{
	char	**spl;

	spl = ft_split(line, ' ');
	if (!spl[1] || !spl[2] || !spl[3] || !spl[4] || !spl[5] || spl[6])
		return (ft_strerror("Error\nbad cy format", 0, spl));
	if (!ft_check_xyz(spl[1]))
		return (ft_strerror("for cylinder", 0, spl));
	if (!ft_check_vec(spl[2]))
		return (ft_strerror("for cylinder", 0, spl));
	if (!ft_check_double(spl[3]))
		return (ft_strerror("for cylinder diameter", 0, spl));
	if (!ft_check_double(spl[4]))
		return (ft_strerror("for cylinder height", 0, spl));
	if (!ft_check_rgb(spl[5]))
		return (ft_strerror("for cylinder", 0, spl));
	free(line);
	return (ft_strerror("", 1, spl));
}

int	ft_check_tr(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		return (ft_strerror("Error\nbad tr format", 0, split));
	if (!ft_check_xyz(split[1]))
		return (ft_strerror("for triangle", 0, split));
	if (!ft_check_xyz(split[2]))
		return (ft_strerror("for triangle", 0, split));
	if (!ft_check_xyz(split[3]))
		return (ft_strerror("for triangle", 0, split));
	if (!ft_check_rgb(split[4]))
		return (ft_strerror("for triangle", 0, split));
	free(line);
	return (ft_strerror("", 1, split));
}
