/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:24:11 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 16:20:32 by user             ###   ########.fr       */
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
	if (scene.res[0] > x)
		scene.res[0] = x;
	if (scene.res[1] > y - 60)
		scene.res[1] = y - 60;
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
		exit(1);
	ft_check_res();
	if (!(S.win = mlx_new_window(S.mlx, S.res[0], S.res[1], "RayTracing")))
		exit(1);
	mlx_string_put(S.mlx, S.win, S.res[0]/2 - 35, S.res[1]/2, 0xFFFFFF, "LOADING...");
	ft_load_scene();
	mlx_key_hook(S.win, key_win, S.mlx);
	mlx_loop(S.mlx);
}
