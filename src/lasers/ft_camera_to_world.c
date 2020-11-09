/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:04:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 00:14:41 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_quadrant(double x, double y, double rad)
{
	if (x > 0)
	{
		if (y > 0)
			return (rad);
		else
			return (2 * 3.14159 - rad);
	}
	else
	{
		if (y > 0)
			return (3.14159 - rad);
		else
			return (3.14159 + rad);
	}
}

double	ft_movector(double x, double y, double t, double rad)
{
	double	p;
	double	radx;

	radx = acos(x / t);
	radx = ft_quadrant(x, y, radx);
	p = cos(radx + rad) * t;
	return (p);
}

void	ft_camera_to_world(double *p, t_cam *c)
{
	double radx;
	double rady;
	double radz;
	double *px;

	px = p;
	radx = acos(c->vec[0] / 1);
	radx = ft_quadrant(c->vec[0], c->vec[1], radx);
	rady = acos(c->vec[1] / 1);
	rady = ft_quadrant(c->vec[1], c->vec[0], rady);
	radz = 0 - acos(c->vec[2] / 1);
	radz = ft_quadrant(c->vec[2], c->vec[1], radz);
	p[0] = ft_movector(px[0], px[1], ft_magnitude(px), radx);
	p[1] = ft_movector(px[1], px[0], ft_magnitude(px), rady);
	p[2] = ft_movector(px[2], px[1], ft_magnitude(px), radz);
}
