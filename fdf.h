/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:23:09 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/23 16:32:39 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct
{
	int			w;
	int			h;
}				t_size;

typedef struct
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					colour;


t_list			*to_list(t_list *res,char *str, int count);
void			count_size_line(t_list *res, t_size *map);
void			convert_to_int(t_list *res, int **int_arr, t_size *map);
int				**read_file(t_size *map, const int fd);
void			print_map(t_size *map, int **int_arr);
void			print_row(t_size *map, int **int_arr, int j);
void			create_line(void *mlx_ptr, void *mlx_win);

#endif
