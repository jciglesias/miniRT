/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:48:07 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 14:48:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		count_cams(void)
{
	t_cam	*cam;
	int		count;

	count = 1;
	cam = S.cam;
	while (cam && cam != S.action_cam)
	{
		count++;
		cam = cam->next;
	}
	return (count);
}

void	change_cam(int left)
{
	t_cam	*cam;

	cam = S.cam;
	if (left)
	{
		if (S.action_cam == S.cam)
			while (cam->next)
				cam = cam->next;
		else
			while (cam && cam->next != S.action_cam)
				cam = cam->next;
	}
	else
	{
		if (S.action_cam->next)
			cam = S.action_cam->next;
	}
	S.action_cam = cam;
	mlx_put_image_to_window(S.mlx, S.win, S.action_cam->layer.img, 0, 0);//posicion de img (0,0)
}

int		key_win(int key, void *p)
{
	char *ccams;

	(void)p;
	if (key == 0xFF1B)
		exit(0);
	if (key == 65361)
	{
		mlx_clear_window(S.mlx, S.win);
		change_cam(1);
		ccams = ft_itoa(count_cams());
		mlx_string_put(S.mlx, S.win, 28, S.res[1] - 5, 0xFFFFFF, ccams);
	}
	if (key == 65363)
	{
		mlx_clear_window(S.mlx, S.win);
		change_cam(0);
		ccams = ft_itoa(count_cams());
		mlx_string_put(S.mlx, S.win, 28, S.res[1] - 5, 0xFFFFFF, ccams);
	}
	mlx_string_put(S.mlx, S.win, 5, S.res[1] - 5, 0xFFFFFF, "cam");
	return (0);
}
