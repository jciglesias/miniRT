/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:44:28 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/21 12:07:21 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_resize_sp(int key, int *neg)
{
	static double diam;

	if (key >= 48 && key <= 57)
		diam = diam * 10 + (key - 48);
	else if (key == 65293 || key == 65421)
	{
		S.pix.sp->d = diam * *neg;
		diam = 0;
		*neg = 1;
		mlx_clear_window(S.mlx, S.win);
		ft_load_scene();
		S.click = 0;
	}
	else
		S.click = 0;
}

void	ft_resize_sq(int key, int *neg)
{
	static double sd;

	if (key >= 48 && key <= 57)
		sd = sd * 10 + (key - 48);
	else if (key == 65293 || key == 65421)
	{
		S.pix.sq->side = sd * *neg;
		sd = 0;
		*neg = 1;
		mlx_clear_window(S.mlx, S.win);
		ft_load_scene();
		S.click = 0;
	}
	else
		S.click = 0;
}

void	ft_resize_cy(int key, int *neg)
{
	static double temp;

	if (key >= 48 && key <= 57)
		temp = temp * 10 + (key - 48);
	else if (key == 44)
	{
		S.pix.cy->h = temp * *neg;
		temp = 0;
		*neg = 1;
	}
	else if (key == 65293 || key == 65421)
	{
		S.pix.cy->d = temp * *neg;
		temp = 0;
		*neg = 1;
		mlx_clear_window(S.mlx, S.win);
		ft_load_scene();
		S.click = 0;
	}
	else
		S.click = 0;
}

void	ft_resize(int key)
{
	static int neg = 1;
	static int pos = 5;
	char		output[2];

	if (key >= 65429 && key <= 65438)
		ft_numb_convert(&key);
	output[0] = (char)key;
	output[1] = 0;
	mlx_string_put(S.mlx, S.win, pos += 5, 10, 0xFFFFFF, output);
	if (key == 45 || key == 65453)
		neg = -1;
	if (S.pix.fig == 1)
		ft_resize_sp(key, &neg);
	else if (S.pix.fig == 3)
		ft_resize_sq(key, &neg);
	else if (S.pix.fig == 4)
		ft_resize_cy(key, &neg);
	else
		S.click = 0;
	if (key == 65293 || key == 65421)
		pos = 5;
}
