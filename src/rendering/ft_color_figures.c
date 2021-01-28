/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:48:15 by jiglesia          #+#    #+#             */
/*   Updated: 2021/01/13 00:26:57 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_color_sp(t_pix *pix)
{
	t_sphere	*spx;

	spx = S.SP;
	while (spx)
	{
		ft_colorsphere(pix, spx);
		spx = spx->next;
	}
}

void	ft_color_pl(t_pix *pix)
{
	t_plane	*plx;

	plx = S.PL;
	while (plx)
	{
		ft_colorplane(pix, plx);
		plx = plx->next;
	}
}

void	ft_color_sq(t_pix *pix)
{
	t_square	*sqx;

	sqx = S.SQ;
	while (sqx)
	{
		ft_colorsquare(pix, sqx);
		sqx = sqx->next;
	}
}

void	ft_color_cy(t_pix *pix)
{
	t_cylinder	*cyx;

	cyx = S.CY;
	while (cyx)
	{
		ft_colorcylinder(pix, cyx);
		cyx = cyx->next;
	}
}

void	ft_color_tr(t_pix *pix)
{
	t_triangle	*trx;

	trx = S.TR;
	while (trx)
	{
		ft_colortriangle(pix, trx);
		trx = trx->next;
	}
}
