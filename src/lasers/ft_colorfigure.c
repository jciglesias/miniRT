/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorfigure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:29:06 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/29 02:07:59 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_colorsphere(t_pix *pix, t_sphere *sp)
{
	double l[3];
	double tca;
	double d2;
	double thc;
	double t0;

	ft_dif_vector(sp->xyz, pix->o, l);
	tca = ft_dot_product(l, pix->vec);
	if (tca < 0)
		return ;
	d2 = ft_dot_product(l, l) - tca * tca;
	if (d2 > (sp->d * sp->d / 4))
		return ;
	thc = ft_sqrt((sp->d * sp->d / 4) - d2);
	t0 = ft_t0t1(tca - thc, tca + thc);
	if (t0 && pix->t > t0)
	{
		pix->t = t0;
		pix->fig = 1;
		pix->sp = sp;
		ft_sphere_normal(sp->xyz, pix->o, pix->vec, t0);
		ft_cpyrgb(sp->rgb, pix->color);
	}
}

void	ft_colorplane(t_pix *pix, t_plane *pl)
{
	double l[3];
	double denom;
	double t0;
	double n[3];

	t0 = 4000.;
	denom = ft_dot_product(pl->vec, pix->vec);
	ft_veccpy(pl->vec, n);
	if (denom < 0)
	{
		denom *= -1;
		n[0] *= -1;
		n[1] *= -1;
		n[2] *= -1;
	}
	ft_dif_vector(pl->xyz, pix->o, l);
	t0 = ft_dot_product(l, n) / denom;
	l[0] = pix->o[0] + pix->vec[0] * t0;
	l[1] = pix->o[1] + pix->vec[1] * t0;
	l[2] = pix->o[2] + pix->vec[2] * t0;
	ft_normal(l);
	ft_dif_vector(l, pl->xyz, l);
	if (t0 && pix->t > t0 && ft_dot_product(l, n) < 0.1)
	{
		pix->t = t0;
		pix->fig = 2;
		pix->pl = pl;
		ft_normal_plane(pl->vec, pix);
		ft_cpyrgb(pl->rgb, pix->color);
	}
}

void	ft_colorsquare(t_pix *pix, t_square *sq)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;
	double	z;

	t0 = pix->t;
	if (ft_sq_to_pl(pix->vec, pix->o, &t0, sq))
	{
		ft_magxvec(pix->vec, t0, p);
		ft_sum_vector(pix->o, p, p);
		ft_dif_vector(p, sq->xyz, p);
		x = ft_maxx(sq->vec, sq->side * 3 / 4) - fabs(p[0]);
		y = ft_maxy(sq->vec, sq->side * 3 / 4) - fabs(p[1]);
		z = ft_maxz(sq->vec, sq->side * 3 / 4) - fabs(p[2]);
		if (x >= 0 && y >= 0 && z >=0)
		{
			pix->t = t0;
			pix->fig = 3;
			pix->sq = sq;
			ft_normal_plane(sq->vec, pix);
			ft_cpyrgb(sq->rgb, pix->color);
		}
	}
}

void	ft_colortriangle(t_pix *pix, t_triangle *tr)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = pix->t;
	if (ft_tr_to_pl(pix->vec, pix->o, &t0, tr))
	{
		ft_magxvec(pix->vec, t0, p);
		ft_sum_vector(pix->o, p, p);
		x = ft_angle(tr->xyz, &(tr->xyz[3]), &(tr->xyz[6]));
		y = ft_angle(tr->xyz, &(tr->xyz[6]), &(tr->xyz[3]));
		if (ft_cmpangles(x, y, p, tr))
		{
			pix->t = t0;
			pix->fig = 5;
			pix->tr = tr;
			ft_trnormal(tr->xyz, &(tr->xyz[3]), &(tr->xyz[6]));
			ft_normal_plane(S.normal, pix);
			ft_cpyrgb(tr->rgb, pix->color);
		}
	}
}

void	ft_colorcylinder(t_pix *pix, t_cylinder *cy)
{
	double	a;
	double	b;

	a = ft_infinit_cy(pix->vec, pix->o, cy);
	b = ft_caps(pix->vec, pix->o, cy);
	if (a < pix->t || b < pix->t)
	{
		if (b < a)
		{
			pix->t = b;
			pix->fig = 4;
			pix->cy = cy;
			ft_normal_plane(cy->vec, pix);
			ft_cpyrgb(cy->rgb, pix->color);
			return ;
		}
		pix->t = a;
		pix->fig = 4;
		pix->cy = cy;
		ft_cy_normal(pix, cy);
		ft_cpyrgb(cy->rgb, pix->color);
	}
}
