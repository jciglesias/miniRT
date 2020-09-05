/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:57 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/05 14:38:35 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argv, char **argc)
{
	void	*mlx;
	void	*win1;
	t_scene	scene;
	int		fd;

	if (argv == 2)
	{
		if (!(mlx = mlx_init()))
			exit(1);
		if ((fd = open(argc[1], O_RDONLY)) < 1)
			exit(1);
		if (!ft_check_entry(fd, NULL))
		{
			close(fd);
			exit (1);
		}
		close(fd);
		if ((fd = open(argc[1], O_RDONLY)) < 1)
			exit(1);
		ft_init_scene(&scene);
		ft_fill_scene(&scene, fd);
		if (!(win1 = mlx_new_window(mlx, scene.res[0], scene.res[1], "ventana 1")))
			exit(1);
		mlx_loop(mlx);
	}
}
