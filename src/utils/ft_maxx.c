/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:35:11 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/11 20:58:26 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_maxx(double *n, double mag)
{
	double	radx;

	radx = (3.14159 / 4) - acos(n[0] / ft_hipo(n[0], n[2]));
	return (cos(radx) * mag);
}

double	ft_maxy(double *n, double mag)
{
	double	rady;

	rady = (3.14159 / 4) - acos(n[1] / ft_hipo(n[2], n[1]));
	return (cos(rady) * mag);
}
