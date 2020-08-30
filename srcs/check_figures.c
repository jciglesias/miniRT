/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:55:55 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/31 00:25:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_sp(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_check_xyz(split[1]))
		return (0);
}

int	ft_check_pl(char *line)
{}

int	ft_check_sq(char *line)
{}

int	ft_check_cy(char *line)
{}

int	ft_check_tr(char *line)
{}
