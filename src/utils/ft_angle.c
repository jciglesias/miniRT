/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:28:10 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/21 18:36:14 by jiglesia         ###   ########.fr       */
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
