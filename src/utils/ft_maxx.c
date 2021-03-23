/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:35:11 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/11 20:00:06 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_maxx(double *n, double mag)
{
	double	radx;

	radx = 0;
	if (ft_hipo(n[0], n[2]))
		radx = (3.141593 / 4) - acos(n[0] / ft_hipo(n[0], n[2]));
	return (cos(radx) * mag);
}

double	ft_maxy(double *n, double mag)
{
	double	rady;

	rady = 0;
	if (ft_hipo(n[0], n[2]))
		rady = (3.141593 / 4) - acos(n[1] / ft_hipo(n[2], n[1]));
	return (cos(rady) * mag);
}

double	ft_maxz(double *n, double mag)
{
	double	radz;

	radz = 0;
	if (ft_hipo(n[1], n[2]))
		radz = (3.141593 / 4) - acos(n[2] / ft_hipo(n[1], n[2]));
	return (cos(radz) * mag);
}
