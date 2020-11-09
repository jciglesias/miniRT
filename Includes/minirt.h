/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:57:59 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/09 00:46:28 by jiglesia         ###   ########.fr       */
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
# define	S scene
# define	PL plane
# define	L light
# define	TR triangle
# define	SQ square
# define	CY cylinder
# define	SP sphere
# define	C cam
# define	E endian

typedef struct		s_layer
{
	void			*img;
	int				bpp;
	int				bpl;
	int				endian;
	char			*data;
}					t_layer;

typedef struct		s_cam
{
	double			xyz[3];
	double			vec[3];
	int				fov;
	int				**bmp;
	t_layer			layer;
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
	int				lendian;
	void			*mlx;
	void			*win;
}					t_scene;

extern t_scene		scene;

void				ft_init_scene(void);
void				ft_init_int(int i, int *a);
void				ft_init_double(int i, double *a);
t_cam				*ft_init_cam(void);
t_light				*ft_init_l(void);
t_sphere			*ft_init_sp(void);
t_plane				*ft_init_pl(void);
t_square			*ft_init_sq(void);
t_cylinder			*ft_init_cy(void);
t_triangle			*ft_init_tr(void);
void				ft_fill_scene(int fd);
void				ft_fill_rgb(int *a, char *line);
void				ft_fill_xyz(double *a, char *line);
void				ft_fill_r(char *line);
void				ft_fill_a(char *line);
void				ft_fill_c(char *line);
void				ft_fill_l(char *line);
void				ft_fill_sp(char *line);
void				ft_fill_pl(char *line);
void				ft_fill_sq(char *line);
void				ft_fill_cy(char *line);
void				ft_fill_tr(char *line);
int					ft_check_entry(int fd, char *line, int r, int a);
char				*ft_check_elem(char *line);
int					ft_check_r(char *line);
int					ft_check_a(char *line);
int					ft_check_c(char *line);
int					ft_check_l(char *line);
int					ft_check_sp(char *line);
int					ft_check_pl(char *line);
int					ft_check_sq(char *line);
int					ft_check_cy(char *line);
int					ft_check_tr(char *line);
int					ft_check_double(char *dob);
int					ft_check_xyz(char *xyz);
int					ft_check_vec(char *vec);
int					ft_check_rgb(char *rgb);
int					ft_strerror(char *str, int a, char **line);
void				ft_start_render(void);
int					key_win(int key, void *p);
int					mouse_win(int button, int x, int y, void *p);
void				ft_load_scene(void);
void				ft_mallotrix(int **bmp);

//int					ft_skip(char *str, char *line);
#endif
