/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by jiglesia          #+#    #+#             */
/*   Updated: 2021/02/13 14:48:00 by jiglesia         ###   ########.fr       */
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

void	ft_normal_plane(double *v, t_pix *pix)
{
	double temp[3];
	double nv;

	temp[0] = -pix->vec[0];
	temp[1] = -pix->vec[1];
	temp[2] = -pix->vec[2];
	nv = ft_dot_product(v, temp);
	if (nv < 0)
	{
		S.normal[0] = -v[0];
		S.normal[1] = -v[1];
		S.normal[2] = -v[2];
	}
	else
		ft_veccpy(v, S.normal);
}
