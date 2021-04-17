/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 01:10:17 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/17 17:37:29 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define S g_scene
# define PL plane
# define L light
# define TR triangle
# define SQ square
# define CY cylinder
# define SP sphere
# define C cam
# define E endian

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

typedef struct		s_pix
{
	double			t;
	double			vec[3];
	double			o[3];
	int				color[3];
	t_sphere		*sp;
	t_plane			*pl;
	t_square		*sq;
	t_cylinder		*cy;
	t_triangle		*tr;
	int				fig;
}					t_pix;

typedef struct		s_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
	unsigned int	size2;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}					t_head;

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
	double			normal[3];
	t_pix			pix;
	t_head			head;
	int				click;
	double			rot[3];
	double 			trans[3];
	int				shadow;
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
void				ft_save_file(int **map, char *a);
void				ft_check_res(void);

/*
** events
*/

int					key_win(int key, void *p);
int					mouse_press(int button, int x, int y, void *p);
void				ft_translate(int key);
void				ft_rotate(int key);
void				ft_resize(int key);
void				ft_numb_convert(int *key);

/*
** rendering
*/

void				ft_fill_bmp(t_cam *c, int **bmp);
void				ft_primray(double y, double x, t_cam *cam, double *vec);
int					ft_gtpxl(t_pix *pix);
void				ft_load_scene(void);
void				ft_plotrt(t_cam *cam, int count);
int					**ft_mallotrix(int **bmp);
int					ft_rgb(unsigned char r, unsigned char g,
							unsigned char b);
void				ft_color_sp(t_pix *pix);
void				ft_color_pl(t_pix *pix);
void				ft_color_sq(t_pix *pix);
void				ft_color_cy(t_pix *pix);
void				ft_color_tr(t_pix *pix);
double				ft_tan(double rad);
double				ft_hipo(double a, double b);
double				ft_quadrant(double x, double y, double rad);
double				ft_degtorad(double deg);
void				ft_camera_to_world(double *p, t_cam *c);
void				ft_normal(double *p);
double				ft_magnitude(double *p);
void				ft_dif_vector(double *center, double *o, double *l);
void				ft_sum_vector(double *center, double *vec, double *p);
double				ft_dot_product(double *a, double *b);
void				ft_crossp(double *a, double *b, double *p);
void				ft_veccpy(double *a, double *b);
void				ft_cpyrgb(int *a, int *b);
double				ft_t0t1(double t0, double t1);
void				ft_magxvec(double *vec, double mag, double *p);
double				ft_distance(double *a, double *b);
double				ft_maxx(double *n, double mag);
double				ft_maxy(double *n, double mag);
double				ft_maxz(double *n, double mag);
int					ft_cmpangles(double x, double y, double *p, t_triangle *tr);
double				ft_angle(double *a, double *b, double *c);
void				ft_move_x(double x, double *p);
void				ft_move_y(double y, double *p);
void				ft_move_z(double z, double *p);
int					ft_sq_to_pl(double *vec, double *o, double *t,
								t_square *pl);
int					ft_tr_to_pl(double *vec, double *o, double *t,
								t_triangle *tr);
double				ft_cy_to_pl(double *vec, double *o, double *c, double *n);
double				ft_intersect_base(double *vec, double *o,
									t_cylinder *cy, double *t);
double				ft_intersect_base2(double *vec, double *o,
									t_cylinder *cy, double *t);
void				ft_movecy(double *ray, t_cylinder *cy, double *vec,
							double *o);
double				ft_infinit_cy(double *vec, double *o, t_cylinder *cy);
double				ft_caps(double *vec, double *o, t_cylinder *cy);
void				ft_colorsphere(t_pix *pix, t_sphere *sp);
void				ft_colorplane(t_pix *pix, t_plane *pl);
void				ft_colorsquare(t_pix *pix, t_square *sq);
void				ft_colortriangle(t_pix *pix, t_triangle *tr);
void				ft_colorcylinder(t_pix *pix, t_cylinder *cy);
void				ft_back_trace(t_pix *pix);
void				ft_sphere_normal(double *c, double *o, double *v, double t);
void				ft_trnormal(double *a, double *b, double *c);
void				ft_cy_normal(t_pix *pix, t_cylinder *cy);
int					ft_ob_sp(double t, double *v, double *o);
int					ft_ob_pl(double t, double *v, double *o);
int					ft_ob_sq(double t, double *v, double *o);
int					ft_ob_cy(double t, double *v, double *o);
int					ft_ob_tr(double t, double *v, double *o);
int					ft_sp_obstruction(double t, double *v, double *o,
									t_sphere *sp);
int					ft_pl_obstruction(double t, double *v, double *o,
									t_plane *pl);
int					ft_sq_obstruction(double t, double *v, double *o,
									t_square *sq);
int					ft_cy_obstruction(double t, double *v, double *o,
									t_cylinder *cy);
int					ft_tr_obstruction(double t, double *v, double *o,
									t_triangle *tr);
void				ft_normal_plane(double *v, t_pix *pix);
int					ft_sq_to_pl_obst(double *v, double *o, double *t,
									t_square *pl);
double				ft_cy_to_pl_obst(double *v, double *o, double *c,
									double *n);
int					ft_tr_to_pl_obst(double *v, double *o, double *t,
									t_triangle *tr);
double				ft_caps_obst(double *vec, double *o, t_cylinder *cy);

/*
** destroying
*/
void				ft_free_scene(void);

/*
** testing
*/

void				test_scene(void);

#endif
