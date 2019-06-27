/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:05:11 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 15:19:51 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_camera(t_fdf *fdf)
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

void		init_fdf(t_fdf *fdf)
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
    fdf->col->r = 0;
	fdf->col->g = 0;
	fdf->col->b = 0;
    fdf->col->point_colour = NULL;
	fdf->col->pos_start = 0;
	fdf->col->pos_fin = 0;
}

void	free_fdf(t_fdf *fdf)
{
	free(fdf->cam);
	free(fdf->col);
	free(fdf->map);
	free(fdf->mlx);
	free(fdf->win);
	free(fdf);
}