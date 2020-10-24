/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 13:24:11 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/18 01:26:52 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_res(void *mlx, t_scene *scene)
{
	int x;
	int y;

	mlx_get_screen_size(mlx, &x, &y);
	if (scene->res[0] > x)
		scene->res[0] = x;
	if (scene->res[1] > y)
		scene->res[1] = y;
}

void	ft_start_render(t_scene *scene)
{
	void	*mlx;
	void	*win1;

	if (!(mlx = mlx_init()))
		exit(1);
	ft_check_res(mlx, scene);
	if (!(win1 = mlx_new_window(mlx, scene->res[0], scene->res[1], "win1")))
		exit(1);
	ft_load_scene(scene, mlx, win1);
	mlx_key_hook(win1, key_win, win1);
	mlx_mouse_hook(win1, mouse_win, win1);
	//mlx_expose_hook(win1, expose_win, win1);
	mlx_loop(mlx);
}
