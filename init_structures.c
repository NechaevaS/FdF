/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:05:11 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/03 17:52:35 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fill_camera(t_fdf *fdf)
{
	fdf->cam->x_zoom = 20;
	fdf->cam->y_zoom = 20;
	fdf->cam->z_zoom = 20;
	fdf->cam->x_rot = 35.26 + 180;
	fdf->cam->y_rot = -45;
	fdf->cam->z_rot = 0;
	fdf->cam->z = 0;
	fdf->cam->x = 0;
	fdf->cam->y = 0;
}

void			init_fdf(t_fdf *fdf)
{
	t_size		*map;
	t_colour	*col;
	t_camera	*cam;

	cam = (t_camera *)ft_memalloc(sizeof(t_camera));
	map = (t_size *)malloc(sizeof(t_size));
	col = (t_colour *)malloc(sizeof(t_colour));
	fdf->map = map;
	fdf->col = col;
	fdf->cam = cam;
	fdf->map->h = 0;
	fdf->map->w = 0;
	fdf->col->r_st = 0;
	fdf->col->g_st = 0;
	fdf->col->b_st = 0;
	fdf->col->r_f = 0;
	fdf->col->g_f = 0;
	fdf->col->b_f = 0;
}

void			free_fdf(t_fdf *fdf)
{
	// int			i;

	// i = 0;
	// while(i < fdf->map->h * fdf->map->w)
	// 	{
	// 		free(fdf->col->point_colour[i]);
	// 		i++;
	// 	}
	free(fdf->col->point_colour);
	free(fdf->col);
	free(fdf->cam);
	free(fdf->map);
	free_matrix(fdf->points);
	free_matrix(fdf->draw_points);
}
