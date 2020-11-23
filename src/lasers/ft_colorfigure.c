/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorfigure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:29:06 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/24 00:43:29 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_colorsphere(double *vec, double *o, double *t, t_sphere *sp)
{
	double l[3];
	double tca;
	double d2;
	double thc;
	double t0;

	ft_dif_vector(sp->xyz, o, l);
	tca = ft_dot_product(l, vec);
	if (tca < 0)
		return (0);
	d2 = ft_dot_product(l, l) - tca * tca;
	if (d2 > (sp->d * sp->d / 4))
		return (0);
	thc = ft_sqrt((sp->d * sp->d / 4) - d2);
	t0 = ft_t0t1(tca - thc, tca + thc);
	if (t0 && *t > t0)
	{
		*t = t0;
		return (ft_rgb(sp->rgb[0], sp->rgb[1], sp->rgb[2]));
	}
	return (0);
}

int	ft_colorplane(double *vec, double *o, double *t, t_plane *pl)
{
	double l[3];
	double denom;
	double t0;

	t0 = 4000.;
	denom = ft_dot_product(pl->vec, vec);
	if (denom > (1 / 1000000))
	{
		ft_dif_vector(pl->xyz, o, l);
		t0 = ft_dot_product(l, pl->vec) / denom;
	}
	if (t0 && *t > t0)
	{
		*t = t0;
		return (ft_rgb(pl->rgb[0], pl->rgb[1], pl->rgb[2]));
	}
	return (0);
}

int	ft_colorsquare(double *vec, double *o, double *t, t_square *sq)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = *t;
	if (ft_sq_to_pl(vec, o, &t0, sq))
	{
		ft_magxvec(vec, t0, p);
		ft_sum_vector(o, p, p);
		ft_dif_vector(p, sq->xyz, p);
		x = ft_maxx(sq->vec, sq->side * 3 / 4) - fabs(p[0]);
		y = ft_maxy(sq->vec, sq->side * 3 / 4) - fabs(p[1]);
		if (x >= 0 && y >= 0)
		{
			*t = t0;
			return (ft_rgb(sq->rgb[0], sq->rgb[1], sq->rgb[2]));
		}
	}
	return (0);
}

int	ft_colortriangle(double *vec, double *o, double *t, t_triangle *tr)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = *t;
	if (ft_tr_to_pl(vec, o, &t0, tr))
	{
		ft_magxvec(vec, t0, p);
		ft_sum_vector(o, p, p);
		x = ft_angle(tr->xyz, &(tr->xyz[3]), &(tr->xyz[6]));
		y = ft_angle(tr->xyz, &(tr->xyz[6]), &(tr->xyz[3]));
		if (ft_cmpangles(x, y, p, tr))
		{
			*t = t0;
			return (ft_rgb(tr->rgb[0], tr->rgb[1], tr->rgb[2]));
		}
	}
	return (0);
}

int	ft_colorcylinder(double *vec, double *o, double *t, t_cylinder *cy)
{
	double	t0;
	double	p0[3];
	double	a;
	double	b;
	double	delta;

	ft_dif_vector(o, cy->xyz, p0);
	a = pow(vec[0], 2) + pow(vec[2], 2);
	b = vec[0] * p0[0] + vec[2] * p0[2];
	delta = b * b - a * (pow(p0[0], 2) + pow(p0[2], 2) - pow(cy->d / 2, 2));
	if (delta < 0.00000001)
		return (0);
	t0 = (-b - sqrt(delta)) / a;
	if (t0 < 0.00000001)
		return (0);
/*	a = p0[1] + t0 * vec[1];
	if (a > cy->h || a < 0)
	{
		a = ft_intersect_base(vec, cy->xyz - cy->h, &t0);
		}*/
	*t = t0;
	return (ft_rgb(cy->rgb[0], cy->rgb[1], cy->rgb[2]));
}
