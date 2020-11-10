/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:04:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 22:28:26 by jiglesia         ###   ########.fr       */
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

double	ft_movector(double x, double t, double rad)
{
	double	p;
	double	radx;

	radx = acos(x / t);
	p = cos(radx + rad) * t;
	return (p);
}

double	ft_hipo(double a, double b)
{
	double c;

	c = ft_sqrt(a * a + b * b);
	return (c);
}

void	ft_camera_to_world(double *p, t_cam *c)
{
	double radx;
	double rady;
	double radz;
	double *px;
	double hipo;

	px = p;
	hipo = ft_hipo(c->vec[0], c->vec[1]);
	radx = 0;
	if (hipo)
		radx = acos(c->vec[0] / hipo);
	radx = ft_quadrant(c->vec[0], c->vec[1], radx);
	rady = 0;
	if (hipo)
		rady = acos(c->vec[1] / hipo);
	rady = ft_quadrant(c->vec[1], c->vec[0], rady);
	hipo = ft_hipo(c->vec[2], c->vec[1]);
	radz = 0;
	if (hipo)
		radz = 0 - acos(c->vec[2] / hipo);
	radz = ft_quadrant(c->vec[2], c->vec[1], radz);
	p[0] = ft_movector(px[0], ft_hipo(px[0], px[1]), radx);
	p[1] = ft_movector(px[1], ft_hipo(px[0], px[1]), rady);
	p[2] = ft_movector(px[2], ft_hipo(px[2], px[1]), radz);
}
