/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:39:56 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/10 01:25:13 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_rotate_figure(void)
{
	if (S.pix.fig == 2)
		ft_veccpy(S.rot, S.pix.pl->vec);
	else if (S.pix.fig == 3)
		ft_veccpy(S.rot, S.pix.sq->vec);
	else if (S.pix.fig == 4)
		ft_veccpy(S.rot, S.pix.cy->vec);
}

void	ft_rotate(int key)
{
	static int i;

	if (key == 44)
		i++;
	else if (key >= 48 && key <= 57)
		S.rot[i] = S.rot[i] * 10 + (key - 48);
	else if (key == 65293)
	{
		ft_normal(S.rot);
		ft_rotate_figure();
		mlx_clear_window(S.mlx, S.win);
		ft_load_scene();
		i = 0;
		S.click = 0;
	}
	else
		S.click = 0;
}

void	ft_translate_figure(void)
{
	if (S.pix.fig == 1)
		ft_veccpy(S.trans, S.pix.sp->xyz);
	else if (S.pix.fig == 2)
		ft_veccpy(S.trans, S.pix.pl->xyz);
	else if (S.pix.fig == 3)
		ft_veccpy(S.trans, S.pix.sq->xyz);
	else if (S.pix.fig == 4)
		ft_veccpy(S.trans, S.pix.cy->xyz);
}

void	ft_translate(int key)
{
	static int i;

	if (key == 44)
		i++;
	else if (key >= 48 && key <= 57)
		S.trans[i] = S.trans[i] * 10 + (key - 48);
	else if (key == 65293)
	{
		ft_translate_figure();
		mlx_clear_window(S.mlx, S.win);
		ft_load_scene();
		i = 0;
		S.click = 0;
	}
	else
		S.click = 0;
}
