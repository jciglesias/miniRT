/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:10:17 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/21 19:57:38 by jiglesia         ###   ########.fr       */
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
# include <math.h>
# define	S g_scene
# define	PL plane
# define	L light
# define	TR triangle
# define	SQ square
# define	CY cylinder
# define	SP sphere
# define	C cam
# define	E endian
# define	U unsigned

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
	t_cam			*action_cam;
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

extern t_scene		g_scene;

void				ft_init_scene(void);
void				ft_init_int(int i, int *a);
void				ft_init_double(int i, double *a);
t_cam				*ft_init_cam(void);
t_layer				ft_init_layer(t_layer layer);
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

/*
** events
*/

int					key_win(int key, void *p);
int					mouse_win(int button, int x, int y, void *p);

/*
** rendering
*/

void				ft_load_scene(void);
void				ft_plotrt(void);
int					**ft_mallotrix(int **bmp);
int					ft_rgb(unsigned char r, unsigned char g,
							unsigned char b);
int					ft_color_sp(double *vec, double *o, double *t);
int					ft_color_pl(double *vec, double *o, double *t);
int					ft_color_sq(double *vec, double *o, double *t);
int					ft_color_cy(double *vec, double *o, double *t);
int					ft_color_tr(double *vec, double *o, double *t);
double				ft_tan(double rad);
double				ft_hipo(double a, double b);
double				ft_degtorad(double deg);
void				ft_camera_to_world(double *p, t_cam *c);
void				ft_normal(double *p);
double				ft_magnitude(double *p);
void				ft_dif_vector(double *center, double *o, double *l);
void				ft_sum_vector(double *center, double *vec, double *p);
double				ft_dot_product(double *a, double *b);
void				ft_crossp(double *a, double *b, double *p);
double				ft_t0t1(double t0, double t1);
void				ft_magxvec(double *vec, double magm, double *p);
double				ft_maxx(double *n, double mag);
double				ft_maxy(double *n, double mag);
int					ft_cmpangles(double x, double y, double *p, t_triangle *tr);
double				ft_angle(double *a, double *b, double *c);
int					ft_sq_to_pl(double *vec, double *o, double *t,
								t_square *pl);
int					ft_tr_to_pl(double *vec, double *o, double *t,
								t_triangle *tr);
int					ft_colorsphere(double *vec, double *o, double *t,
								   t_sphere *sp);
int					ft_colorplane(double *vec, double *o, double *t,
								   t_plane *pl);
int					ft_colorsquare(double *vec, double *o, double *t,
								   t_square *sq);
int					ft_colortriangle(double *vec, double *o, double *t,
								   t_triangle *tr);


/*
** testing
*/

void				test_scene(void);

//int					ft_skip(char *str, char *line);
#endif
