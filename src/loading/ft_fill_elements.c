/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 21:17:32 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/13 18:02:49 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_r(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	S.r++;
	S.res[0] = ft_atoi(split[1]);
	S.res[1] = ft_atoi(split[2]);
	S.mlx = mlx_init();
	ft_check_res();
	ft_strerror("", 0, split);
}

void	ft_fill_a(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	S.a++;
	S.al = ft_atod(split[1]);
	ft_fill_rgb(S.rgb, split[2]);
	ft_strerror("", 0, split);
}

void	ft_fill_c(char *line)
{
	char	**split;
	t_cam	*new;

	S.c++;
	split = ft_split(line, ' ');
	new = ft_init_cam();
	ft_fill_xyz(new->xyz, split[1]);
	ft_fill_xyz(new->vec, split[2]);
	ft_normal(new->vec);
	new->fov = ft_atoi(split[3]);
	if (new->fov > 179)
		new->fov = 179;
	new->next = S.cam;
	S.cam = new;
	ft_strerror("", 0, split);
}

void	ft_fill_l(char *line)
{
	char	**split;
	t_light	*new;

	S.l++;
	split = ft_split(line, ' ');
	new = ft_init_l();
	ft_fill_xyz(new->xyz, split[1]);
	new->bri = ft_atod(split[2]);
	ft_fill_rgb(new->rgb, split[3]);
	new->next = S.light;
	S.light = new;
	ft_strerror("", 0, split);
}
