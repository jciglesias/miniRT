/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_cy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:27:39 by jiglesia          #+#    #+#             */
/*   Updated: 2020/12/12 01:32:20 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_cylinder(double *o, double *vec, t_cylinder *cy, double *t)
{
	double v[3];
	double u[3];
	double a;
	double b;
	double c;

	ft_dif_vector(o, cy->xyz, u);
	ft_magxvec(cy->vec, ft_dot_product(u, cy->vec),  u);
	ft_dif_vector(o, cy->xyz, v);
	ft_dif_vector(v, u, u);
	ft_magxvec(cy->vec, ft_dot_product(vec, cy->vec), v);
	ft_dif_vector(vec, v, v);
	a = ft_dot_product(v, v);
	b = 2 * ft_dot_product(v, u);
	c = ft_dot_product(u, u) - pow(cy->d / 2, 2);
	t[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	t[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (t[0] <= 0 && t[1] <= 0)
	{
		t[0] = 4000;
		t[1] = 4000;
		return (0);
	}
	return (1);
}

double	ft_infinit_cy(double *vec, double *o, t_cylinder *cy)
{
	double	t[2];
	double	d1;
	double	d2;
	double	dif1[3];
	double	dif2[3];

	if (!(check_cylinder(o, vec, cy, t)))
		return(4000);
	ft_dif_vector(cy->xyz, o, dif1);
	ft_magxvec(vec, t[0], dif2);
	ft_dif_vector(dif2, dif1, dif2);
	d1 = ft_dot_product(cy->vec, dif2);
	ft_magxvec(vec, t[1], dif2);
	ft_dif_vector(dif2, dif1, dif2);
	d2 = ft_dot_product(cy->vec, dif2);
	if (!((d1 >= 0 && d1 <= cy->h && t[0] > 0) || (d2 >= 0 && d2 <= cy->h
												&& t[0] > 0)))
		return (4000);
	return (ft_t0t1(t[0], t[1]));
}

double	ft_distance(double *a, double *b)
{
	double c[3];

	ft_dif_vector(b, a, c);
	return (sqrt(ft_dot_product(c, c)));
}

double	ft_caps(double *vec, double *o, t_cylinder *cy)
{
	double d1;
	double d2;
	double p1[3];
	double p2[3];
	double c[3];

	ft_magxvec(cy->vec, cy->h, c);
	ft_sum_vector(cy->xyz, c,c);
	d1 = ft_cy_to_pl(vec, o, cy->xyz, cy->vec);
	d2 = ft_cy_to_pl(vec, o, c, cy->vec);
	if (d1 < 4000 || d2 < 4000)
	{
		ft_magxvec( vec, d1, p1);
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
		return (4000);
	}
	return (4000);
}
