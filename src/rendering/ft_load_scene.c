/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 22:52:25 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/08 20:37:24 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_fill_bmp(t_cam *c, int **bmp)
{
	int		i;
	int		j;

	i = -1;
	while (bmp[++i][j])
	{
		j = -1;
		while (bmp[i][++j])
			if (ft_fxysp(ft_norm(i, j, c), c->xyz, sp))
				bmp[i][j] = ft_fxysp(ft_norm(i, j, c->xyz), c->xyz, sp);
	}
	c->bmp = bmp;
}

void	ft_load_scene(void)
{
	t_cam	*c;
	int		i;
	int		j;

	c = S.cam;
	while (c)
	{
		i = 0;
		ft_mallotrix(c->bmp);
		while (i < S.res[1])
		{
			j = 0;
			while (j < S.res[0])
				bmp[i][j++] = 0;
			i++;
		}
		ft_fill_bmp(c, bmp);
		c = c->next;
	}
}
