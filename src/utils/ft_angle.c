/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:28:10 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/26 13:43:33 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_cmpangles(double x, double y, double *p, t_triangle *tr)
{
	if (x >= ft_angle(tr->xyz, &(tr->xyz[3]), p))
		if (x >= ft_angle(p, &(tr->xyz[3]), &(tr->xyz[6])))
			if (y >= ft_angle(p, &(tr->xyz[6]), &(tr->xyz[3])))
				if (y >= ft_angle(tr->xyz, &(tr->xyz[6]), p))
					return (1);
	return (0);
}

double	ft_angle(double *a, double *b, double *c)
{
	double	l[3];
	double	va[3];
	double	tca;
	double	rad;

	ft_dif_vector(c, b, l);
	ft_dif_vector(a, b, va);
	ft_normal(va);
	tca = ft_dot_product(l, va);
	rad = acos(tca / ft_magnitude(l));
	return (rad);
}

void	ft_move_x(double x, double *p)
{
	double	px[3];

	px[0] = p[0];
	px[1] = p[1] * cos(x) - p[2] * sin(x);
	px[2] = p[1] * sin(x) + p[2] * cos(x);
	p[0] = px[0];
	p[1] = px[1];
	p[2] = px[2];
}

void	ft_move_y(double y, double *p)
{
	double	px[3];

	px[0] = p[0] * cos(y) + p[2] * sin(y);
	px[1] = p[1];
	px[2] = p[0] * (-sin(y)) + p[2] * cos(y);
	p[0] = px[0];
	p[1] = px[1];
	p[2] = px[2];
}

void	ft_move_z(double z, double *p)
{
	double	px[3];

	px[0] = p[0] * cos(z) - p[1] * sin(z);
	px[1] = p[0] * sin(z) + p[1] * cos(z);
	px[2] = p[2];
	p[0] = px[0];
	p[1] = px[1];
	p[2] = px[2];
}
