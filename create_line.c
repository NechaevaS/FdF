/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/23 16:32:46 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
colour	colour_blend()
{
	colour		start;
	colour		fin;
	colour		my_colour;
	const int	steps = 100;
	int			i;

	start.r = 255;
	start.g = 0;
	start.b = 0;
	fin.r = 0;
	fin.g = 255;
	fin.b = 0;

	while (i <= steps)
	{
		my_colour.r   = start.r   + (((fin.r   - start.r)   * i) / steps);
		my_colour.g  = start.g + (((fin.g - start.g) * i) / steps);
		my_colour.b   = start.b  + (((fin.b  - start.b)  * i) / steps);
		i++;
	}
	return(my_colour);
}

void	create_line(void *mlx_ptr, void *mlx_win, t_point pos)
{
	int	x_st = 100;
	int	y_st = 100;
	int	x_fin = 400;
	int	y_fin = 400;
	int	color = 0xFFFFFF;
	while (y_st <= y_fin & x_st <= x_fin)
	{

		mlx_pixel_put(mlx_ptr, mlx_win, x_st, y_st, color_blend());
		x_st++;
		y_st++;
		color = color - 20;
	}
}
