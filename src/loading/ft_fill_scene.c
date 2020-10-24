/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:37:37 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/13 01:07:16 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_line(char *elem, char *line, t_scene *scene)
{
	if (!ft_strncmp(elem, "R", 1))
		ft_fill_r(line, scene);
	else if (!ft_strncmp(elem, "A", 1))
		ft_fill_a(line, scene);
	else if (!ft_strncmp(elem, "cy", 2))
		ft_fill_cy(line, scene);
	else if (!ft_strncmp(elem, "c", 1))
		ft_fill_c(line, scene);
	else if (!ft_strncmp(elem, "l", 1))
		ft_fill_l(line, scene);
	else if (!ft_strncmp(elem, "sp", 2))
		ft_fill_sp(line, scene);
	else if (!ft_strncmp(elem, "pl", 2))
		ft_fill_pl(line, scene);
	else if (!ft_strncmp(elem, "sq", 2))
		ft_fill_sq(line, scene);
	else
		ft_fill_tr(line, scene);
}

void	ft_fill_scene(t_scene *scene, int fd)
{
	char	*elem;
	char	*line;
	int		i;

	i = 1;
	elem = NULL;
	line = NULL;
	while (get_next_line(fd, &line) || i--)
	{
		elem = ft_check_elem(line);
		ft_fill_line(elem, line, scene);
		free(line);
		line = NULL;
	}
	free(line);
}
