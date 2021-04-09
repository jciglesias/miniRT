/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl_obst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:10:15 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/09 14:50:22 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_sq_to_pl_obst(double *v, double *o, double *t, t_square *pl)
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
	if (t0 && *t > t0 && t0 >= 0)
	{
		*t = t0;
		return (1);
	}
	else
		return (0);
}

double	ft_cy_to_pl_obst(double *vec, double *o, double *c, double *n)
{
	double l[3];
	double denom;
	double t0;

	denom = ft_dot_product(n, vec);
	t0 = 4000;
	if (denom > (1 / 1000000))
	{
		ft_dif_vector(c, o, l);
		t0 = ft_dot_product(l, n) / denom;
	}
	return (t0);
}

double	ft_caps_obst(double *vec, double *o, t_cylinder *cy)
{
	double d1;
	double d2;
	double p1[3];
	double p2[3];
	double c[3];

	ft_magxvec(cy->vec, cy->h, c);
	ft_sum_vector(cy->xyz, c, c);
	d1 = ft_cy_to_pl_obst(vec, o, cy->xyz, cy->vec);
	d2 = ft_cy_to_pl_obst(vec, o, c, cy->vec);
	if (d1 < 4000 || d2 < 4000)
	{
		ft_magxvec(vec, d1, p1);
		ft_sum_vector(o, p1, p1);
		ft_magxvec(vec, d2, p2);
		ft_sum_vector(o, p2, p2);
		if ((d1 < 4000 && ft_distance(p1, cy->xyz) <= (cy->d / 2))
			&& (d2 < 4000 && ft_distance(p2, c) <= (cy->d / 2)))
			return (d1 < d2 ? d1 : d2);
		else if (d1 < 4000 && ft_distance(p1, cy->xyz) <= (cy->d / 2))
			return (d1);
		else if (d2 < 4000 && ft_distance(p2, c) <= (cy->d / 2))
			return (d2);
	}
	return (4000);
}

int		ft_tr_to_pl_obst(double *vec, double *o, double *t, t_triangle *tr)
{
	double l[3];
	double denom;
	double t0;
	double normal[3];
	double a[3];

	ft_dif_vector(tr->xyz, &(tr->xyz[3]), a);
	ft_dif_vector(tr->xyz, &(tr->xyz[6]), l);
	ft_crossp(a, l, normal);
	ft_normal(normal);
	denom = ft_dot_product(normal, vec);
	t0 = 0;
	if (denom)
	{
		ft_dif_vector(tr->xyz, o, l);
		t0 = ft_dot_product(l, normal) / denom;
	}
	if (t0 && *t > t0 && t0 >= 0)
	{
		*t = t0;
		return (1);
	}
	return (0);
}
