/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:37:37 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 13:17:24 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_line(char *elem, char *line)
{
	if (!ft_strncmp(elem, "R", 1))
		ft_fill_r(line);
	else if (!ft_strncmp(elem, "A", 1))
		ft_fill_a(line);
	else if (!ft_strncmp(elem, "cy", 2))
		ft_fill_cy(line);
	else if (!ft_strncmp(elem, "c", 1))
		ft_fill_c(line);
	else if (!ft_strncmp(elem, "l", 1))
		ft_fill_l(line);
	else if (!ft_strncmp(elem, "sp", 2))
		ft_fill_sp(line);
	else if (!ft_strncmp(elem, "pl", 2))
		ft_fill_pl(line);
	else if (!ft_strncmp(elem, "sq", 2))
		ft_fill_sq(line);
	else
		ft_fill_tr(line);
}

void	ft_fill_scene(int fd)
{
	char	*elem;
	char	*line;
	int		i;

	i = 1;
	elem = NULL;
	line = NULL;
	while (get_next_line(fd, &line) || i--)
	{
		if (line && ft_strlen(line))
		{
			elem = ft_check_elem(line);
			ft_fill_line(elem, line);
		}
		free(line);
		line = NULL;
	}
	free(line);
	if (!S.r)
		ft_fill_r("R 100 100");
	if (!S.a)
		ft_fill_a("A 0.1 255,255,255");
	if (!S.cam)
		ft_fill_c("c   0,0,0      0,0,-1    90");
	S.action_cam = S.cam;
}
