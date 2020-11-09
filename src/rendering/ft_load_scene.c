/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:52:25 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/09 15:32:24 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	*ft_primray(double y, double x, t_cam *c, double *p)
{
	double	ratio;
	double	scale;

	scale = ft_tan(ft_degtorad(c->fov * 0.5));
	ratio = (double)S.res[0] / (double)S.res[1];
	p[0] = (2 * ((x + 0.5) / (double)S.res[0] - 1) * ratio * scale);
	p[1] = (1 - 2 * ((y + 0.5) / (double)S.res[1] - 1) * scale);
	p[2] = -1;
	ft_camera_to_world(p, c);
	ft_normal(p);
	return (p);
}

int		ft_gtpxl(double *vec, double *o)
{
	int		color;
	double	t;

	color = 0;
	t = 4000.;
	color = ft_color_sp(vec, o, &t);
	color = ft_color_pl(vec, o, &t);
	color = ft_color_sq(vec, o, &t);
	color = ft_color_cy(vec, o, &t);
	color = ft_color_tr(vec, o, &t);
	return (color);
}

void	ft_fill_bmp(t_cam *c, int **bmp)
{
	int		i;
	int		j;
	double	p[3];

	i = 0;
	while (i < S.res[1])
	{
		j = -1;
		while (++j < S.res[0])
			bmp[i][j] = ft_gtpxl(ft_primray((double)i, (double)j, c, p), c->xyz);
		i++;
	}
}

void	ft_load_scene(void)
{
	t_cam	*c;

	c = S.cam;
	while (c)
	{
		c->bmp = ft_mallotrix(c->bmp);
		ft_fill_bmp(c, c->bmp);
		c = c->next;
	}
}
