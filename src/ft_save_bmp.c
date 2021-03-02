/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:09:24 by jiglesia          #+#    #+#             */
/*   Updated: 2021/03/02 16:26:33 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_create_file(char *a)
{
	char	*filename;
	int		fd;

	if (!(filename = (char *)malloc(sizeof(char) * 20)))
		return (0);
	filename[0] = '\0';
	ft_strlcat(filename, "bmps/cam_", 20);
	ft_strlcat(filename, a, 20);
	ft_strlcat(filename, ".bmp", 20);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	free(filename);
	return (fd);
}

void	ft_create_header(void)
{
	S.head.type[0] = 0x42;
	S.head.type[1] = 0x4D;
	S.head.size = (S.res[0] * S.res[1] * 4) + 54;
	S.head.reserved = 0x00000000;
	S.head.offset = 0x36;
	S.head.size2 = 40;
	S.head.width = S.res[0];
	S.head.height = -S.res[1];
	S.head.colplanes = 1;
	S.head.bpp = 32;
	S.head.compression = 0;
	S.head.img_size = (S.res[0] * S.res[1] * 4);
	S.head.x_ppm = 2835;
	S.head.y_ppm = 2835;
	S.head.color_number = 0;
	S.head.important_color = 0;
}

void	ft_write_header(int fd)
{
	int a;

	a = write(fd, &S.head.type, 2);
	a = write(fd, &S.head.size, 4);
	a = write(fd, &S.head.reserved, 4);
	a = write(fd, &S.head.offset, 4);
	a = write(fd, &S.head.size2, 4);
	a = write(fd, &S.head.width, 4);
	a = write(fd, &S.head.height, 4);
	a = write(fd, &S.head.colplanes, 2);
	a = write(fd, &S.head.bpp, 2);
	a = write(fd, &S.head.compression, 4);
	a = write(fd, &S.head.img_size, 4);
	a = write(fd, &S.head.x_ppm, 4);
	a = write(fd, &S.head.y_ppm, 4);
	a = write(fd, &S.head.color_number, 4);
	a = write(fd, &S.head.important_color, 4);
	(void)a;
}

void	ft_write_file(int **map, int fd, int x, int y)
{
	char	*array;
	int		i;

	array = (char *)malloc(sizeof(char) * S.res[0] * S.res[1] * 4);
	i = 0;
	while (x < S.res[0])
	{
		array[i++] = map[y][x] & 255;
		array[i++] = (map[y][x] & 255 << 8) >> 8;
		array[i++] = (map[y][x] & 255 << 16) >> 16;
		array[i++] = 0;
		x++;
		if (x == S.res[0])
			y++;
		if (y < S.res[1] && x == S.res[0])
			x = 0;
	}
	i = write(fd, array, S.res[0] * S.res[1] * 4);
	free(array);
}

void	ft_save_file(int **map, char *a)
{
	int fd;

	fd = ft_create_file(a);
	ft_create_header();
	ft_write_header(fd);
	ft_write_file(map, fd, 0, 0);
	close(fd);
}
