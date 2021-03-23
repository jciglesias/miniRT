/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:39:56 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/11 19:06:59 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_rotate_figure(void)
{
	ft_normal(S.rot);
	if (S.pix.fig == 2)
		ft_veccpy(S.rot, S.pix.pl->vec);
	else if (S.pix.fig == 3)
		ft_veccpy(S.rot, S.pix.sq->vec);
	else if (S.pix.fig == 4)
		ft_veccpy(S.rot, S.pix.cy->vec);
	ft_init_double(3, S.rot);
	mlx_clear_window(S.mlx, S.win);
	ft_load_scene();
	S.click = 0;
}

void	ft_numb_convert(int *key)
{
	if (*key == 65438)
		*key = 48;
	else if (*key == 65436)
		*key = 49;
	else if (*key == 65433)
		*key = 50;
	else if (*key == 65435)
		*key = 51;
	else if (*key == 65430)
		*key = 52;
	else if (*key == 65437)
		*key = 53;
	else if (*key == 65432)
		*key = 54;
	else if (*key == 65429)
		*key = 55;
	else if (*key == 65431)
		*key = 56;
	else if (*key == 65434)
		*key = 57;
}

void	ft_rotate(int key)
{
	static int	i;
	static int	neg = 1;
	static int	pos = 5;
	char		output[2];

	if (key >= 65429 && key <= 65438)
		ft_numb_convert(&key);
	output[0] = (char)key;
	output[1] = 0;
	mlx_string_put(S.mlx, S.win, pos += 5, 10, 0xFFFFFF, output);
	if (key == 44)
	{
		S.rot[i] *= neg;
		neg = 1;
		i++;
	}
	else if (key == 45 || key == 65453)
		neg = -1;
	else if (key >= 48 && key <= 57)
		S.rot[i] = S.rot[i] * 10 + (key - 48);
	else if (key == 65293 || key == 65421)
	{
		pos = 5;
		S.rot[i] *= neg;
		neg = 1;
		ft_rotate_figure();
		i = 0;
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
	ft_init_double(3, S.trans);
	mlx_clear_window(S.mlx, S.win);
	ft_load_scene();
	S.click = 0;
}

void	ft_translate(int key)
{
	static int i;
	static int neg = 1;
	static int pos = 5;
	char		output[2];

	if (key >= 65429 && key <= 65438)
		ft_numb_convert(&key);
	output[0] = (char)key;
	output[1] = 0;
	mlx_string_put(S.mlx, S.win, pos += 5, 10, 0xFFFFFF, output);
	if (key == 44)
	{
		S.trans[i] *= neg;
		neg = 1;
		i++;
	}
	else if (key == 45 || key == 65453)
		neg = -1;
	else if (key >= 48 && key <= 57)
		S.trans[i] = S.trans[i] * 10 + (key - 48);
	else if (key == 65293 || key == 65421)
	{
		pos = 5;
		S.trans[i] *= neg;
		neg = 1;
		ft_translate_figure();
		i = 0;
	}
	else
		S.click = 0;
}
