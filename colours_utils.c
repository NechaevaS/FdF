/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:36:18 by snechaev          #+#    #+#             */
/*   Updated: 2019/06/26 13:44:48 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

double		colours_st(t_fdf *fdf, int n)
{
	char	tmp[3];
	double	col;

	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_start][n], 2);
	col = ft_atoi_base(tmp,16);
	return (col);
}

double		colours_fin(t_fdf *fdf, int n)
{
	char	tmp[3];
	double	col;

	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_fin][n], 2);
	col = ft_atoi_base(tmp,16);
	return (col);
}

int		colour_blend(t_fdf *fdf, int steps, int curr_st)
{
	unsigned int	my_colour;
	double		r_st;
	double		g_st;
	double		b_st;
	double		r_f;
	double		g_f;
	double		b_f;

	r_st = colours_st(fdf, 0);
	g_st = colours_st(fdf, 2);
	b_st = colours_st(fdf, 4);
	r_f = colours_fin(fdf, 0);
	g_f = colours_fin(fdf, 2);
	b_f = colours_fin(fdf, 4);
	if (r_st == r_f && g_st == g_f && b_st == b_f)
		my_colour = (r_st * 65536) + (g_st * 256) + b_st;
	else
	{
		fdf->col->r = r_st + (((r_f - r_st) * curr_st) / steps);
		fdf->col->g = g_st + (((g_f - g_st) * curr_st) / steps);
		fdf->col->b = b_st + (((b_f - b_st) * curr_st) / steps);
		my_colour = (fdf->col->r * 65536) + (fdf->col->g * 256) + fdf->col->b;
	}
	return (my_colour);
}

void	change_colour(t_fdf *fdf, char *str)
{
	int i;

	i = 0;
	while(i < fdf->map->h * fdf->map->w)
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
			exit (1);
		}
		i++;
	}
}