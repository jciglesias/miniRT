/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:57:59 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/28 23:26:08 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINIRT_H
# define	MINIRT_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_scene
{
	int		res;
	int		x;
	int		y;
	int		amb;
	double	lrr;
	int		r;
	int		g;
	int		b;
	int		cam;
	double	vpx;
	double	vpy;
	double	vpz;
	double	nox;
	double	noy;
	double	noz;
	int		fov;
	int		light;
	double	lpx;
	double	lpy;
	double	lpz;
	double	brr;
	int		lr;
	int		lg;
	int		lb;
	int		sphere;
	double	spx;
	double	spy;
	double	spz;
	double	spd;
	int		spr;
	int		spg;
	int		spb;
	int		plane;
	double	plx;
	double	ply;
	double	plz;
	double	nopx;
	double	nopy;
	double	nopz;
	int		plr;
	int		plg;
	int		plb;
	int		square;
	double	sqx;
	double	sqy;
	double	sqz;
	double	nosx;
	double	nosy;
	double	nosz;
	double	sqs;
	int		sqr;
	int		sqg;
	int		sqb;
	int		cy;
	double	cyx;
	double	cyy;
	double	cyz;
	double	nocx;
	double	nocy;
	double	nocz;
	double	cyd;
	double	cyh;
	int		cyr;
	int		cyg;
	int		cyb;
	int		tr;
	double	trx1;
	double	try1;
	double	trz1;
	double	trx2;
	double	try2;
	double	trz2;
	double	trx3;
	double	try3;
	double	trz3;
	int		trr;
	int		trg;
	int		trb;
}			t_scene;

void		ft_init_scene(t_scene scene);
#endif
