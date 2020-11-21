/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:24:14 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/20 17:16:52 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_primray(double y, double x, t_cam *c, double *p)
{
	double	ratio;
	double	scale;

	scale = tan(ft_degtorad(c->fov * 0.5));
	ratio = (double)S.res[0] / (double)S.res[1];
	p[0] = (2 * (x + 0.5) / (double)S.res[0] - 1) * ratio * scale;
	p[1] = (1 - 2 * ((y + 0.5) / (double)S.res[1]) * scale);
	p[2] = -1;
	ft_camera_to_world(p, c);
	ft_normal(p);
}

int		ft_gtpxl(double *vec, double *o)
{
	int		color;
	int		temp;
	double	t;
	double	t0;

	color = 0;
	t = 4000.;
	color = ft_color_sp(vec, o, &t);
	t0 = t;
	temp = ft_color_pl(vec, o, &t);
	if (t < t0)
		color = temp;
	t0 = t;
	temp = ft_color_sq(vec, o, &t);
	if (t < t0)
		color = temp;
	t0 = t;
/*	temp = ft_color_cy(vec, o, &t);
	if (t < t0)
		color = temp;
		t0 = t;*/
	temp = ft_color_tr(vec, o, &t);
	if (t < t0)
		color = temp;
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
		{
			ft_primray((double)i, (double)j, c, p);
			bmp[i][j] = ft_gtpxl(p , c->xyz);
		}
		i++;
	}
}

void	ft_load_scene(void)
{
	t_cam	*c;
	int		mpos;
	int		count;

	mpos = 13;
	mlx_string_put(S.mlx, S.win, 5, mpos, 0xFFFFFF, "Loading Scene...");
	mpos += 13;
	mlx_string_put(S.mlx, S.win, 5, mpos, 0xFFFFFF, "Number of Cameras:");
	mlx_string_put(S.mlx, S.win, 119, mpos, 0x88FFFF, ft_itoa(S.c));
	c = S.cam;
	count = 0;
	while (c)
	{
		mpos += 13;
		count++;
		mlx_string_put(S.mlx, S.win, 5, mpos, 0xFFFFFF, "Loading Cam");
		mlx_string_put(S.mlx, S.win, 80, mpos, 0x88FF88, ft_itoa(count));
		c->bmp = ft_mallotrix(c->bmp);
		ft_fill_bmp(c, c->bmp);
		c = c->next;
	}
	ft_plotrt();
}
