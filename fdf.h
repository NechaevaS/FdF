/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/30 16:16:33 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH			512
# define WIN_HEIGHT			512
# define SCALE				100
# define OFFSET				100

typedef struct
{
	int			w;
	int			h;
}				t_size;

typedef struct
{
	int			posx;
	int			posy;
	int			z;
	int			x;
	int			y;
	int			scale;
}				t_point;

typedef struct
{
	int		red;
	int		green;
	int		blue;
}				t_color;


t_list			*to_list(t_list *res,char *str, int count);
void			count_size_line(t_list *res, t_size *map);
void			convert_to_int(t_list *res, int **int_arr, t_size *map);
int				**read_file(t_size *map, const int fd);
void			print_map(t_size *map, int **int_arr);
void			print_row(t_size *map, int **int_arr, int j);
void			create_lines(void *mlx_ptr, void *mlx_win, t_point **net, t_size * map);
t_point			**to_coord(int **arr, t_size *map);

#endif
