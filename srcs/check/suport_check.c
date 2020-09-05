/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:47:23 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/05 00:11:07 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_double(char *dob)
{
	int	i;

	i = 0;
	if (dob[i] == '-')
		i++;
	if (dob[i] < '0' || dob[i] > '9')
		return (ft_puterror("Error\nno double ", 0));
	while (dob[++i])
	{
		if (dob[i] == '.')
				i++;
		if (dob[i] < '0' || dob[i] > '9')
			return (ft_puterror("Error\nno double ", 0));
	}
	return (1);
}

int	ft_check_xyz(char *xyz)
{
	char	**split;
	int		i;

	split = ft_split(xyz, ',');
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (ft_strerror("Error\nwrong xyz ", 0, split));
	i = 0;
	while (split[i])
		if (!ft_check_double(split[i++]))
			return (ft_strerror("Error\nwrong xyz ", 0, split));
	return (ft_strerror("", 1, split));
}

int	ft_check_vec(char *vec)
{
	char	**split;
	int		i;

	split = ft_split(vec, ',');
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (ft_strerror("Error\nwrong vector ", 0, split));
	i = -1;
	while (split[++i])
	{
		if (!ft_check_double(split[i]))
			return (ft_strerror("for vector ", 0, split));
		if (ft_atod(split[i]) < -1. || ft_atod(split[i]) > 1.)
			return (ft_strerror("Error\nvector [-1.0,1.0] ", 0, split));
	}
	return (ft_strerror("", 1, split));
}

int	ft_check_int(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_check_rgb(char *rgb)
{
	char	**split;
	int		i;

	split = ft_split(rgb, ',');
	if (!split[0] || !split[1] || !split[2] || split[3])
		return (ft_strerror("Error\nwrong color ", 0, split));
	i = -1;
	while (split[++i])
	{
		if (!ft_check_int(split[i]))
			return (ft_strerror("Error\nwrong color ", 0, split));
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (ft_strerror("Error\nwrong color ", 0, split));
	}
	return (ft_strerror("", 1, split));
}
