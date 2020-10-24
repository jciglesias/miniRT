/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_elements2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 20:01:46 by jiglesia          #+#    #+#             */
/*   Updated: 2020/10/24 13:10:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square	*ft_init_sq(void)
{
	t_square *sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	ft_init_double(3, sq->xyz);
	ft_init_double(3, sq->vec);
	sq->side = 0.;
	ft_init_int(3, sq->rgb);
	sq->next = NULL;
	return (sq);
}

t_cylinder	*ft_init_cy(void)
{
	t_cylinder *cy;

	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (NULL);
	ft_init_double(3, cy->xyz);
	ft_init_double(3, cy->vec);
	cy->d = 0.;
	cy->h = 0.;
	ft_init_int(3, cy->rgb);
	cy->next = NULL;
	return (cy);
}

t_triangle	*ft_init_tr(void)
{
	t_triangle *tr;

	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	ft_init_double(9, tr->xyz);
	ft_init_int(3, tr->rgb);
	tr->next = NULL;
	return (tr);
}

t_layer		*ft_init_layer(void)
{
	t_layer	*layer;

	if (!(layer = (t_layer *)malloc(sizeof(t_layer))))
		return (NULL);
	layer->img = NULL;
	layer->bpp = 0;
	layer->bpl = 0;
	layer->endian = -1;
	layer->data = NULL;
	layer->next = NULL;
}
