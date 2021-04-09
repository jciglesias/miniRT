/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obstructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:40:27 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/09 14:51:59 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_sp_obstruction(double t, double *v, double *o, t_sphere *sp)
{
	double l[3];
	double tca;
	double d2;
	double thc;
	double t0;

	ft_dif_vector(sp->xyz, o, l);
	tca = ft_dot_product(l, v);
	if (tca < 0)
		return (0);
	d2 = ft_dot_product(l, l) - tca * tca;
	if (d2 > (sp->d * sp->d / 4))
		return (0);
	thc = ft_sqrt((sp->d * sp->d / 4) - d2);
	t0 = ft_t0t1(tca - thc, tca + thc);
	if (t < t0)
		return (0);
	else
		return (1);
}

int		ft_pl_obstruction(double t, double *v, double *o, t_plane *pl)
{
	double l[3];
	double denom;
	double t0;

	t0 = 4000.;
	denom = ft_dot_product(pl->vec, v);
	if (denom)
	{
		ft_dif_vector(pl->xyz, o, l);
		t0 = ft_dot_product(l, pl->vec) / denom;
	}
	if (t0 && t > t0 && t0 >= 0)
		return (1);
	else
		return (0);
}

int		ft_sq_obstruction(double t, double *v, double *o, t_square *sq)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;
	double	z;

	t0 = t;
	if (ft_sq_to_pl_obst(v, o, &t0, sq))
	{
		ft_magxvec(v, t0, p);
		ft_sum_vector(o, p, p);
		ft_dif_vector(p, sq->xyz, p);
		x = ft_maxx(sq->vec, sq->side * 3 / 4) - fabs(p[0]);
		y = ft_maxy(sq->vec, sq->side * 3 / 4) - fabs(p[1]);
		z = ft_maxz(sq->vec, sq->side * 3 / 4) - fabs(p[2]);
		if (x >= 0 && y >= 0 && z >=0)
			return (1);
	}
	return (0);
}

int		ft_cy_obstruction(double t, double *v, double *o, t_cylinder *cy)
{
	double	a;
	double	b;

	a = ft_infinit_cy(v, o, cy);
	b = ft_caps_obst(v, o, cy);
	if (a < t || b < t)
		return (1);
	return (0);
}

int		ft_tr_obstruction(double t, double *v, double *o, t_triangle *tr)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = t;
	if (ft_tr_to_pl_obst(v, o, &t0, tr))
	{
		ft_magxvec(v, t0, p);
		ft_sum_vector(o, p, p);
		x = ft_angle(tr->xyz, &(tr->xyz[3]), &(tr->xyz[6]));
		y = ft_angle(tr->xyz, &(tr->xyz[6]), &(tr->xyz[3]));
		if (ft_cmpangles(x, y, p, tr))
			return (1);
	}
	return (0);
}
