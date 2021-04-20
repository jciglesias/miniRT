/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:03:40 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 16:04:36 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_adjust_color(t_pix *pix, int *rgb)
{
	double r;
	double g;
	double b;

	r = rgb[0] / 255;
	g = rgb[1] / 255;
	b = rgb[2] / 255;
	pix->color[0] *= r;
	pix->color[1] *= g;
	pix->color[2] *= b;
}
