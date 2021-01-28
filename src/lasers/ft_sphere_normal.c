/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by jiglesia          #+#    #+#             */
/*   Updated: 2021/01/09 15:01:50 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_sphere_normal(double *c, double *o, double *vec, double t)
{
	double	p[3];

	p[0] = o[0] + vec[0] * t;
	p[1] = o[1] + vec[1] * t;
	p[2] = o[2] + vec[2] * t;
	ft_dif_vector(p, c, S.normal);
	ft_normal(S.normal);
}
