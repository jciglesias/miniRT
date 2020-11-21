/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:57 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/21 19:16:47 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	g_scene;

int	main(int argv, char **argc)
{
	int		fd;

	if (argv == 2)
	{
		if ((fd = open(argc[1], O_RDONLY)) < 1)
			exit(1);
		if (!ft_check_entry(fd, NULL, 0, 0))
		{
			close(fd);
			exit(1);
		}
		close(fd);
		if ((fd = open(argc[1], O_RDONLY)) < 1)
			exit(1);
		ft_init_scene();
		ft_fill_scene(fd);
		close(fd);
		ft_start_render();
	}
}
