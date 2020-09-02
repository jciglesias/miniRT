/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:55 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/02 01:31:31 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_sp(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		free(split);
		return(0);
	}
	if (!ft_check_xyz(split[1]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_double(split[2]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_rgb(split[3]))
	{
		free(split);
		return (0);
	}
	free(split);
	return (1);
}

int	ft_check_pl(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || split[4])
	{
		free(split);
		return(0);
	}
	if (!ft_check_xyz(split[1]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_vec(split[2]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_rgb(split[3]))
	{
		free(split);
		return (0);
	}
	free(split);
	return (1);
}

int	ft_check_sq(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split [5])
	{
		free(split);
		return(0);
	}
	if (!ft_check_xyz(split[1]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_vec(split[2]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_double(split[3]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_rgb(split[4]))
	{
		free(split);
		return (0);
	}
	free(split);
	return (1);
}

int	ft_check_cy(char *line)
{
	char	**spl;

	spl = ft_split(line, ' ');
	if (!spl[1] || !spl[2] || !spl[3] || !spl[4] || !spl[5] || spl[6])
	{
		free(spl);
		return(0);
	}
	if (!ft_check_xyz(spl[1]))
	{
		free(spl);
		return (0);
	}
	if (!ft_check_vec(spl[2]))
	{
		free(spl);
		return (0);
	}
	if (!ft_check_double(spl[3]))
	{
		free(spl);
		return (0);
	}
	if (!ft_check_double(spl[4]))
	{
		free(spl);
		return (0);
	}
	if (!ft_check_rgb(spl[5]))
	{
		free(spl);
		return (0);
	}
	free(spl);
	return (1);
}

int	ft_check_tr(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
	{
		free(split);
		return(0);
	}
	if (!ft_check_xyz(split[1]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_xyz(split[2]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_xyz(split[3]))
	{
		free(split);
		return (0);
	}
	if (!ft_check_rgb(split[4]))
	{
		free(split);
		return (0);
	}
	free(split);
	return (1);
}
