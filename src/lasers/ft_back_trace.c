/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_trace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:08:01 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 16:04:39 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

	t = ft_distance(p, o) - 0.00001;
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

	p[0] = pix->o[0] + pix->vec[0] * pix->t;
	p[1] = pix->o[1] + pix->vec[1] * pix->t;
	p[2] = pix->o[2] + pix->vec[2] * pix->t;
	ft_dif_vector(p, l->xyz, v);
	ft_normal(v);
	if (ft_check_obstacle(p, v, l->xyz))
	{
		if (S.shadow)
			return (-1);
		else
		{
			S.shadow = 1;
			return (0);
		}
	}
	ft_adjust_color(pix, l->rgb);
	return (ft_calculate_nv(v));
}

void	ft_lights(double *nv, t_pix *pix)
{
	t_light	*lts;
	double	temp;

	lts = S.light;
	S.shadow = 0;
	while (lts)
	{
		temp = ft_trace_light(pix, lts);
		if (temp > *nv || temp == 0)
		{
			if (temp > *nv && !S.shadow)
				*nv = temp;
			else if (temp == 0)
				*nv *= 0.7;
			else
				*nv *= 1.7;
		}
		lts = lts->next;
	}
}

void	ft_back_trace(t_pix *pix)
{
	double nv;

	nv = ft_calculate_nv(pix->vec) * S.al;
	ft_adjust_color(pix, S.rgb);
	if (nv < 0)
		nv = 0;
	ft_lights(&nv, pix);
	pix->color[0] *= nv;
	pix->color[1] *= nv;
	pix->color[2] *= nv;
}
