/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t0t1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:57:40 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/11 21:44:21 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_magxvec(double *vec, double mag, double *p)
{
	int	i;
	i = -1;
	while (++i < 3)
		p[i] = vec[i] * mag;
}

void	ft_sum_vector(double *center, double *vec, double *p)
{
	int i;

	i = -1;
	while (++i < 3)
		p[i] = center[i] + vec[i];
}

void	ft_dif_vector(double *center, double *o, double *l)
{
	int i;

	i = -1;
	while (++i < 3)
		l[i] = center[i] - o[i];
}

double	ft_dot_product(double *a, double *b)
{
	double	dot;
	int		i;

	i = -1;
	dot = 0;
	while (++i < 3)
		dot += a[i] * b[i];
	return (dot);
}

double	ft_t0t1(double t0, double t1)
{
	if (t0 < 0)
	{
		if (t1 < 0)
			return (0);
	}
	else if (t1 < 0)
		return (t0);
	else if (t1 > t0)
		return (t0);
	return (t1);
}
