/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:24:14 by jiglesia          #+#    #+#             */
/*   Updated: 2021/01/28 14:20:57 by jiglesia         ###   ########.fr       */
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

int		ft_gtpxl(t_pix pix)
{
	ft_init_int(3, pix.color);
	pix.t = 4000.;
	ft_color_sp(&pix);
	ft_color_pl(&pix);
	ft_color_sq(&pix);
	ft_color_cy(&pix);
	ft_color_tr(&pix);
	ft_back_trace(&pix);
	return (ft_rgb(pix.color[0], pix.color[1], pix.color[2]));
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
			ft_veccpy(p, S.pix.vec);
			ft_veccpy(c->xyz, S.pix.o);
			bmp[i][j] = ft_gtpxl(S.pix);
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
