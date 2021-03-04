/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 00:17:50 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/04 21:17:25 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_cam(t_cam *camera)
{
	t_cam	*cam;
	int		i;

	cam = camera;
	while (cam)
	{
		if (cam->layer.img)
			mlx_destroy_image(S.mlx, cam->layer.img);
		i = 0;
		while (i < S.res[1])
			free(cam->bmp[i++]);
		free(cam->bmp);
		cam = cam->next;
		free(camera);
		camera = cam;
	}
}

void	ft_free_light(t_light *l, t_sphere *sp, t_plane *pl)
{
	t_light		*temp;
	t_sphere	*sptemp;
	t_plane		*pltemp;

	while (l)
	{
		temp = l->next;
		free(l);
		l = temp;
	}
	while (sp)
	{
		sptemp = sp->next;
		free(sp);
		sp = sptemp;
	}
	while (pl)
	{
		pltemp = pl->next;
		free(pl);
		pl = pltemp;
	}
}

void	ft_free_square(t_square *sq, t_cylinder *cy)
{
	t_square	*temp;
	t_cylinder	*cytemp;

	while (sq)
	{
		temp = sq->next;
		free(sq);
		sq = temp;
	}
	while (cy)
	{
		cytemp = cy->next;
		free(cy);
		cy = cytemp;
	}
}

void	ft_free_triangle(t_triangle *tr)
{
	t_triangle *temp;

	while (tr)
	{
		temp = tr->next;
		free(tr);
		tr = temp;
	}
}

void	ft_free_scene(void)
{
	ft_free_cam(S.cam);
	ft_free_light(S.light, S.sphere, S.plane);
	ft_free_square(S.square, S.cylinder);
	ft_free_triangle(S.triangle);
	if (S.win)
		mlx_destroy_window(S.mlx, S.win);
	if (S.mlx)
	{
		mlx_destroy_display(S.mlx);
		free(S.mlx);
	}
}
