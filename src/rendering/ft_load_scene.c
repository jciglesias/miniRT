/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:52:25 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/08 16:17:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
void	ft_distance_fig(t_cam *c)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_square	*sq;
	t_cylinder	*cy;
	t_triangle	*tr;

	sp = S.SP;
	pl = S.PL;
	sq = S.SQ;
	cy = S.CY;
	tr = S.TR;
	ft_distance_sp(c, sp);
	ft_distance_pl(c, pl);
	ft_distance_sq(c, sq);
	ft_distance_cy(c, cy);
	ft_distance_tr(c, tr);
}
*/
void	ft_distance_cam(void)
{
	t_cam	*c;

	c = S.cam;
	while (c)
	{
		//ft_distance_fig(c);
		c = c->next;
	}
}

void	ft_load_scene(void)
{
	ft_distance_cam();
}
