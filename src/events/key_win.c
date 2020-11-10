/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:48:07 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/10 14:24:42 by user             ###   ########.fr       */
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
/*
void	change_cam(int left)
{
	t_cam	*cam;
	t_cam	*tmpcam;

	cam = S.cam;
	while (cam && cam != S.action_cam)
		cam = cam->next;
	if (left)
	{
		tmpcam = S.cam;
	}
	else
	{

	}
}
*/
int		key_win(int key, void *p)
{
//	char *ccams;

	(void)p;
	if (key == 0xFF1B)
		exit(0);
	if (key == 65361)
	{
		mlx_clear_window(S.mlx, S.win);
		//mlx_put_image_to_window(S.mlx,S.win,imgt,0,0);//posicion de img (0,0)
		//ccams = ft_itoa(count_cams());
		mlx_string_put(S.mlx, S.win, 28, S.res[1] - 5, 0xFFFFFF, "0");
	}
	if (key == 65363)
	{
		mlx_clear_window(S.mlx, S.win);
		//mlx_put_image_to_window(S.mlx,S.win,imgt,0,0);//posicion de img (0,0)
		//ccams = ft_itoa(count_cams());
		mlx_string_put(S.mlx, S.win, 28, S.res[1] - 5, 0xFFFFFF, "0");
	}
	mlx_string_put(S.mlx, S.win, 5, S.res[1] - 5, 0xFFFFFF, "cam");
	return (0);
}
