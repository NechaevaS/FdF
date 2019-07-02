/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/07/01 11:50:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_t_line(t_fdf *fdf, int start, int fin, t_line *line)
{
	line->x = ELEM(fdf->draw_points, start, 0);
	line->y = ELEM(fdf->draw_points, start, 1);
	line->dx = ELEM(fdf->draw_points, fin, 0) - line->x;
	line->dy = ELEM(fdf->draw_points, fin, 1) - line->y;
}

void		create_hor_line(t_fdf *fdf, int start, int fin)
{
	t_line	line;
	double	f;
	t_blend	bl;

	bl.pos_start = start;
	bl.pos_fin = fin;
	fill_t_line(fdf, start, fin, &line);
	bl.steps = line.dx;
	line.a = (line.dy / line.dx);
	line.b = line.y - line.a * line.x;
	line.dir = (line.dx < 0) ? -1 : 1;
	line.x = (line.x >= 0) ? line.x : 0;
	f = ELEM(fdf->draw_points, fin, 0);
	f = (f >= 0) ? f : 0;
	while (line.x * line.dir < f * line.dir)
	{
		line.y = line.a * line.x + line.b;
		if (line.y >= 0 && line.x >= 0 && line.x < WIN_W)
		{
			bl.curr_st = line.x - ELEM(fdf->draw_points, start, 0);
			mlx_pixel_put(fdf->mlx, fdf->win, line.x, line.y,
				colour_blend(fdf, &bl));
		}
		line.x += line.dir;
	}
}

void		create_vert_line(t_fdf *fdf, int start, int fin)
{
	t_line	line;
	double	f;
	t_blend	bl;

	bl.pos_start = start;
	bl.pos_fin = fin;
	fill_t_line(fdf, start, fin, &line);
	bl.steps = line.dy;
	line.a = (line.dx / line.dy);
	line.b = line.x - line.a * line.y;
	line.dir = (line.dy < 0) ? -1 : 1;
	line.y = (line.y >= 0) ? line.y : 0;
	f = ELEM(fdf->draw_points, fin, 1);
	f = (f >= 0) ? f : 0;
	while (line.y * line.dir < f * line.dir && line.y >= 0 && line.y <= WIN_H)
	{
		line.x = line.a * line.y + line.b;
		if (line.x >= 0 && line.y >= 0 && line.y < WIN_H)
		{
			bl.curr_st = line.y - ELEM(fdf->draw_points, start, 1);
			mlx_pixel_put(fdf->mlx, fdf->win, line.x, line.y,
				colour_blend(fdf, &bl));
		}
		line.y += line.dir;
	}
}

void		create_line(t_fdf *fdf, int start, int fin)
{
	double	dx;
	double	dy;
	double	slope;

	dx = ELEM(fdf->draw_points, fin, 0) - ELEM(fdf->draw_points, start, 0);
	dy = ELEM(fdf->draw_points, fin, 1) - ELEM(fdf->draw_points, start, 1);
	if (dx == 0)
	{
		create_vert_line(fdf, start, fin);
		return ;
	}
	slope = dy / dx;
	slope = (slope < 0) ? -slope : slope;
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
				create_line(fdf, row, row + 1);
			if (j + 1 < fdf->map->h)
				create_line(fdf, row, row + fdf->map->w);
			i++;
		}
		j++;
	}
}
