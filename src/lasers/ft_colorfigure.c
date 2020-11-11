/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorfigure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:29:06 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/11 13:18:22 by jiglesia         ###   ########.fr       */
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
