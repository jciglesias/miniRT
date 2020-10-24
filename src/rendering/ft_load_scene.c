/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:52:25 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/18 01:30:22 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_load_scene(t_scene *scene, void *mlx, void *win1)
{
	mlx_string_put(mlx, win1, scene->plane->xyz[0], scene->plane->xyz[1], 0x00FF0000, "prueba");
}
