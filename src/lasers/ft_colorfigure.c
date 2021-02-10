/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorfigure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:29:06 by jiglesia          #+#    #+#             */
/*   Updated: 2021/02/09 17:44:19 by jiglesia         ###   ########.fr       */
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
		ft_sphere_normal(sp->xyz, pix->o, pix->vec, t0);
		ft_cpyrgb(sp->rgb, pix->color);
	}
}

void	ft_normal_plane(double *v, t_pix *pix)
{
	double temp[3];
	double nv;

	temp[0] = -pix->vec[0];
	temp[1] = -pix->vec[1];
	temp[2] = -pix->vec[2];
	nv = ft_dot_product(v, temp);
	if (nv < 0)
	{
		S.normal[0] = -v[0];
		S.normal[1] = -v[1];
		S.normal[2] = -v[2];
	}
	else
		ft_veccpy(v, S.normal);
}

void	ft_colorplane(t_pix *pix, t_plane *pl)
{
	double l[3];
	double denom;
	double t0;

	t0 = 4000.;
	denom = ft_dot_product(pl->vec, pix->vec);
	if (denom > (1 / 1000000))
	{
		ft_dif_vector(pl->xyz, pix->o, l);
		t0 = ft_dot_product(l, pl->vec) / denom;
	}
	if (t0 && pix->t > t0)
	{
		pix->t = t0;
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

	t0 = pix->t;
	if (ft_sq_to_pl(pix->vec, pix->o, &t0, sq))
	{
		ft_magxvec(pix->vec, t0, p);
		ft_sum_vector(pix->o, p, p);
		ft_dif_vector(p, sq->xyz, p);
		x = ft_maxx(sq->vec, sq->side * 3 / 4) - fabs(p[0]);
		y = ft_maxy(sq->vec, sq->side * 3 / 4) - fabs(p[1]);
		if (x >= 0 && y >= 0)
		{
			pix->t = t0;
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
			ft_normal_plane(cy->vec, pix);
			ft_cpyrgb(cy->rgb, pix->color);
			return ;
		}
		pix->t = a;
		ft_cy_normal(pix, cy);
		ft_cpyrgb(cy->rgb, pix->color);
	}
}
