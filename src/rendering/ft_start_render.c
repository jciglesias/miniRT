/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:24:11 by jiglesia          #+#    #+#             */
/*   Updated: 2020/10/24 17:12:26 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_res(void)
{
	int x;
	int y;

	mlx_get_screen_size(S.mlx, &x, &y);
	if (scene.res[0] > x)
		scene.res[0] = x;
	if (scene.res[1] > y)
		scene.res[1] = y;
}

void	ft_start_render(void)
{
	if (!(S.mlx = mlx_init()))
		exit(1);
	ft_check_res();
	if (!(S.win = mlx_new_window(S.mlx, S.res[0], S.res[1], "ventana")))
		exit(1);
	ft_load_scene();
	mlx_key_hook(S.win, key_win, S.mlx);
	mlx_mouse_hook(S.win, mouse_win, S.mlx);
	//mlx_expose_hook(win1, expose_win, win1);
	mlx_loop(S.mlx);
}
