/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:49:08 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/13 01:17:26 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_sp(char *line, t_scene *scene)
{
	char		**split;
	t_sphere	*new;

	split = ft_split(line, ' ');
	scene->sp++;
	new = ft_init_sp();
	ft_fill_xyz(new->xyz, split[1]);
	new->d = ft_atod(split[2]);
	ft_fill_rgb(new->rgb, split[3]);
	new->next = scene->sphere;
	scene->sphere = new;
	ft_strerror("", 0, split);
}

void	ft_fill_pl(char *line, t_scene *scene)
{
	char	**split;
	t_plane	*new;

	split = ft_split(line, ' ');
	new = ft_init_pl();
	scene->pl++;
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(new->vec, split[2]);
	ft_fill_rgb(new->rgb, split[3]);
	new->next = scene->plane;
	scene->plane = new;
	ft_strerror("", 0, split);
}

void	ft_fill_sq(char *line, t_scene *scene)
{
	char		**split;
	t_square	*new;

	split = ft_split(line, ' ');
	new = ft_init_sq();
	scene->sq++;
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(new->vec, split[2]);
	new->side = ft_atod(split[3]);
	ft_fill_rgb(new->rgb, split[4]);
	new->next = scene->square;
	scene->square = new;
	ft_strerror("", 0, split);
}

void	ft_fill_cy(char *line, t_scene *scene)
{
	t_cylinder	*new;
	char		**split;

	split = ft_split(line, ' ');
	new = ft_init_cy();
	scene->cy++;
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(new->vec, split[2]);
	new->d = ft_atod(split[3]);
	new->h = ft_atod(split[4]);
	ft_fill_rgb(new->rgb, split[5]);
	new->next = scene->cylinder;
	scene->cylinder = new;
	ft_strerror("", 0, split);
}

void	ft_fill_tr(char *line, t_scene *scene)
{
	t_triangle	*new;
	char		**split;

	split = ft_split(line, ' ');
	new = ft_init_tr();
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(&new->xyz[3], split[2]);
	ft_fill_xyz(&new->xyz[6], split[3]);
	ft_fill_rgb(new->rgb, split[4]);
	new->next = scene->triangle;
	scene->triangle = new;
	ft_strerror("", 0, split);
}
