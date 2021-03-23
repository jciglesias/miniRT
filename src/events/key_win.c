/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:48:07 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/10 23:45:19 by jiglesia         ###   ########.fr       */
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
	mlx_put_image_to_window(S.mlx, S.win, S.action_cam->layer.img, 0, 0);
}

void 	ft_display_next(int sense, char *ccams, void *p)
{
	mlx_clear_window(p, S.win);
	change_cam(sense);
	ccams = ft_itoa(count_cams());
	mlx_string_put(p, S.win, 28, S.res[1] - 5, 0xFFFFFF, ccams);
	free(ccams);
	S.click = 0;
}

int		key_win(int key, void *p)
{
	if (key == 0xFF1B)
	{
		ft_free_scene();
		exit(0);
	}
	else if (key == 65361)
		ft_display_next(1, NULL, p);
	else if (key == 65363)
		ft_display_next(0, NULL, p);
	else if (S.click == 1)
		ft_translate(key);
	else if (S.click == 2)
		ft_resize(key);
	else if (S.click == 3)
		ft_rotate(key);
	mlx_string_put(p, S.win, 5, S.res[1] - 5, 0xFFFFFF, "cam");
	return (0);
}
