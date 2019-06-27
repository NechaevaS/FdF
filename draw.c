/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 14:41:28 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_gor_line(t_fdf *fdf, double *start, double *fin)
{
	double	x;
	double	y;
	double	a;
	double	b;
	double	dx;
	double	dy;
	int		dir;
	double	f;

	x = start[0];
	y = start[1];
	dx = fin[0] - x;
	dy = fin[1] - y;
	a = dy / dx;
	b = y - a * x;
	dir = (dx < 0)?-1:1;
	x = (x >= 0)? x: 0;
	f = (fin[0] >= 0) ? fin[0]: 0;
	while (x * dir < f * dir)
	{
		y = a * x + b;
		if (y >= 0 && x >= 0 && x <  WIN_W)
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, colour_blend(fdf, dx, (x - start[0])));
		x += dir;
	}
}

void		create_vert_line(t_fdf *fdf, double *start, double *fin)
{
	double	x;
	double	y;
	double	a;
	double	b;
	double	dx;
	double	dy;
	int		dir;
	double	f;

	x = start[0];
	y = start[1];
	dx = fin[0] - x;
	dy = fin[1] - y;
	a = dx / dy;
	b = x - a * y;
	dir = (dy < 0)? -1:1;
	y = (y >= 0)? y: 0;
	x = (x > WIN_H)? WIN_H: y;
	f = (fin[1] >= 0) ? fin[1]: 0;
	while (y * dir < f * dir && y >= 0 && y <=  WIN_H)
	{
		x = a * y + b;
		if (x >= 0 && y >= 0 && y <  WIN_H)
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, colour_blend(fdf, dy, (y - start[1])));
		y+= dir;
	}
}

void		draw_all(t_fdf *fdf)
{
	int		i;
	int		j;
	int		row;

	j = 0;
	while (j < fdf->map->h)
	{
		i = 0;
		while (i < fdf->map->w)
		{
			row = fdf->map->w * j + i;
			fdf->col->pos_start = row;
			if (i + 1 < fdf->map->w)
			{
				fdf->col->pos_fin = row + 1;
				create_gor_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + 1, 0));
				create_vert_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + 1, 0));
			}
			if (j + 1 < fdf->map->h)
			{
				fdf->col->pos_fin = row + fdf->map->w;
				create_gor_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + fdf->map->w, 0));
				create_vert_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + fdf->map->w, 0));
			}
			i++;
		}
		j++;
	}
}
