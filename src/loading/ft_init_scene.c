/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:26:35 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 12:26:33 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	scene.r = 0;
	ft_init_int(2, scene.res);
	scene.a = 0;
	scene.al = 0.;
	ft_init_int(3, scene.rgb);
	scene.c = 0;
	scene.cam = NULL;
	scene.action_cam = NULL;
	scene.l = 0;
	scene.light = NULL;
	scene.sp = 0;
	scene.sphere = NULL;
	scene.pl = 0;
	scene.plane = NULL;
	scene.sq = 0;
	scene.square = NULL;
	scene.cy = 0;
	scene.cylinder = NULL;
	scene.tr = 0;
	scene.triangle = NULL;
	scene.lendian = 0;
	scene.mlx = NULL;
	scene.win = NULL;
}
