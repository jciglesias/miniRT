/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:48:15 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/20 17:57:23 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_color_sp(double *vec, double *o, double *t)
{
	int			color;
	int			temp;
	t_sphere	*spx;

	spx = S.SP;
	color = 0;
	while (spx)
	{
		if ((temp = ft_colorsphere(vec, o, t, spx)))
			color = temp;
		spx = spx->next;
	}
	return (color);
}

int	ft_color_pl(double *vec, double *o, double *t)
{
	int		color;
	int		temp;
	t_plane	*plx;

	plx = S.PL;
	color = 0;
	while (plx)
	{
		if ((temp = ft_colorplane(vec, o, t, plx)))
			color = temp;
		plx = plx->next;
	}
	return (color);
}

int	ft_color_sq(double *vec, double *o, double *t)
{
	int			color;
	int			temp;
	t_square	*sqx;

	sqx = S.SQ;
	color = 0;
	while (sqx)
	{
		if ((temp = ft_colorsquare(vec, o, t, sqx)))
			color = temp;
		sqx = sqx->next;
	}
	return (color);
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
	int			color;
	int			temp;
	t_triangle	*trx;

	trx = S.TR;
	color = 0;
	while (trx)
	{
		if ((temp = ft_colortriangle(vec, o, t, trx)))
			color = temp;
		trx = trx->next;
	}
	return (color);
}
