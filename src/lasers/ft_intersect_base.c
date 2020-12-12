/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:14:42 by jiglesia          #+#    #+#             */
/*   Updated: 2020/12/06 16:47:06 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_intersect_base(double *vec, double *o, t_cylinder *cy, double *t)
{
	double	p0[3];
	double	p[3];
	double	b;
	double	t0;

	ft_dif_vector(o, cy->xyz, p0);
	b = -1;
	if (vec[1] == 0)
		return (0);
	t0 = p0[1] / (b * vec[1]);
	if (t0 < 0.00000001)
		return (0);
	p[0] = p0[0] + t0 * vec[0];
	p[1] = p0[1] + t0 * vec[1];
	p[2] = p0[2] + t0 * vec[2];
	if ((pow(p[0], 2) + pow(p[2], 2) - pow(cy->d / 2, 2)) > 0.00000001)
		return (0);
	*t = t0;
	return (1);
}

double	ft_intersect_base2(double *vec, double *o, t_cylinder *cy, double *t)
{
	double	p0[3];
	double	p[3];
	double	b;
	double	t0;

	p[0] = cy->xyz[0];
	p[1] = cy->xyz[1] + cy->h;
	p[2] = cy->xyz[2];
	ft_dif_vector(o, p, p0);
	b = 1;
	if (vec[1] == 0)
		return (0);
	t0 = (-1) * p0[1] / (b * vec[1]);
	if (t0 < 0.00000001)
		return (0);
	p[0] = p0[0] + t0 * vec[0];
	p[1] = p0[1] + t0 * vec[1];
	p[2] = p0[2] + t0 * vec[2];
	if ((pow(p[0], 2) + pow(p[2], 2) - pow(cy->d / 2, 2)) > 0.00000001)
		return (0);
	*t = t0;
	return (1);
}

void	ft_veccpy(double *p, double *p0)
{
	int i;

	i = -1;
	while (++i < 3)
		p0[i] = p[i];
}

void	ft_move_o(double y, double x, double *xyz, double *o)
{
	double t;
	double vec[3];

	//t = ft_dot_product(xyz, o);
	ft_dif_vector(o, xyz, vec);
	t = ft_magnitude(vec);
	ft_move_x(x, vec);
	ft_move_y(y, vec);
	//ft_veccpy(vec, o);
	ft_normal(vec);
	o[0] = xyz[0] + vec[0] * t;
	o[1] = xyz[1] + vec[1] * t;
	o[2] = xyz[2] + vec[2] * t;
}

void	ft_movecy(double *ray, t_cylinder *cy, double *vec, double *o)
{
	double hipo;
	double rady;
	double radx;
	double n0[3];
	//(void)n;

	ft_veccpy(ray, vec);
	if (cy->vec[1] != 1)
	{
		//n gira en z y x pero vec gira en x y y
		ft_veccpy(cy->vec, n0);
		hipo = ft_hipo(n0[2], n0[1]);
		radx = 0;
		if (hipo)
			radx = acos(fabs(n0[2]) / hipo);
		radx = ft_quadrant((-1) * n0[2], n0[1], radx) - 3.141593 / 2;
		hipo = ft_hipo(n0[0], n0[2]);
		rady = 0;
		if (hipo)
			rady = acos(fabs(n0[0]) / hipo);
		if (rady || n0[2] == 1)
			rady = ft_quadrant(n0[0], (-1) * n0[2], rady) - 3.141593 / 2;
		ft_move_x(-radx, vec);
		ft_move_y(-rady, vec);
		ft_normal(vec);
		//move o
		ft_move_o(rady, radx, cy->xyz, o);
	}
}
