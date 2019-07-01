/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:36:18 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/27 15:54:23 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

double		colours_component(t_fdf *fdf, int id, int n)
{
	char	tmp[3];
	double	col;

	ft_strncpy(tmp, &fdf->col->point_colour[id][n], 2);
	col = ft_atoi_base(tmp, 16);
	return (col);
}

int			colour_blend(t_fdf *fdf, t_blend *bl)
{
	int		c;
	double	r;
	double	g;
	double	b;

	fdf->col->r_st = colours_component(fdf, bl->pos_start, 0);
	fdf->col->g_st = colours_component(fdf, bl->pos_start, 2);
	fdf->col->b_st = colours_component(fdf, bl->pos_start, 4);
	fdf->col->r_f = colours_component(fdf, bl->pos_fin, 0);
	fdf->col->g_f = colours_component(fdf,  bl->pos_fin, 2);
	fdf->col->b_f = colours_component(fdf,  bl->pos_fin, 4);
	if (fdf->col->r_st == fdf->col->r_f && fdf->col->g_st == fdf->col->g_f
		&& fdf->col->b_st == fdf->col->b_f)
		c = (fdf->col->r_st * 65536) + (fdf->col->g_st * 256) + fdf->col->b_st;
	else
	{
		r = fdf->col->r_st + (((fdf->col->r_f - fdf->col->r_st) *
			bl->curr_st) / bl->steps);
		g = fdf->col->g_st + (((fdf->col->g_f - fdf->col->g_st) *
			bl->curr_st) / bl->steps);
		b = fdf->col->b_st + (((fdf->col->b_f - fdf->col->b_st) *
			bl->curr_st) / bl->steps);
		c = (r * 65536) + (g * 256) + b;
	}
	return (c);
}

void		gradient(t_fdf *fdf)
{

	int i;
	char *grad[60];
	t_blend  bl;

	i = 0;
	bl.pos_start = 0;
	bl.pos_fin = 50;
	bl.steps = 50;
	bl.curr_st = i;
	fdf->col->point_colour[0] = "00FF00";
	fdf->col->point_colour[50] = "FFFFFF";
    while(i < 50)
	{
		grad[i] = ft_itoa_base (colour_blend(fdf, &bl), 16);
		printf("%s\n", grad[i]);
		i++;
	}

	i = 0;
	while (i < fdf->map->h * fdf->map->w)
	{
		bl.curr_st = ELEM(fdf->points, i, 1);
		if (bl.curr_st <= 0)
			fdf->col->point_colour[i] = "00FF00";
		else if (bl.curr_st >= 50)
			fdf->col->point_colour[i] = "FFFFFF";
		else
		{
			fdf->col->point_colour[i] = grad[bl.steps - bl.curr_st];
		}
		i++;
	}
}

void		change_colour(t_fdf *fdf, char *str)
{
	int		i;

	i = 0;
	while (i < fdf->map->h * fdf->map->w)
	{
		if (strcmp(str, "gradient") == 0)
			gradient(fdf);
		else if (strcmp(str, "green") == 0)
			fdf->col->point_colour[i] = "00FF00";
		else if (strcmp(str, "red") == 0)
			fdf->col->point_colour[i] = "FF0000";
		else if (strcmp(str, "blue") == 0)
			fdf->col->point_colour[i] = "0000FF";
		else
		{
			ft_error("Please choose one : red, green, blue");
			exit(1);
		}
		i++;
	}
}
