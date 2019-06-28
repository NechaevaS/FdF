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

double		colours_st(t_fdf *fdf, int n)
{
	char	tmp[3];
	double	col;

	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_start][n], 2);
	col = ft_atoi_base(tmp, 16);
	return (col);
}

double		colours_fin(t_fdf *fdf, int n)
{
	char	tmp[3];
	double	col;

	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_fin][n], 2);
	col = ft_atoi_base(tmp, 16);
	return (col);
}

int			colour_blend(t_fdf *fdf, int steps, int curr_st)
{
	int		c;
	double	r;
	double	g;
	double	b;

	fdf->col->r_st = colours_st(fdf, 0);
	fdf->col->g_st = colours_st(fdf, 2);
	fdf->col->b_st = colours_st(fdf, 4);
	fdf->col->r_f = colours_fin(fdf, 0);
	fdf->col->g_f = colours_fin(fdf, 2);
	fdf->col->b_f = colours_fin(fdf, 4);
	if (fdf->col->r_st == fdf->col->r_f && fdf->col->g_st == fdf->col->g_f
		&& fdf->col->b_st == fdf->col->b_f)
		c = (fdf->col->r_st * 65536) + (fdf->col->g_st * 256) + fdf->col->b_st;
	else
	{
		r = fdf->col->r_st + (((fdf->col->r_f - fdf->col->r_st) *
			curr_st) / steps);
		g = fdf->col->g_st + (((fdf->col->g_f - fdf->col->g_st) *
			curr_st) / steps);
		b = fdf->col->b_st + (((fdf->col->b_f - fdf->col->b_st) *
			curr_st) / steps);
		c = (r * 65536) + (g * 256) + b;
	}
	return (c);
}

void		change_colour(t_fdf *fdf, char *str)
{
	int		i;

	i = 0;
	while (i < fdf->map->h * fdf->map->w)
	{
		if (strcmp(str, "green") == 0)
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
