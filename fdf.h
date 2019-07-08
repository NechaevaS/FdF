/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/08 11:45:03 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "key_codes.h"
# include <math.h>
# ifdef __APPLE__
#  include "minilibx_macos/mlx.h"
# else
#  include "minilibx/mlx.h"
# endif

# define WIN_W	1200
# define WIN_H	1200
# define ELEM(m, row, col) ((m)->data[(row) * ((m)->n_col) + (col)])

typedef struct
{
	double		x;
	double		y;
	double		a;
	double		b;
	double		dx;
	double		dy;
	int			dir;
}				t_line;

typedef struct
{
	int			i;
	int			j;
	int			k;
}				t_help;

typedef struct
{
	int			w;
	int			h;
}				t_size;

typedef struct
{
	double		r_st;
	double		g_st;
	double		b_st;
	double		r_f;
	double		g_f;
	double		b_f;
	char		**point_colour;
}				t_colour;

typedef struct
{
	int			pos_start;
	int			pos_fin;
	int			steps;
	int			curr_st;

}				t_blend;

typedef struct
{
	int			x;
	int			y;
	int			z;
	double		x_zoom;
	double		y_zoom;
	double		z_zoom;
	double		x_rot;
	double		y_rot;
	double		z_rot;
}				t_camera;

typedef struct
{
	int			n_col;
	int			n_row;
	double		*data;
}				t_matrix;

typedef struct	s_fdf
{
	t_matrix	*points;
	t_matrix	*draw_points;
	t_camera	*cam;
	t_colour	*col;
	t_size		*map;
	void		*mlx;
	void		*win;
}				t_fdf;

t_matrix		*read_file(t_fdf *fdf, const int fd);
void			draw_all(t_fdf *fdf);
t_matrix		*mtrx_mltpl(t_matrix *a, t_matrix *b);
void			mtrx_mltpl_acc(t_matrix *a, t_matrix *b);
t_matrix		*init_matrix(int row, int col);
void			free_matrix(t_matrix *m);
void			uni_matrix(t_matrix *u);
void			m_scale(t_matrix *t, t_fdf *fdf);
void			m_rotate_z(t_matrix *t, double a);
void			m_rotate_y(t_matrix *t, double a);
void			m_rotate_x(t_matrix *t, double a);
void			m_move(t_matrix *t, double dx, double dy, double dz);
void			m_project(t_matrix *t);
void			create_view(t_fdf *fdf);
int				colour_blend(t_fdf *fdf, t_blend *bl);
void			control_move(t_fdf *fdf, int keycode);
void			control_zoom(t_fdf *fdf, int keycode);
void			control_rotate(t_fdf *fdf, int keycode);
void			control_flat(t_fdf *fdf, int keycode);
void			control_view(t_fdf *fdf, int keycode);
int				key_controls(int keycode, t_fdf *fdf);
void			fill_camera(t_fdf *fdf);
void			print_usage(t_fdf *fdf);
void			init_fdf(t_fdf *fdf);
void			free_fdf(t_fdf *fdf);
void			all_controls(t_fdf *fdf);
void			change_colour(t_fdf *fdf, char *str);
int				ft_error(char *s);

#endif
