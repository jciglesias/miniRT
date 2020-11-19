/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:04:12 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/19 23:51:39 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_quadrant(double x, double y, double rad)
{
	if (x >= 0)
	{
		if (y >= 0)
			return (rad);
		else
			return (2 * 3.141593 - rad);
	}
	else
	{
		if (y > 0)
			return (3.141593 - rad);
		else
			return (3.141593 + rad);
	}
}

void	ft_movector(double x, double y, double z, double *p)
{
	double	px[3];

	px[0] = p[0] * cos(y) * cos(z) + p[1] * (sin(y) * sin(x) * cos(z) - cos(x) * sin(y)) + p[2] * (sin(y) * cos(x) * cos(z) + sin(x) * sin(z));
	px[1] = p[0] * cos(y) * sin(z) + p[1] * (sin(x) * sin(y) * sin(z) + cos(x) * cos(z)) + p[2] * (cos(x) * sin(y) * sin(z) - sin(x) * cos(z));
	px[2] = p[0] * (-sin(y)) + p[1] * sin(x) * cos(y) + p[2] * cos(x) * cos(y);
	p[0] = px[0];// * (-1);
	p[1] = px[1];
	p[2] = px[2];// * (-1);
}

double	ft_hipo(double a, double b)
{
	double c;

	c = ft_sqrt(a * a + b * b);
	return (c);
}

void	ft_crossp(double *a, double *b, double *p)
{
	p[0] = a[1] * b[2] - a[2] * b[1];
	p[1] = a[2] * b[0] - a[0] * b[2];
	p[2] = a[0] * b[1] - a[1] * b[0];
}

void	ft_camera_to_world(double *p, t_cam *c)
{
	double radx;
	double rady;
	double z;
	double x;
	double hipo;

	/*px = p;
	hipo = ft_hipo(c->vec[0], c->vec[1]);
	radz = 0;
	if (hipo)
		radx = acos(c->vec[0] / hipo);
		radz = ft_quadrant(c->vec[0], c->vec[1], radz);*/
	x = c->vec[0];
	z = c->vec[2];
	if (x < 0)
		x *= -1;
	if (z < 0)
		z *= -1;
	hipo = ft_hipo(c->vec[0], c->vec[2]);
	rady = 0;
	if (hipo)
		rady = acos(x / hipo);
	if (rady)
		rady = ft_quadrant(c->vec[0], c->vec[2], rady) - (3.141593 * 3 / 2);
/*	if (c->vec[2] != -1 && x && z)
	rady -= (3.141593 * 3 / 2);*/
	hipo = ft_hipo(c->vec[2], c->vec[1]);
	radx = 0;
	if (hipo)
		radx = acos(z / hipo);
	radx = ft_quadrant((-1) * c->vec[2], c->vec[1], radx);
	if (c->vec[1] == -1)
		radx = -3.141593 / 2;
	if (c->vec[1] == 1)
		radx = 3.141593 / 2;
	ft_movector(radx, rady, 0, p);
}
