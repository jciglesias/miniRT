/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:21:07 by jiglesia          #+#    #+#             */
/*   Updated: 2021/02/13 14:23:54 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_cpyrgb(int *rgb, int *color)
{
	int i;

	i = 0;
	while (i < 3)
	{
		color[i] = rgb[i];
		i++;
	}
}

void	ft_veccpy(double *p, double *p0)
{
	int i;

	i = -1;
	while (++i < 3)
		p0[i] = p[i];
}
