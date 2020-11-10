/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ciglesia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:11:46 by user              #+#    #+#             */
/*   Updated: 2020/11/10 13:51:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_color_ptr(unsigned char *line, int opp, int endian, int color, int x)
{
	int byte;
	int dec;

	dec = opp;
	byte = x * opp;
	while (dec--)
		if (endian == S.lendian)
		{
			if (endian)
				*(line + byte + dec) = ((unsigned char *)(&color))[4 - opp+dec];
			else
				*(line + byte + dec) = ((unsigned char *)(&color))[dec];
		}
		else
		{
			if (endian)
				*(line + byte + dec) = ((unsigned char *)(&color))[opp - 1-dec];
			else
				*(line + byte + dec) = ((unsigned char *)(&color))[3 - dec];
		}
}

static void	fill_img(t_layer *l, int w, int h, int **bmp)
{
  int	x;
  int	y;
  int	color;
  int	color2;
  unsigned char *ptr;

  y = 0;
  while (y < h)
  {
      ptr = (unsigned char *)l->data + y * l->bpl;
      x = 0;
      while (x < w)
	  {

		  color = bmp[y][x];
		  color2 = mlx_get_color_value(S.mlx, color);
		  set_color_ptr(ptr, l->bpp/8, l->endian, color2, x);
		  x++;
	  }
	  y++;
  }
}

void	ft_plotrt(void)
{
	t_cam	*cam;
	t_layer	*l;

	cam = S.cam;
	while (cam)
	{
		l = &cam->layer;
		if (!(l->img = mlx_new_image(S.mlx, S.res[0], S.res[1])))
			exit(1);
		l->data = mlx_get_data_addr(l->img, &l->bpp, &l->bpl, &l->endian);
		fill_img(l, S.res[0], S.res[1], cam->bmp);
		cam = cam->next;
	}
	mlx_put_image_to_window(S.mlx, S.win, S.cam->layer.img, 0, 0);
	mlx_string_put(S.mlx, S.win, 5, S.res[1] - 5, 0xFFFFFF, "cam 1");
}
