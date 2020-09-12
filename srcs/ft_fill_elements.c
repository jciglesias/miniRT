/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:17:32 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/13 01:17:02 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_r(char *line, t_scene *scene)
{
	char	**split;

	split = ft_split(line, ' ');
	scene->r++;
	scene->res[0] = ft_atoi(split[1]);
	scene->res[1] = ft_atoi(split[2]);
	ft_strerror("", 0, split);
}

void	ft_fill_a(char *line, t_scene *scene)
{
	char	**split;

	split = ft_split(line, ' ');
	scene->a++;
	scene->al = ft_atod(split[1]);
	ft_fill_rgb(scene->rgb, split[2]);
	ft_strerror("", 0, split);
}

void	ft_fill_c(char *line, t_scene *scene)
{
	char	**split;
	t_cam	*new;

	scene->c++;
	split = ft_split(line, ' ');
	new = ft_init_cam();
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(new->vec, split[2]);
	new->fov = ft_atoi(split[3]);
	new->next = scene->cam;
	scene->cam = new;
	ft_strerror("", 0, split);
}

void	ft_fill_l(char *line, t_scene *scene)
{
	char	**split;
	t_light	*new;

	scene->l++;
	split = ft_split(line, ' ');
	new = ft_init_l();
	ft_fill_xyz(new->xyz, split[1]);
	new->bri = ft_atod(split[2]);
	ft_fill_rgb(new->rgb, split[3]);
	new->next = scene->light;
	scene->light = new;
	ft_strerror("", 0, split);
}
