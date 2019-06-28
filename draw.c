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

void		create_hor_line(t_fdf *fdf, int start, int fin)
{
	t_line	line;
	int		dir;
	double	f;
	t_blend	bl;

	bl.pos_start = start;
	bl.pos_fin = fin;
	line.x = ELEM(fdf->draw_points, start, 0);
	line.y = ELEM(fdf->draw_points, start, 1);
	line.dx = ELEM(fdf->draw_points, fin, 0) - line.x;
	line.dy = ELEM(fdf->draw_points, fin, 1) - line.y;
	bl.steps = line.dx;
	line.a = (line.dy / line.dx);
	line.b = line.y - line.a * line.x;
	dir = (line.dx < 0)?-1:1;
	line.x = (line.x >= 0)? line.x: 0;
	f = ELEM(fdf->draw_points, fin, 0);
	f = (f >= 0) ? f: 0;
	while (line.x * dir < f * dir)
	{
		line.y = line.a * line.x + line.b;
		if (line.y >= 0 && line.x >= 0 && line.x <  WIN_W)
		{
			bl.curr_st = line.x - ELEM(fdf->draw_points, start, 0);
			mlx_pixel_put(fdf->mlx, fdf->win, line.x, line.y, colour_blend(fdf, &bl));
		}
		line.x += dir;
	}
}

void		create_vert_line(t_fdf *fdf, int start, int fin)
{

	t_line	line;
	int		dir;
	double	f;
	t_blend	bl;

	bl.pos_start = start;
	bl.pos_fin = fin;
	line.x = ELEM(fdf->draw_points, start, 0);
	line.y = ELEM(fdf->draw_points, start, 1);
	line.dx = ELEM(fdf->draw_points, fin, 0) - line.x;
	line.dy = ELEM(fdf->draw_points, fin, 1) - line.y;
	bl.steps = line.dy;
	line.a = (line.dx / line.dy);
	line.b = line.x - line.a * line.y;
	dir = (line.dy < 0)? -1:1;
	line.y = (line.y >= 0)? line.y: 0;
	f = ELEM(fdf->draw_points, fin, 1);
	f = (f >= 0) ? f: 0;
	while (line.y * dir < f * dir && line.y >= 0 && line.y <=  WIN_H)
	{
		line.x = line.a * line.y + line.b;
		if (line.x >= 0 && line.y >= 0 && line.y <  WIN_H)
		{
			bl.curr_st = line.y - ELEM(fdf->draw_points, start, 1);
			mlx_pixel_put(fdf->mlx, fdf->win, line.x, line.y, colour_blend(fdf, &bl));
		}
		line.y+= dir;
	}
}

void	create_line(t_fdf *fdf, int start, int fin)
{
	double dx;
	double dy;
	double slope;

	dx = ELEM(fdf->draw_points, fin, 0) - ELEM(fdf->draw_points, start, 0);
	dy = ELEM(fdf->draw_points, fin, 1) - ELEM(fdf->draw_points, start, 1);
	if (dx == 0)
	{
		create_vert_line(fdf, start, fin);
		return;
	}
	slope = dy / dx;
	slope = (slope < 0)? -slope: slope;
	if (slope <= 1)
		create_hor_line(fdf, start, fin);
	else
		create_vert_line(fdf, start, fin);
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
			if (i + 1 < fdf->map->w)
			{
				create_line(fdf,  row, row + 1);
			}
			if (j + 1 < fdf->map->h)
			{

				create_line(fdf, row, row + fdf->map->w);
			}
			i++;
		}
		j++;
	}
}
// void		draw_all(t_fdf *fdf)
// {
// 	int		i;
// 	int		j;
// 	int		row;

// 	j = 0;
// 	while (j < fdf->map->h)
// 	{
// 		i = 0;
// 		while (i < fdf->map->w)
// 		{
// 			row = fdf->map->w * j + i;
// 			fdf->col->pos_start = row;
// 			if (i + 1 < fdf->map->w)
// 			{
// 				fdf->col->pos_fin = row + 1;
// 				create_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + 1, 0));
// 			}
// 			if (j + 1 < fdf->map->h)
// 			{
// 				fdf->col->pos_fin = row + fdf->map->w;
// 				create_line(fdf, &ELEM(fdf->drow_points, row, 0), &ELEM(fdf->drow_points, row + fdf->map->w, 0));
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }
