/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:57 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/28 23:26:18 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main()
{
	void	*mlx;
	void	*win1;
	t_scene	scene;

	if (!(mlx = mlx_init()))
		exit(1);
	if (!(win1 = mlx_new_window(mlx, 500, 500, "ventana 1")))
		exit(1);
	ft_init_scene(scene);
	mlx_loop(mlx);
}
