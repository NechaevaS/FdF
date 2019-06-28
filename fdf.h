/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 16:37:09 by snechaev         ###   ########.fr       */
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
	int			w;
	int			h;
}				t_size;

typedef struct
{
	int			n_col;
	int			n_row;
	double		*data;
}				t_matrix;

typedef struct
{
	double		r_st;
	double		g_st;
	double		b_st;
	double		r_f;
	double		g_f;
	double		b_f;
	char		**point_colour;
	int			pos_start;
	int			pos_fin;
}				t_colour;

typedef struct
{
	int			x;
	int			y;
	int			z;
	double		flat;
	double		x_rot;
	double		y_rot;
	double		z_rot;
	int			zoom;
}				t_camera;

typedef struct
{
	t_matrix	*points;
	t_matrix	*drow_points;
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
void			m_scale(t_matrix *t, double zoom);
void			m_rotate_z(t_matrix *t, double a);
void			m_rotate_y(t_matrix *t, double a);
void			m_rotate_x(t_matrix *t, double a);
void			m_move(t_matrix *t, double dx, double dy, double dz);
void			m_project(t_matrix *t);
t_matrix		*create_view(t_fdf *fdf);
int				colour_blend(t_fdf *fdf, int steps, int curr_st);
int				key_controls(int keycode, t_fdf *fdf);
void			fill_camera(t_fdf *fdf);
void			print_usage(t_fdf *fdf);
void			init_fdf(t_fdf *fdf);
void			free_fdf(t_fdf *fdf);
void			all_controls(t_fdf *fdf);
void			change_colour(t_fdf *fdf, char *str);
int				ft_error(char *s);

#endif
