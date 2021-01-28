/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:08:01 by jiglesia          #+#    #+#             */
/*   Updated: 2021/01/28 20:07:18 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_back_trace(t_pix *pix)
{
	double v[3];
	double nv;

	v[0] = -pix->vec[0];
	v[1] = -pix->vec[1];
	v[2] = -pix->vec[2];
	nv = ft_dot_product(S.normal, v);
	if (nv < 0)
		nv *= -1;
	pix->color[0] *= nv;
	pix->color[1] *= nv;
	pix->color[2] *= nv;
}
