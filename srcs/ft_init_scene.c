/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:26:35 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/29 00:29:58 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_init_int(int *a, int *b, int *c, int *d)
{
	(*a) = 0;
	(*b) = 0;
	(*c) = 0;
	(*d) = 0;
}

void	ft_init_double(double *a, double *b, double *c, double *d)
{
	(*a) = 0.;
	(*b) = 0.;
	(*c) = 0.;
	(*d) = 0.;
}

void	ft_init_scene(t_scene scene)
{
	ft_init_int(&scene.res, &scene.x, &scene.y, &scene.amb);
	ft_init_int(&scene.r, &scene.g, &scene.b, &scene.cam);
	ft_init_int(&scene.fov, &scene.light, &scene.lr, &scene.lg);
	ft_init_int(&scene.lb, &scene.sphere, &scene.spr, &scene.spg);
	ft_init_int(&scene.spb, &scene.plane, &scene.plr, &scene.plg);
	ft_init_int(&scene.plb, &scene.square, &scene.sqr, &scene.sqg);
	ft_init_int(&scene.sqb, &scene.cy, &scene.cyr, &scene.cyg);
	ft_init_int(&scene.cyb, &scene.tr, &scene.trr, &scene.trg);
	ft_init_double(&scene.lrr, &scene.vpx, &scene.vpy, &scene.vpz);
	ft_init_double(&scene.nox, &scene.noy, &scene.noz, &scene.lpx);
	ft_init_double(&scene.lpy, &scene.lpz, &scene.brr, &scene.spx);
	ft_init_double(&scene.spy, &scene.spz, &scene.spd, &scene.plx);
	ft_init_double(&scene.ply, &scene.plz, &scene.nopx, &scene.nopy);
	ft_init_double(&scene.nopz, &scene.sqx, &scene.sqy, &scene.sqz);
	ft_init_double(&scene.nosx, &scene.nosy, &scene.nosz, &scene.sqs);
	ft_init_double(&scene.cyx, &scene.cyy, &scene.cyz, &scene.nocx);
	ft_init_double(&scene.nocy, &scene.nocz, &scene.cyd, &scene.cyh);
	ft_init_double(&scene.trx1, &scene.try1, &scene.trz1, &scene.trx3);
	ft_init_double(&scene.trx2, &scene.try2, &scene.trz2, &scene.try3);
	scene.trb = 0;
	scene.trz3 = 0.;
}
