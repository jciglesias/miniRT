/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sq_to_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:33:08 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/11 23:45:58 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_sq_to_pl(double *vec, double *o, double *t, t_square *pl)
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
		return (1);
	}
	return (0);
}
