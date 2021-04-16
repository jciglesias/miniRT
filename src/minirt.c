/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 21:04:57 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 20:30:22 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	g_scene;

int	ft_check_and_fill(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 1)
		return (0);
	if (!ft_check_entry(fd, NULL, 0, 0))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if ((fd = open(file, O_RDONLY)) < 1)
		return (0);
	ft_init_scene();
	ft_fill_scene(fd);
	close(fd);
	return (1);
}

int	ft_show_window(char *file)
{
	if (!ft_check_and_fill(file))
		return (0);
	ft_start_render();
	return (0);
}

int	ft_save_bmp(char *file)
{
	t_cam	*c;
	int		i;

	if (!ft_check_and_fill(file))
		return (1);
	c = S.cam;
	while (c)
	{
		c->bmp = ft_mallotrix(c->bmp);
		ft_fill_bmp(c, c->bmp);
		c = c->next;
	}
	c = S.cam;
	i = 1;
	while (c)
	{
		ft_save_file(c->bmp, ft_itoa(i));
		i++;
		c = c->next;
	}
	ft_free_scene();
	return (0);
}

int	ft_check_rt(char *file)
{
	int i;

	i = 0;
	while (file[i])
	{
		if (file[i++] == '.')
			if (file[i++] == 'r')
				if (file[i] == 't')
					return (1);
	}
	return (0);
}

int	main(int argv, char **argc)
{
	if (argc[1])
		if (!ft_check_rt(argc[1]))
			return (ft_puterror("Wrong file\n", 1));
	if (argv == 2)
		return (ft_show_window(argc[1]));
	if (argv == 3)
	{
		if (!ft_strncmp(argc[2], "--save", 6))
			return (ft_save_bmp(argc[1]));
	}
	return (0);
}
