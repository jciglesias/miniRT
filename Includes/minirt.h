/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:57:59 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/30 22:21:45 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINIRT_H
# define	MINIRT_H
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_cam
{
	double			xyz[3];
	double			vec[3];
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	double			xyz[3];
	double			bri;
	int				rgb[3];
	struct s_light	*next;
}					t_light;

typedef struct		s_sphere
{
	double			xyz[3];
	double			d;
	int				rgb[3];
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane
{
	double			xyz[3];
	double			vec[3];
	int				rgb[3];
	struct s_plane	*next;
}					t_plane;

typedef struct		s_square
{
	double			xyz[3];
	double			vec[3];
	double			side;
	int				rgb[3];
	struct s_square	*next;
}					t_square;

typedef struct		s_cyl
{
	double			xyz[3];
	double			vec[3];
	double			d;
	double			h;
	int				rgb[3];
	struct s_cyl	*next;
}					t_cylinder;

typedef struct		s_tri
{
	double			xyz[9];
	int				rgb[3];
	struct s_tri	*next;
}					t_triangle;

typedef struct		s_scene
{
	int				r;
	int				res[2];
	int				a;
	double			al;
	int				rgb[3];
	int				c;
	t_cam			*cam;
	int				l;
	t_light			*light;
	int				sp;
	t_sphere		*sphere;
	int				pl;
	t_plane			*plane;
	int				sq;
	t_square		*square;
	int				cy;
	t_cylinder		*cylinder;
	int				tr;
	t_triangle		*triangle;
}					t_scene;

void				ft_init_scene(t_scene *scene);
void				ft_fill_scene(t_scene *scene, int fd);
int					ft_check_entry(int fd, char **line, int a);
int					ft_skip(char *str, char *line);
#endif
