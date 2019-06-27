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

int		colour_blend(t_fdf *fdf, int steps, int curr_st)
{
	unsigned int	my_colour;
	double		r_st;
	double		g_st;
	double		b_st;
	double		r_f;
	double		g_f;
	double		b_f;
	char	tmp[3];
	int		i = 0;

	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_start][i], 2);
	r_st = ft_atoi_base(tmp,16);
	i = i + 2;
	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_start][i], 2);
	g_st = ft_atoi_base(tmp,16);
	i = i + 2;
	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_start][i], 2);
	b_st = ft_atoi_base(tmp,16);
	i = 0;
	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_fin][i], 2);
	r_f = ft_atoi_base(tmp,16);
	i = i + 2;
	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_fin][i], 2);
	g_f = ft_atoi_base(tmp,16);
	i = i + 2;
	ft_strncpy(tmp, &fdf->col->point_colour[fdf->col->pos_fin][i], 2);
	b_f = ft_atoi_base(tmp,16);
	if (r_st == r_f && g_st == g_f && b_st == b_f)
	{
		my_colour = (r_st * 65536) + (g_st * 256) + b_st;
	}
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
		i++;
	}
}