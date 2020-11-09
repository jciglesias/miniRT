/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <ciglesia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:49:52 by user              #+#    #+#             */
/*   Updated: 2020/11/08 21:27:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		in_circle(int x, int y)
{
	int radius;
	int centerx;
	int centery;

	radius = 300;
	centerx = S.res[0] / 2;
	centery = S.res[1] / 2;
	if (ft_sqrt(((x - centerx)*(x-centerx)) + ((y-centery)*(y-centery))) <= radius)
		return (1);
	return (0);
}

void	set_color_ptr(unsigned char *line, int opp, int endian, int color, int x)
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

int	fill_img(unsigned char *data,int bpp,int sl,int w,int h,int endian)
{
  int	x;
  int	y;
  int	opp;
  //int	dec;
  int	color;
  int	color2;
  unsigned char *ptr;

  opp = bpp/8;
  printf("(bytes por pixel : %d) ", opp);
  y = h;
  int ff = 0;
  int aa = 0;
  while (y--)
  {
      ptr = data + y * sl;
      x = w;
	  ff = aa;
      while (x--)
	  {
		  if (in_circle(x, y))
			  color = ft_rgb(ff,ff,ff);
		  else
			  color = ft_rgb(0,0,0);
		  color2 = mlx_get_color_value(S.mlx, color);
		  set_color_ptr(ptr, opp, endian, color2, x);
		  if (x%4==0)
			  ff++;
	  }
	  if(y%4==0)
		  aa++;
  }
}

void	test_scene(void)
{
	void	*imgt;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;

	if (!(imgt = mlx_new_image(S.mlx,S.res[0],S.res[1])))
		exit(1);
	data = mlx_get_data_addr(imgt,&bpp,&sl,&endian);
	fill_img(data,bpp,sl,S.res[0],S.res[1],endian);
	mlx_put_image_to_window(S.mlx,S.win,imgt,0,0);//posicion de img (0,0)
}
