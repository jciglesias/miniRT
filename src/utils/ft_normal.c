/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:00:28 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/20 16:02:11 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_magnitude(double *p)
{
	double x;
	double y;
	double z;

	x = p[0] * p[0];
	y = p[1] * p[1];
	z = p[2] * p[2];
	return (ft_sqrt(x + y + z));
}

void	ft_normal(double *p)
{
	double	mag;

	mag =  ft_magnitude(p);
	p[0] /= mag;
	p[1] /= mag;
	p[2] /= mag;
}

double ft_degtorad(double deg)
{
	double	rad;

	rad = 3.141593 / 180;
	rad *= deg;
	return (rad);
}
