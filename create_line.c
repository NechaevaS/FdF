/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snechaev <snechaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:57:34 by snechaev          #+#    #+#             */
/*   Updated: 2019/05/23 13:42:27 by snechaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_line(void *mlx_ptr, void *mlx_win)
{
	int	x_st = 100;
	int	y_st = 100;
	int	x_fin = 400;
	int	y_fin = 400;
	int	color = 0xFFFFFF;
	while (y_st <= y_fin & x_st <= x_fin)
	{

		mlx_pixel_put(mlx_ptr, mlx_win, x_st, y_st, color);
		x_st++;
		y_st++;
		color = color - 20;
	}
}
