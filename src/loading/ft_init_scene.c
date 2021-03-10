/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:51:34 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/06 21:53:01 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_pix(void)
{
	S.pix.t = 4000;
	S.pix.sp = NULL;
	S.pix.pl = NULL;
	S.pix.sq = NULL;
	S.pix.cy = NULL;
	S.pix.tr = NULL;
	S.pix.fig = 0;
}

void	ft_init_int(int i, int *a)
{
	while (i)
		a[--i] = 0;
}

void	ft_init_double(int i, double *a)
{
	while (i)
		a[--i] = 0.;
}

void	ft_init_scene(void)
{
	S.r = 0;
	ft_init_int(2, S.res);
	S.a = 0;
	S.al = 0.;
	ft_init_int(3, S.rgb);
	S.c = 0;
	S.cam = NULL;
	S.action_cam = NULL;
	S.l = 0;
	S.light = NULL;
	S.sp = 0;
	S.sphere = NULL;
	S.pl = 0;
	S.plane = NULL;
	S.sq = 0;
	S.square = NULL;
	S.cy = 0;
	S.cylinder = NULL;
	S.tr = 0;
	S.triangle = NULL;
	S.lendian = 0;
	S.mlx = NULL;
	S.win = NULL;
	ft_init_double(3, S.normal);
	ft_init_pix();
}
