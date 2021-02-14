/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:35:58 by jiglesia          #+#    #+#             */
/*   Updated: 2021/02/13 14:37:05 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_ob_sp(double t, double *v, double *o)
{
	t_sphere *temp;

	temp = S.sphere;
	while (temp)
	{
		if (ft_sp_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_pl(double t, double *v, double *o)
{
	t_plane *temp;

	temp = S.plane;
	while (temp)
	{
		if (ft_pl_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_sq(double t, double *v, double *o)
{
	t_square *temp;

	temp = S.square;
	while (temp)
	{
		if (ft_sq_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_cy(double t, double *v, double *o)
{
	t_cylinder *temp;

	temp = S.cylinder;
	while (temp)
	{
		if (ft_cy_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		ft_ob_tr(double t, double *v, double *o)
{
	t_triangle *temp;

	temp = S.triangle;
	while (temp)
	{
		if (ft_tr_obstruction(t, v, o, temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}
