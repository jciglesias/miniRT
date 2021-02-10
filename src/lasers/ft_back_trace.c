/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:08:01 by jiglesia          #+#    #+#             */
/*   Updated: 2021/02/10 14:13:43 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_sp_obstruction(double t, double *v, double *o, t_sphere *sp)
{
	double l[3];
	double tca;
	double d2;
	double thc;
	double t0;

	ft_dif_vector(sp->xyz, o, l);
	tca = ft_dot_product(l, v);
	if (tca < 0)
		return (0);
	d2 = ft_dot_product(l, l) - tca * tca;
	if (d2 > (sp->d * sp->d / 4))
		return (0);
	thc = ft_sqrt((sp->d * sp->d / 4) - d2);
	t0 = ft_t0t1(tca - thc, tca + thc);
	if (t < t0)
		return (0);
	else
		return (1);
}

int		ft_pl_obstruction(double t, double *v, double *o, t_plane *pl)
{
	double l[3];
	double denom;
	double t0;

	t0 = 4000.;
	denom = ft_dot_product(pl->vec, v);
	if (denom > (1 / 1000000))
	{
		ft_dif_vector(pl->xyz, o, l);
		t0 = ft_dot_product(l, pl->vec) / denom;
	}
	if (t0 && t > t0)
		return (1);
	else
		return (0);
}

int		ft_sq_obstruction(double t, double *v, double *o, t_square *sq)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = t;
	if (ft_sq_to_pl(v, o, &t0, sq))
	{
		ft_magxvec(v, t0, p);
		ft_sum_vector(o, p, p);
		ft_dif_vector(p, sq->xyz, p);
		x = ft_maxx(sq->vec, sq->side * 3 / 4) - fabs(p[0]);
		y = ft_maxy(sq->vec, sq->side * 3 / 4) - fabs(p[1]);
		if (x >= 0 && y >= 0)
			return (1);
	}
	return (0);
}

int		ft_cy_obstruction(double t, double *v, double *o, t_cylinder *cy)
{
	double	a;
	double	b;

	a = ft_infinit_cy(v, o, cy);
	b = ft_caps(v, o, cy);
	if (a < t || b < t)
		return (1);
	return (0);
}

int		ft_tr_obstruction(double t, double *v, double *o, t_triangle *tr)
{
	double	t0;
	double	p[3];
	double	x;
	double	y;

	t0 = t;
	if (ft_tr_to_pl(v, o, &t0, tr))
	{
		ft_magxvec(v, t0, p);
		ft_sum_vector(o, p, p);
		x = ft_angle(tr->xyz, &(tr->xyz[3]), &(tr->xyz[6]));
		y = ft_angle(tr->xyz, &(tr->xyz[6]), &(tr->xyz[3]));
		if (ft_cmpangles(x, y, p, tr))
			return (1);
	}
	return (0);
}

int		ft_ob_sp(double t, double *v, double *o)
{
	t_sphere *temp;

	temp = S.sphere;
	while (temp)
	{
		if (ft_sp_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_pl(double t, double *v, double *o)
{
	t_plane *temp;

	temp = S.plane;
	while (temp)
	{
		if (ft_pl_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_sq(double t, double *v, double *o)
{
	t_square *temp;

	temp = S.square;
	while (temp)
	{
		if (ft_sq_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_cy(double t, double *v, double *o)
{
	t_cylinder *temp;

	temp = S.cylinder;
	while (temp)
	{
		if (ft_cy_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_tr(double t, double *v, double *o)
{
	t_triangle *temp;

	temp = S.triangle;
	while (temp)
	{
		if (ft_tr_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

double	ft_calculate_nv(double *v)
{
	double temp[3];

	temp[0] = -v[0];
	temp[1] = -v[1];
	temp[2] = -v[2];
	return (ft_dot_product(S.normal, temp));
}

int		ft_check_obstacle(double *p, double *vec, double *o)
{
	double	t;

	t = ft_distance(p, o) - 0.001;
	if (ft_ob_sp(t, vec, o))
		return (1);
	if (ft_ob_pl(t, vec, o))
		return (1);
	if (ft_ob_sq(t, vec, o))
		return (1);
	if (ft_ob_cy(t, vec, o))
		return (1);
	if (ft_ob_tr(t, vec, o))
		return (1);
	return (0);
}

double	ft_trace_light(t_pix *pix, t_light *l)
{
	double p[3];
	double v[3];
	double r;
	double g;
	double b;

	p[0] = pix->o[0] + pix->vec[0] * pix->t;
	p[1] = pix->o[1] + pix->vec[1] * pix->t;
	p[2] = pix->o[2] + pix->vec[2] * pix->t;
	ft_dif_vector(p, l->xyz, v);
	ft_normal(v);
	if (ft_check_obstacle(p, v, l->xyz))
		return (0);
	r = l->rgb[0] / 255;
	g = l->rgb[1] / 255;
	b = l->rgb[2] / 255;
	pix->color[0] *= r;
	pix->color[1] *= g;
	pix->color[2] *= b;
	return (ft_calculate_nv(v));
}

void	ft_lights(double *nv, t_pix *pix)
{
	t_light	*lts;
	double	temp;

	lts = S.light;
	while (lts)
	{
		temp = ft_trace_light(pix, lts);
		if (temp > *nv)
			*nv = temp;
		lts = lts->next;
	}
}

void	ft_back_trace(t_pix *pix)
{
	double v[3];
	double nv;
	double r;
	double g;
	double b;

	v[0] = -pix->vec[0];
	v[1] = -pix->vec[1];
	v[2] = -pix->vec[2];
	nv = ft_dot_product(S.normal, v) * S.al;
	r = S.rgb[0] / 255;
	g = S.rgb[1] / 255;
	b = S.rgb[2] / 255;
	pix->color[0] *= r;
	pix->color[1] *= g;
	pix->color[2] *= b;
	if (nv < 0)
		nv = 0;
	ft_lights(&nv, pix);
	pix->color[0] *= nv;
	pix->color[1] *= nv;
	pix->color[2] *= nv;
}
