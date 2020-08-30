/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:45:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/30 14:20:04 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_r(char *line, t_scene *scene)
{
	int i;

	if (!scene->r)
	{
		i = 1;
		scene->r += 1;
		i += ft_skip(" ", &line[i]);
		if (*line[i] <= 48 || line[i] >= 57)
			return (0);
		scene->res[0] = ft_atoi(&line[i]);
		i += ft_skip("0123456789", &line[i]);
		i += ft_skip(" ", &line[i]);
		if (*line[i] <= 48 || line[i] >= 57)
			return (0);
		scene->res[1] = ft_atoi(&line[i]);
		i += ft_skip("0123456789", &line[i]);
		if (line[i] == '\0')
			return (1);
	}
	return (0);
}

int	ft_check_a(char *line, t_scene scene)
{
	int	i;

	if (!scene->a)
	{
		i = 1;
		scene->a += 1;
		i += ft_skip(" ", &line[i]);
		if (*line[i] <= 48 || line[i] >= 57)
			return (0);
		scene->al = ft_atod(&line[i]);
		i += ft_skip("0123456789.", &line[i]);
		i += ft_skip(" ", &line[i]);
		if (*line[i] <= 48 || line[i] >= 57)
			return (0);
		i += ft_fill_rgb(&line[i], scene->rgb);
		if (line[i] == '\0')
			return(1);
	}
	return (0);
}

int	ft_check_c(char *line, t_scene *scene)
{
	int		i;
	t_cam	*p;

	i = 1;
	p = scene->cam;
	i += ft_skip(" ", &line[i]);
	if (*line[i] <= 48 || line[i] >= 57)
			return (0);
	if (p)
		while (p)
			p = p->next;
	ft_init_cam(p);
	i += ft_fill_xyz(&line[i], p->xyz);
	i += ft_skip(" ", &line[i]);
	if ((*line[i] <= 48 || line[i] >= 57) && p = NULL)
		return (0);
	i += ft_fill_vec(&line[i], p->vec);
	i += ft_skip(" ", &line[i]);
	if ((*line[i] <= 48 || line[i] >= 57) && p = NULL)
		return (0);
	p->fov = ft_atoi(&line[i]);
	i += ft_skip("0123456789.", &line[i]);
	if (&line[i] == '\0')
		return (1);
	p = NULL;
	return (0);
}

int	ft_check_entry(int fd, char **line, int a, t_scene *scene)
{
	while (get_next_line(fd, line))
	{
		if (*line[0] == 'R')
			a = ft_check_r(*line, scene);
		else if (*line[0] == 'A')
			a = ft_check_a(*line, scene);
		else if (*line[0] == 'c')
			a = ft_check_c(*line, scene);
		else if (*line[0] == 'l')
			a = ft_check_l(*line);
		else if (*line[0] == 's' && *line[1] == 'p')
			a = ft_check_sp(*line);
		else if (*line[0] == 'p' && *line[1] == 'l')
			a = ft_check_pl(*line);
		else if (*line[0] == 's' && *line[1] == 'q')
			a = ft_check_sq(*line);
		else if (*line[0] == 'c' && *line[1] == 'y')
			a = ft_check_cy(*line);
		else if (*line[0] == 't' && *line[1] == 'r')
			a = ft_check_tr(*line);
		if (!a && *line[0] != '\0')
			return (0);
	}
	return (1);
}
