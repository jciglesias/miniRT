/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:24:11 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/10 00:45:19 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	int red;
	int green;
	int blue;

	red = r * 0x10000;
	green = g * 0x100;
	blue = b;
	return (red + green + blue);
}

void	ft_check_res(void)
{
	int x;
	int y;

	mlx_get_screen_size(S.mlx, &x, &y);
	if (S.res[0] > x)
		S.res[0] = x;
	if (S.res[1] > y - 60)
		S.res[1] = y - 60;
}

int		exit_win(void *p)
{
	(void)p;
	ft_free_scene();
	exit(0);
	return (1);
}

int		mouse_press(int button, int x, int y, void *p)
{
	(void)p;

	if (!S.click && button)
	{
		ft_primray((double)y, (double)x, S.action_cam, S.pix.vec);
		ft_veccpy(S.action_cam->xyz, S.pix.o);
		ft_gtpxl(&S.pix);
		if (S.pix.fig != 5)
			S.click = button;
		if (S.pix.fig == 1 && button == 3)
			S.click = 0;
	}
	return (1);
}

void	ft_start_render(void)
{
	int a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		S.lendian = 1;
	else
		S.lendian = 0;
	if (!(S.mlx = mlx_init()))
		return ;
	ft_check_res();
	if (!(S.win = mlx_new_window(S.mlx, S.res[0], S.res[1], "RayTracing")))
		return ;
	mlx_string_put(S.mlx, S.win, S.res[0] / 2 - 35, S.res[1] / 2,
				0xFFFFFF, "LOADING...");
	ft_load_scene();
	S.click = 0;
	mlx_hook(S.win, DestroyNotify, 0, exit_win, 0);
	mlx_key_hook(S.win, key_win, S.mlx);
	mlx_mouse_hook(S.win, mouse_press, S.mlx);
	mlx_loop(S.mlx);
}
