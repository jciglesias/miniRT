/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:04:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/13 15:49:54 by jiglesia         ###   ########.fr       */
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

void	ft_movector(double radx, double rady, double *p)
{
	double	px[3];

	px[0] = p[0] * cos(rady) + p[1] * sin(rady) * sin(radx) + p[2] * sin(rady) * cos(radx);
	px[1] = p[1] * cos(radx) + p[2] * (-sin(radx));
	px[2] = p[0] * (-sin(rady)) + p[1] * sin(radx) * cos(rady) + p[2] * cos(radx) * cos(rady);
	p[0] = px[0];
	p[1] = px[1];
	p[2] = px[2];
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
	//double radz;
	//double *px;
	double hipo;

	/*px = p;
	hipo = ft_hipo(c->vec[0], c->vec[1]);
	radz = 0;
	if (hipo)
		radx = acos(c->vec[0] / hipo);
		radz = ft_quadrant(c->vec[0], c->vec[1], radz);*/
	hipo = ft_hipo(c->vec[0], c->vec[1]);
	rady = 0;
	if (hipo)
		rady = acos(c->vec[1] / hipo);
	rady = ft_quadrant(c->vec[1], c->vec[0], rady);
	hipo = ft_hipo(c->vec[2], c->vec[1]);
	radx = 0;
	if (hipo)
		radx = acos(c->vec[2] / hipo);
	radx = ft_quadrant(c->vec[2], c->vec[1], radx);
	ft_movector(radx, rady, p);
	//p[1] = ft_movector(px[1], ft_hipo(px[0], px[1]), rady);
	//p[2] = ft_movector(px[2], ft_hipo(px[2], px[1]), radz);
}
