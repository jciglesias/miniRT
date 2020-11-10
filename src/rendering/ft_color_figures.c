/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:48:15 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 13:30:54 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_color_sp(double *vec, double *o, double *t)
{
	int			color;
	t_sphere	*spx;

	spx = S.SP;
	color = 0;
	while (spx)
	{
		if (ft_colorsphere(vec, o, t, spx))
			color = ft_colorsphere(vec, o, t, spx);
		spx = spx->next;
	}
	return (color);
}

int	ft_color_pl(double *vec, double *o, double *t)
{
	(void)vec;
	(void)o;
	(void)t;
	return (0);
}

int	ft_color_sq(double *vec, double *o, double *t)
{
	(void)vec;
	(void)o;
	(void)t;
	return (0);
}

int	ft_color_cy(double *vec, double *o, double *t)
{
	(void)vec;
	(void)o;
	(void)t;
	return (0);
}

int	ft_color_tr(double *vec, double *o, double *t)
{
	(void)vec;
	(void)o;
	(void)t;
	return (0);
}
