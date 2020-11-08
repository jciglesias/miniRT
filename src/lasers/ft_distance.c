/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:01:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/07 16:36:49 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mallotrix(t_dist *m)
{
	int	i;

	i = 0;
	if (!(m->mat = (double **)malloc(sizeof(double *) * S.res[0])))
		return ;
	while (i < S.res[0])
	{
		if (!(m->mat[i] = (double *)malloc(sizeof(double) * S.res[1])))
			return ;
		ft_bzero(m->mat[i++], sizeof(double) * S.res[1]);
	}
}

void	ft_distance_sp(t_cam *c, t_sphere *sp)
{
	t_dist	*m;
	int		i;
	int		j;

	m = c->dist;
	while (m = m->next);
	i = -1;
	while (sp)
	{
		m = ft_init_matix();
		ft_mallotrix(m);
		while (m->mat[++i][j])
		{
			j = -1;
			while (m->mat[i][++j])
				if (ft_fxysp(ft_norm(i, j, c), c->xyz, sp))
					m->mat[i][j] = ft_fxysp(ft_norm(i, j, c->xyz), c->xyz, sp);
		}
		sp = sp->next;
	}
}
